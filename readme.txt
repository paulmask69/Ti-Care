DESCRIZIONE E UTILIZZO
----------------------
Questo applicativo gestisce l'esecuzione periodica di specifici task.
L'applicativo fornisce un'unico pannello per l'immissione dei parametri
relativi ai task configurati nel codice.
Il pannello puo' essere chiuso al termine dell'immissione dei parametri
in quanto l'applicativo rimane attivo in background.
Per riaprire il pannello di imissione parametri ci sono 2 modi:
- click su icona computer in system tray
- click tasto destro su icona computer in system tray e selezione voce menu "Imposta parametri"
Per chiudere l'applicativo:
- click tasto destro su icona computer in system tray e selezione voce menu "Esci"


ESTENDIBILITA'
-------------
Ogni task viene definito da un oggetto che eredita dalla classe astratta task
e di cui deve fornire l'implementazione per i metodi virtuali:

- ValidateParameter
- CheckExpiration
- Execute

Al momento sono inclusi nel progetto 2 task di esempio chiamati taskprint e taskcheckfile
la cui definizione e implementazione sono contenute rispettivamente nei moduli omonimi
con estensione .h e .cpp.

Per aggiungere ulteriori task al progetto e' necessario definire le relative classi
come fatto per i task di esempio.
Il metodo Execute permette di personalizzare l'attivita' del task.
Il metodo CheckExpiration permette di personalizzare la periodicita' del task.
Il metodo ValidateParameter permette di personalizzare la validazione dei parametri relativi al task

ESEMPIO:
Si vuole aggiungere al progetto una task che effettua delle azioni ogni lunedi mattina alle ore 10

File taskWeek.h
---------------
class TaskWeek: public Task
{
private:
    .....eventuali altri attributi e metodi privati specifici del task
public:
    TaskWeek();
    virtual bool ValidateParameter(QString name,QString value);
    virtual bool CheckExpiration();
    virtual void Execute();
    .....eventuali altri metodi pubblici specifici per il task
};

File taskWeek.cpp
-----------------
bool TaskWeek::ValidateParameter(QString name,QString value)
{
    ....azioni per validazione del parametro specificato
}
bool TaskWeek::CheckExpiration()
{
    if (QDate::currentDate().dayOfWeek() == 1)
    {
        QTime t(10,0,0);
        if (QTime::currentTime() == t)
        {
            return true;
        }
    }
    return false;
}
bool TaskWeek::Execute()
{
    ....azioni da eseguire ogni lunedi mattina
}
