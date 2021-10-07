/**
 *
 * @brief Definizione classe TaskManager
 *
 * Questa classe gestisce l'esecuzione periodica dei task configurati utilizzando un thread dedicato.
 * La classe gestisce internamente i riferimenti agli oggetti task da eseguire tramite memorizzazione
 * in formato chiave (nome task) e valore (puntatore a oggetto task).
 * Il controllo sulle periodicita' dei singoli task viene effettuato a frequenza costante e configurabile
 * tramite gli attributi: tick e precision.
 * ATTENZIONE: Nel caso si volesse modificare la frequenza suddetta (default = 1 secondo) sara' necessario
 * modificare anche i metodi CheckExpiration dei task qui configurati ossia: TaskPrint e TaskCheckFile
 * in quanto da essa dipendenti.
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
 
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QThread>
#include <QDateTime>
#include <QDebug>
#include "task.h"

class TaskManager: public QThread
{
private:
    QMap<QString,Task*> tasks;		// memorizza i riferimenti ai task (chiave=nome univoco del task, valore=puntatore a oggetto task)
    qint64 tick;                    // frequenza di controllo scadenza task (millisecondi)
    unsigned long precision;        // precisione frequenza di controllo scadenza task (millisecondi)
    bool stopRequest;               // true se e' stata effettuata una richiesta di chiusura del thread dedicato al controllo dei task
    bool isRunning;                 // true se il thread dedicato al controllo dei task è in esecuzione, false viceversa
public:
    /**
    * @brief Definisce il costruttore della classe
    *
	* @param[in] tick : frequenza di controllo scadenza task (millisecondi), parametro opzionale
	* @param[in] precision: precisione frequenza di controllo scadenza task (millisecondi), parametro opzionale
    */
    TaskManager(qint64 tick = 1000, unsigned long precision = 100);
	
    /**
    * @brief Modifica il riferimento di uno specifico task o aggiunge un nuovo task
    *
    * @param[in] name : nome del task
    * @param[in] value: puntatore all'oggetto task
    */	
    void SetTask(QString, Task*);

    /**
    * @brief Restituisce il riferimento a uno specifico task, NULL in caso il task non esiste
    *
    * @param[in] name : nome del task
	*
    * @return: puntatore all'oggetto task, NULL se il task non esiste
    */
    Task* GetTask(QString);

    /**
    * @brief Restituisce iteratore relativo al primo elemento della struttura tasks
    *
    */
    const QMap<QString,Task*>::iterator FirstTask();

    /**
    * @brief Restituisce iteratore relativo all'ultimo elemento della struttura tasks
    *
    */
    const QMap<QString,Task*>::iterator LastTask();

    /**
    * @brief Disattiva il controllo sui task chiudendo il thread dedicato
    *
    */
    void Stop();

    /**
    * @brief Indica se il controllo sui task e' attivo, ossia se il thread dedicato e' in esecuzione
    *
    * @return: true se il controllo e' attivo, false se il controllo non e' attivo
    */
    bool IsRunning();

    /**
    * @brief Esegue il controllo periodico sui task in un thread separato
    *
    */
    void run();
};

#endif // TASKMANAGER_H
