#include "Ataque.h"
#include "Klostermon.h"

String Ataque::getNombre()
{
    String nombreAtaque = nombre;
    return nombreAtaque;
}

void Ataque::setName(String name)
{
    std::string namestd = name.toAnsiString();
    strcpy(nombre, namestd.c_str());
}

int Ataque::getDanio()
{
    int danio = rand() % (danioMax + 1 - danioMin) + danioMin;
    return danio;
}

void Ataque::setDanioMin(int minDanio)
{
    
    danioMin = minDanio;
}

void Ataque::setDanioMax(int maxDanio)
{
    danioMax = maxDanio;
    
}


int Ataque::getDanioPropio()
{
    return danioPropio;
}

void Ataque::setDanioPropio(int selfDamage)
{
    danioPropio = selfDamage;
}

int Ataque::getModVidaTotal()
{
    return modVidaTotal;
}

void Ataque::setModVidaTotal(int newmodvida)
{
    modVidaTotal = newmodvida;
}

int Ataque::getModVidaTotalEnemiga()
{
    return modVidaTotalEnemiga;
}

void Ataque::setModVidaTotalEnemiga(int newModVidaEnemiga)
{
    modVidaTotalEnemiga = newModVidaEnemiga;
}

int Ataque::getEfectividadAtaque()
{
    return efectividadPropia;
}

void Ataque::setEfectividadAtaque(int efecti)
{
    efectividadPropia = efecti;
}

int Ataque::getEfectividadEnemiga()
{
    return efectividadEnemiga;
}

void Ataque::setEfectividadEnemiga(int efecEnemiga)
{
    efectividadEnemiga = efecEnemiga;
}

int Ataque::getVelocidadAtaque()
{
    return velocidad;
}

void Ataque::setVelocidadAtaque(int speed)
{
    velocidad = speed;
}

int Ataque::getVelocidadEnemiga()
{
    return velocidadEnemiga;
}

void Ataque::setVelocidadEnemiga(int speedEnemiga)
{
    velocidadEnemiga = speedEnemiga;
}

float Ataque::getMultPropio()
{
    return multDanioPropio;
}

void Ataque::setMultPropio(float mult)
{
    multDanioPropio = mult;
}

float Ataque::getMultEnemigo()
{
    return multDanioEnemigo;
}

void Ataque::setMultEnemigo(float mult)
{
    multDanioEnemigo = mult;
}

String Ataque::utilizarAtaque(Klostermon& target, Klostermon& atacante)
{
        Ataque* ataqueEfectuado = this;
        int danio_k = ataqueEfectuado->getDanio();
        int danioPropio_k = ataqueEfectuado->getDanioPropio();
        int modDeVida_k = ataqueEfectuado->getModVidaTotal();
        int modDeVidaEnemiga_k = ataqueEfectuado->getModVidaTotalEnemiga();
        int velocidad_k = ataqueEfectuado->getVelocidadAtaque();
        int velocidadEnemiga_k = ataqueEfectuado->getVelocidadEnemiga();
        int efectividad_k = ataqueEfectuado->getEfectividadAtaque();
        int efectividadEnemiga_k = ataqueEfectuado->getEfectividadEnemiga();
        float multPropio_k = ataqueEfectuado->getMultPropio();
        float multEnemigo_k = ataqueEfectuado->getMultEnemigo();

        //Daño
        target.setVida(target.getVida() - int(danio_k * atacante.getMultiplicador()));
        atacante.setVida(atacante.getVida() - danioPropio_k);
        //Vida total
        target.setMaxVida(target.getMaxVida() + int(modDeVidaEnemiga_k * atacante.getMultiplicador()));
        atacante.setMaxVida(atacante.getMaxVida() + int(modDeVida_k * atacante.getMultiplicador()));
        //Velocidad
        target.setVelocidad(target.getVelocidad() + velocidadEnemiga_k);//Aca se recibe un valor negativo(si es que se baja)
        atacante.setVelocidad(atacante.getVelocidad() + velocidad_k);//Aca se suele recibir positivo
        //Efectividad
        target.setEfectividad(target.getEfectividad() + efectividadEnemiga_k);//Se espera un valor negativo
        atacante.setEfectividad(atacante.getEfectividad() + efectividad_k); //Se espera positivo
        //Multiplicador de daño
        target.setMultiplicador(target.getMultiplicador() + multEnemigo_k);//Se espera negativo
        atacante.setMultiplicador(atacante.getMultiplicador() + multPropio_k);//se espera valor positivo

        std::cerr << "ModVidaEnemiga: " << modDeVidaEnemiga_k<<std::endl;
        std::cerr << "Mod vida propia: " << modDeVida_k << std::endl;

        String stringMostrado =
            atacante.getNameKlostermon() + " utilizo " + ataqueEfectuado->getNombre() + "!";
       
        if (danioPropio_k != 0)
        {
            if (danioPropio_k < 0)
            {
                stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                    + " recupero " + std::to_string(danioPropio_k * -1) + " de vida!";
            }
            else
            {
                stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                    + " se autoinfligido " + std::to_string(danioPropio_k) + " de vida!";
            }
        }
        if (danio_k != 0)
        {
            stringMostrado = stringMostrado + "/El " + target.getNameKlostermon()
            +" pierde " + std::to_string(int(danio_k * atacante.getMultiplicador())) + " de vida!";
        }
        if (modDeVidaEnemiga_k < 0)
        {
            stringMostrado = stringMostrado + "/" + target.getNameKlostermon()
                + " bajo " + std::to_string(int(modDeVidaEnemiga_k * atacante.getMultiplicador())) + " de su vida total!";
        }
        if (modDeVida_k > 0)
        {
            stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                + " subio " + std::to_string(int(modDeVida_k * atacante.getMultiplicador())) + " de su vida total!";
        }
        if (velocidadEnemiga_k < 0)
        {
            stringMostrado = stringMostrado + "/" + target.getNameKlostermon()
                + " ahora es mas lento!";
        }
        if (velocidad_k > 0)
        {
            stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                + " ahora es mas rapido!";
        }
        if (efectividadEnemiga_k < 0)
        {
            stringMostrado = stringMostrado + "/" + target.getNameKlostermon()
                + " ahora es menos efectivo!";
        }
        if (efectividad_k > 0)
        {
            stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                + " ahora es mas efectivo!";
        }
        if (multEnemigo_k < 0)
        {
            stringMostrado = stringMostrado + "/" + target.getNameKlostermon()
                + " ahora hace un " + std::to_string(int((multEnemigo_k * -1) * 100)) + "% menos de daño!";
        }
        if (multPropio_k > 0)
        {
            stringMostrado = stringMostrado + "/" + atacante.getNameKlostermon()
                + " ahora hace un " + std::to_string(int(multPropio_k * 100)) + "% mas de daño!";
        }
        return stringMostrado;
    
}

String Ataque::fallarAtaque(Klostermon atacante)
{
    Ataque* ataqueEfectuado= this;
    String stringMostrado =
        atacante.getNameKlostermon() + " utilizo " + ataqueEfectuado->getNombre() + "!/"
        + "Pero fallo!";
    //delete ataqueEfectuado;
    return stringMostrado;
}
