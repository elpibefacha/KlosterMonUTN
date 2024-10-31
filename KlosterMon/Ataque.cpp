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
    int efectividad = atacante.getEfectividad();
    int random = rand() % 101;
    if (random < efectividad)//Si random es menor que efectividad significa que esta dentro del rango, el ataque se efectua
    {
        int danio_k = ataqueEfectuado->getDanio();
        int danioPropio_k = ataqueEfectuado->getDanioPropio();
        int velocidad_k = ataqueEfectuado->getVelocidadAtaque();
        int velocidadEnemiga_k = ataqueEfectuado->getVelocidadEnemiga();
        int efectividad_k = ataqueEfectuado->getEfectividadAtaque();
        int efectividadEnemiga_k = ataqueEfectuado->getEfectividadEnemiga();
        float multPropio_k = ataqueEfectuado->getMultPropio();
        float multEnemigo_k = ataqueEfectuado->getMultEnemigo();

        std::cerr << danio_k << std::endl;
        std::cerr << danioPropio_k << std::endl;
        std::cerr << velocidad_k << std::endl;
        std::cerr << velocidadEnemiga_k << std::endl;
        std::cerr << efectividad_k << std::endl;
        std::cerr << efectividadEnemiga_k << std::endl;
        std::cerr << multPropio_k << std::endl;
        std::cerr << multEnemigo_k << std::endl;

        //Daño
        target.setVida(target.getVida() - int(danio_k * atacante.getMultiplicador()));
        atacante.setVida(atacante.getVida() - danioPropio_k);
        //Velocidad
        target.setVelocidad(target.getVelocidad() + velocidadEnemiga_k);//Aca se recibe un valor negativo(si es que se baja)
        atacante.setVelocidad(atacante.getVelocidad() + velocidad_k);//Aca se suele recibir positivo
        //Efectividad
        target.setEfectividad(target.getEfectividad() + efectividadEnemiga_k);//Se espera un valor negativo
        atacante.setEfectividad(atacante.getEfectividad() + efectividad_k); //Se espera positivo
        //Multiplicador de daño
        target.setMultiplicador(target.getMultiplicador() + multEnemigo_k);//Se espera negativo
        atacante.setMultiplicador(atacante.getMultiplicador() + multPropio_k);//se espera valor positivo

        String stringMostrado =
            atacante.getNameKlostermon() + " utilizo " + ataqueEfectuado->getNombre() + "!";
       
        if (danio_k != 0)
        {
            stringMostrado = stringMostrado + "/El " + target.getNameKlostermon()
            +" pierde " + std::to_string(int(danio_k * atacante.getMultiplicador())) + " de vida!";
        }if (danioPropio_k != 0)
        {
            if (danioPropio < 0)
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
            std::cerr << "multaaa: " + std::to_string(atacante.getMultiplicador()) << " " << std::to_string(multPropio_k) << std::endl;
        }

        return stringMostrado;
    }
    else
    {
        String stringMostrado =
            atacante.getNameKlostermon() + " utilizo " + ataqueEfectuado->getNombre() + "!/"
            + "Pero fallo!";
        return stringMostrado;
    }
}
