/**
 *
 * @brief Implementazione classe TaskCheckFile 
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
 
#include "taskcheckfile.h"

/**
* @brief Definisce il costruttore della classe
*        Aggiunge il parametro relativo al percorso del file da verificare e gli assegna un valore di default
* 
*/
TaskCheckFile::TaskCheckFile()
{
    this->SetParameter("Percorso file","C:\\esempio.txt");
    this->timeCounter = 0;
}

/**
* @brief Implementa il metodo astratto che controlla la validita' di uno specifico parametro
*        Qui e' possibile definire il controllo sulla validita' del percorso file inserito e sull'eventuale esistenza del file.
*
* @param[in] name : nome del task
* @param[in] value: puntatore all'oggetto task
*
* @return: true se il parametro risulta valido, false se il parametro non risulta valido
*/
bool TaskCheckFile::ValidateParameter(QString name, QString value)
{
    if (name == "Percorso file")
    {
        QFileInfo check_file(value);
        if (check_file.exists() && check_file.isFile())    // il percorso si riferisce a un file esistente
        {
            return true;
        }
        else
        {
            return false;
        }
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
bool TaskCheckFile::CheckExpiration()
{
    this->timeCounter++;
    if (this->timeCounter == 30)
    {
        this->timeCounter = 0;
        return true;
    }
    return false;
}

/**
* @brief Implementa il metodo astratto che esegue il task verificando la presenza del file definito come parametro
*
*/	
void TaskCheckFile::Execute()
{
    QFileInfo check_file(this->GetParameter("Percorso file"));
    if (!(check_file.exists() && check_file.isFile()))            // file non trovato
    {
        qDebug() << "File:" << qPrintable(this->GetParameter("Percorso file")) << " non trovato";
    }
}
