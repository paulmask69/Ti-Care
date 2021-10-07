/**
 *
 * @brief Definizione classe TaskCheckFile 
 *
 * Questa classe implementa i metodi della classe astratta task definendo un task specifico per il controllo 
 * dell'esistenza di un file su disco.
 * Il percorso e il nome del file da controllare vengono forniti come parametro del task.
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
 
#ifndef TASKCHECKFILE_H
#define TASKCHECKFILE_H

#include "task.h"
#include <QFileInfo>
#include <QDebug>

class TaskCheckFile: public Task
{
private:
    int timeCounter;             // conta le chiamate alla funzione CheckExpiration al fine di notificare la scadenza della periodicita' del task
	
public:
    /**
    * @brief Definisce il costruttore della classe
    *
    */
    TaskCheckFile();                      

    /**
    * @brief Implementa il metodo astratto che controlla la validita' di uno specifico parametro
    *
    * @param[in] name : nome del parametro
    * @param[in] value : valore del parametro
    *
    * @return: true se il parametro risulta valido, false se il parametro non risulta valido
    */
    virtual bool ValidateParameter(QString name,QString value);
	
    /**
    * @brief Implementa il metodo astratto che verifica la scadenza della periodicita' relativa al task
    *
    * @return: true in caso di periodicita' scaduta, false in caso di periodicita' non scaduta
    */		
    virtual bool CheckExpiration();
	
    /**
    * @brief Metodo astratto che esegue il task verificando la presenza del file definito come parametro
    *
    */		
    virtual void Execute();
};

#endif // TASKCHECKFILE_H
