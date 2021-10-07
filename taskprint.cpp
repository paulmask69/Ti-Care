/**
 *
 * @brief Implementazione classe TaskPrint 
 *
 * @note
 *
 * @author Paolo Mascarello
 *
 *
 * @date 04/10/2021 $
 *
 * Contact: paolo@pm23.it
 *
 * Created on: 04/10/2021
 *
 *
 */
 
#include "taskprint.h"

/**
* @brief Definisce il costruttore della classe
*        Aggiunge il parametro relativo al testo da stampare a video e gli assegna un valore di default
* 
*/
TaskPrint::TaskPrint()
{
    this->SetParameter("Testo","Testo di default");
    this->timeCounter = 0;
}

/**
* @brief Implementa il metodo astratto che controlla la validita' di uno specifico parametro
*        Qui e' possibile definire il controllo sulla validita' del testo inserito o lasciare
*        la funzione inalterata per accettare qualsiasi testo.
*
* @param[in] name : nome del parametro
* @param[in] value : valore del parametro
*
* @return: true se il parametro risulta valido, false se il parametro non risulta valido
*/
bool TaskPrint::ValidateParameter(QString name, QString value)
{
    if (name == "Testo")
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
* @brief Implementa il metodo astratto che verifica la scadenza della periodicita' relativa al task
*        Qui e' possibile personalizzare la periodicita' con cui verra' eseguito il task
*/
bool TaskPrint::CheckExpiration()
{
    this->timeCounter++;
    if (this->timeCounter == 10)
    {
        this->timeCounter = 0;
        return true;
    }
    return false;
}

/**
* @brief Implementa il metodo astratto che esegue il task stampando a video il testo definito come parametro
*
*/	
void TaskPrint::Execute()
{
    qDebug() << qPrintable(this->GetParameter("Testo"));
}
