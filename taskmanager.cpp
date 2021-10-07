/**
 *
 * @brief Implementazione classe TaskManager
 *
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
 
#include "taskmanager.h"

/**
* @brief Definisce il costruttore della classe
*        Imposta i valori di default per i parametri relativi al controllo sulle periodicita'
*
* @param[in] tick : frequenza di controllo scadenza task (millisecondi), parametro opzionale
* @param[in] precision: precisione frequenza di controllo scadenza task (millisecondi), parametro opzionale
*/
TaskManager::TaskManager(qint64 tick, unsigned long precision)
{
    this->tick = tick;        		// imposta frequenza di controllo task (millisecondi)
    this->precision = precision;    // imposta precisione frequenza di controllo task (millisecondi)
    this->isRunning = false;        // controllo sui task non attivo
    this->stopRequest = false;
}

/**
* @brief Modifica il riferimento di uno specifico task o aggiunge un nuovo task
*
* @param[in] name : nome del task
* @param[in] value: puntatore all'oggetto task
*/
void TaskManager::SetTask(QString name, Task* task)
{
    tasks[name] = task;
}

/**
* @brief Restituisce il riferimento a uno specifico task, NULL in caso il task non esiste
*
* @param[in] name : nome del task
*
* @return: puntatore all'oggetto task, NULL se il task non esiste
*/
Task* TaskManager::GetTask(QString name)
{
	if (tasks.contains(name))
		return tasks[name];
	else
		return NULL;
}

/**
* @brief Restituisce iteratore relativo al primo elemento della struttura tasks
*
*/
const QMap<QString,Task*>::iterator TaskManager::FirstTask()
{
    return tasks.begin();
}

/**
* @brief Restituisce iteratore relativo all'ultimo elemento della struttura tasks
*
*/
const QMap<QString,Task*>::iterator TaskManager::LastTask()
{
    return tasks.end();
}

/**
* @brief Disattiva il controllo sui task chiudendo il thread dedicato
*
*/
void TaskManager::Stop()
{
    this->stopRequest = true;         // controllo sui task non attivo
}

/**
* @brief Indica se il controllo sui task e' attivo, ossia se il thread dedicato e' in esecuzione
*
* @return: true se il controllo e' attivo, false se il controllo non e' attivo
*/
bool TaskManager::IsRunning()
{
    return this->isRunning;
}

/**
* @brief Esegue il controllo periodico sui task in un thread separato
*
*/
void TaskManager::run()
{
    QDateTime dt_current = QDateTime::currentDateTime();
    QDateTime dt_previous = dt_current;
    this->isRunning = true;                // controllo sui task attivo
    qDebug() << "Avvio thread task manager";
    while (1)
    {
        dt_current = QDateTime::currentDateTime();
        qint64 msecs = dt_previous.msecsTo(dt_current);
        if (msecs >= this->tick)
        {
            // effettua verifica scadenze sui task configurati
            foreach (const auto& taskname, tasks.keys())
            {
                if (tasks[taskname]->CheckExpiration())
                {
                    tasks[taskname]->Execute();
                }
            }
            dt_previous = dt_current.addMSecs(this->tick - msecs);  /* Compensa l'eccesso di ritardo accumulato dalla funzione msleep nelle varie iterazioni del ciclo.
                                                                       Assegnando semplicemente dt_current a dt_previous si otterrebero ritardi molto più imprecisi */
        }
        QThread::msleep(this->precision);
        if (this->stopRequest)              // identificata richiesta di chiusura thread
        {
            this->stopRequest = false;
            break;                          // conclude il thread uscendo dal ciclo su richiesta del chiamante
        }
    }
    this->isRunning = false;                // controllo sui task inattivo
    qDebug() << "Fine thread task manager";
}
