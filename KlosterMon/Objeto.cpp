#include "Objeto.h"
#include "CuracionPequeña.h"
#include "CuracionGrande.h"
#include "InyeccionCodigo.h"
#include "EstructuracionCod.h"
#include "Optimizacion.h"
#include "CopyPaste.h"

Objeto* Objeto::cargarObjeto(int idRecibida)
{
    Objeto* objeto;
    switch (idRecibida)
    {
    case 0:
        return nullptr; //Retorna null ya que la id 0 es ningun item
    case 1:
        objeto = new CuracionPequeña();
        return objeto;
    case 2:
        objeto = new CuracionGrande();
        return objeto;
    case 3:
        objeto = new InyeccionCodigo();
        return objeto;
    case 4:
        objeto = new EstructuracionCod();
        return objeto;
    case 5:
        objeto = new Optimizacion();
        return objeto;
    case 6:
        objeto = new CopyPaste();
        return objeto;
    default:
        return nullptr;//Si es una id invalida retorna null
    }
    return nullptr;
}

String Objeto::getNombre()
{
    return nombre_obj;
}
