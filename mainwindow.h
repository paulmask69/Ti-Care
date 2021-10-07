#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include "taskmanager.h"
#include "taskprint.h"
#include "taskcheckfile.h"
// in caso di ulteriori task da configurare, aggiungere qui l'inclusione dei relativi file header

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * @brief Costruttore
    *
    */
    explicit MainWindow(QWidget *parent = 0);

    /**
    * @brief Distruttore
    *
    */
    ~MainWindow();

protected:
    /**
    * @brief Funzione richiamata in automatico su chiusura finestra
    *        Ereditata dalla classe genitrice ed utilizzata per evitare la chiusura dell'applicativo
    *        mantenendo attiva l'icona in system tray
    */
    void closeEvent(QCloseEvent * event);

private slots:
    /**
    * @brief Funzione richiamata da voce di menu in system tray per chiusura applicativo
    */
    void exitApplication();

    /**
    * @brief Funzione che gestisce l'evento click sull'icona in system tray
    *
    */
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    /**
    * @brief Funzione che gestisce l'evento di modifica task in menu a tendina
    *
    */
    void selectedTask(QString taskname);

    /**
    * @brief Funzione che gestisce l'evento di modifica parametro in menu a tendina
    *
    */
    void selectedParameter(QString parametername);

    /**
    * @brief Funzione che gestisce l'evento click su pulsante di conferma modifica parametro
    *
    */
    void setButtonConfirm();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    TaskManager taskmanager;        // oggetto che gestisce la periodicita' dei task in thread dedicato
    TaskPrint taskprint;            // oggetto che gestisce il task che stampa a video un testo
    TaskCheckFile taskcheckfile;    // oggetto che gestisce il task che controlla la presenza di un file su disco
    bool closeApplication;          // flag utilizzata per identificare se esiste una richiesta di chiusura dell'applicativo

    /**
    * @brief Funzione utilizzata per popolare il menu a tendina relativo all'elenco dei task configurati
    *
    */
    void populateComboTask();

    /**
    * @brief Funzione utilizzata per popolare il menu a tendina relativo all'elenco dei parametri relativi al task selezionato
    *
    */
    void populateComboParameter(QString);
};

#endif // MAINWINDOW_H
