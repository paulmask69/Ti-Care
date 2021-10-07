/**
 *
 * @brief Implementazione della classe astratta Task
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

#include "task.h"

/**
* @brief Modifica il valore di un parametro esistente o aggiunge un nuovo parametro al task
*
* @param[in] name : nome del parametro
* @param[in] value: valore da assegnare al parametro
*/
void Task::SetParameter(QString name, QString value)
{
     parameters[name] = value;   			// modifica il valore al parametro esistente o aggiunge il nuovo parametro
}

/**
* @brief Restituisce il valore di un parametro del task, stringa vuota nel caso il parametro non esiste
*
* @param[in] name : nome del parametro
*
* @return: valore assegnato al parametro o stringa vuota in caso di parametro inesistente
*/
QString Task::GetParameter(QString name)
{
    if (parameters.contains(name))
        return parameters[name];
    else
        return QString("");
}

/**
* @brief Restituisce iteratore relativo al primo elemento della struttura parameters
*
*/
const QMap<QString,QString>::iterator Task::FirstParameter()
{
    return parameters.begin();
}

/**
* @brief Restituisce iteratore relativo all'ultimo elemento della struttura parameters
*
*/
const QMap<QString,QString>::iterator Task::LastParameter()
{
    return parameters.end();
}
