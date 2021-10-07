/**
 *
 * @brief Definizione classe astratta Task
 *
 * Questa classe definisce l'interfaccia generica a un task e permette di aggiungere nuovi task all'applicativo
 * tramite la creazione di classi derivate e la definizione dei metodi astratti: ValidateParameters, CheckExpiration, Execute
 * La classe gestisce internamente i parametri relativi al task tramite memorizzazione
 * in formato chiave (nome parametro) e valore (valore parametro).
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

#ifndef TASK_H
#define TASK_H

#include <QMap>
#include <QString>

class Task
{
protected:
    QMap<QString,QString> parameters;        	// memorizza i parametri del task (chiave=nome univoco del parametro, valore=valore assegnato al parametro)

public:
    /**
    * @brief Modifica il valore di un parametro esistente o aggiunge un nuovo parametro al task
    *
    * @param[in] name : nome del parametro
    * @param[in] value: valore da assegnare al parametro
    */
    void SetParameter(QString name, QString value);

    /**
    * @brief Restituisce il valore di un parametro del task, stringa vuota nel caso il parametro non esiste
    *
    * @param[in] name : nome del parametro
    *
    * @return: valore assegnato al parametro o stringa vuota in caso di parametro inesistente
    */
    QString GetParameter(QString name);

    /**
    * @brief Restituisce iteratore relativo al primo elemento della struttura parameters
    *
    */
    const QMap<QString,QString>::iterator FirstParameter();

    /**
    * @brief Restituisce iteratore relativo all'ultimo elemento della struttura parameters
    *
    */
    const QMap<QString,QString>::iterator LastParameter();

    /**
    * @brief Metodo astratto che controlla la validita' di uno specifico parametro
    *
    * @param[in] name : nome del parametro
    * @param[in] value : valore del parametro
    *
    * @return: true se il parametro risulta valido, false se il parametro non risulta valido
    */
    virtual bool ValidateParameter(QString name,QString value) = 0;

    /**
    * @brief Metodo astratto che verifica la scadenza della periodicita' relativa al task
    *
    * @return: true in caso di periodicita' scaduta, false in caso di periodicita' non scaduta
    */
    virtual bool CheckExpiration() = 0;

    /**
    * @brief Metodo astratto che esegue il task
    *
    */
    virtual void Execute() = 0;

};


#endif // TASK_H
