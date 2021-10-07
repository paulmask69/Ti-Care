#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
* @brief Costruttore
*
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TT-Care Test Tecnico");

    this->closeApplication = false;

    // Inizializzazione icona in system tray e relativo tooltip
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("TT-Care Test Tecnico");

    // creazione menu contestuale da visualizzare su icona system tray (click tasto destro mouse)
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction("Imposta parametri", this);
    QAction * quitAction = new QAction("Esci", this);

    // connessione segnali relativi ad eventi click su voci di menu in system tray
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));              // visualizza pannello gestione parametri
    connect(quitAction, SIGNAL(triggered()), this, SLOT(exitApplication()));   // chiude applicativo
    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    // Associa il menu contestuale precedentemente creato all'icona in system tray
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    // connessione segnale relativo a click su icona in system tray
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    // connessione segnali di modifica scelta in menu a tendina relativi a task e parametri
    connect(ui->cmbTask, SIGNAL(currentTextChanged(QString)), SLOT(selectedTask(QString)));
    connect(ui->cmbParameter, SIGNAL(currentTextChanged(QString)), SLOT(selectedParameter(QString)));

    // connessione segnale di pressione pulsante di conferma modifica parametro
    connect(ui->buttConfirm, SIGNAL(clicked()), SLOT(setButtonConfirm()));

    // associa i task di esempio all'oggetto taskmanager che li gestira'
    taskmanager.SetTask("Task Print",&taskprint);
    taskmanager.SetTask("Task Check File",&taskcheckfile);
    // se sono stati creati ulteriori task andranno aggiunti in maniera analoga in questo punto

    // popola menu a tendina con i task configurati
    populateComboTask();

    // avvia il thread dedicato alla gestione della periodicita' dei task
    taskmanager.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
* @brief Funzione richiamata in automatico su chiusura finestra
*        Ereditata dalla classe genitrice ed utilizzata per evitare la chiusura dell'applicativo
*        mantenendo attiva l'icona in system tray
*/
void MainWindow::closeEvent(QCloseEvent * event)
{
    if (!this->closeApplication)    // filtra la chiusura dell'applicativo se non e' avvenuta una richiesta da menu in system tray
    {
        event->ignore();
        this->hide();               // nasconde il form ma non chiude l'applicativo in quanto l'evento e' stato ignorato nell'istruzione precedente
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        trayIcon->showMessage("TT-Care Test Tecnico", "", icon, 1000);      // visualizza messaggio di popup in system tray per indicare che l'applicativo e' ancora attivo
    }
}

/**
* @brief Funzione richiamata da voce di menu in system tray per chiusura applicativo
*/
void MainWindow::exitApplication()
{
    taskmanager.Stop();                 // ferma thread dedicato al controllo dei task
    while (taskmanager.IsRunning());    // attende la conferma di chiusura del thread dedicato al controllo dei task
    this->closeApplication = true;      // segnala all'evento close l'avvenuta richiesta di chiusura applicativo
    this->close();                      // chiude il form
}

/**
* @brief Funzione che gestisce l'evento click sull'icona in system tray
*
*/
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
            if (!this->isVisible())
            {
                this->show();     // visualizza form
            }
            else
            {
                this->hide();    // nasconde form
            }
            break;
        default:
            break;
    }
}

/**
* @brief Funzione che gestisce l'evento di modifica task in menu a tendina
*
*/
void MainWindow::selectedTask(QString taskname)
{
    ui->lblInfo->setText("");
    populateComboParameter(taskname);
}

/**
* @brief Funzione che gestisce l'evento di modifica parametro in menu a tendina
*
*/
void MainWindow::selectedParameter(QString parametername)
{
    if (parametername != "")
    {
        ui->lblInfo->setText("");
        Task* task = taskmanager.GetTask(ui->cmbTask->currentText());
        if (task != NULL)
        {
            QString value = task->GetParameter(parametername);
            ui->txtValue->setText(value);
        }
    }
}

/**
* @brief Funzione che gestisce l'evento click su pulsante di conferma modifica parametro
*
*/
void MainWindow::setButtonConfirm()
{
    Task* task = taskmanager.GetTask(ui->cmbTask->currentText());
    if (task != NULL)
    {
        if (task->ValidateParameter(ui->cmbParameter->currentText(),ui->txtValue->toPlainText()))
        {
            task->SetParameter(ui->cmbParameter->currentText(),ui->txtValue->toPlainText());
            ui->lblInfo->setStyleSheet("QLabel { color : green; }");
            ui->lblInfo->setText("Modifica effettuata");
        }
        else
        {
            ui->lblInfo->setStyleSheet("QLabel { color : red; }");
            ui->lblInfo->setText("Errore validazione parametri");
        }
    }
}

/**
* @brief Funzione utilizzata per popolare il menu a tendina relativo all'elenco dei task configurati
*
*/
void MainWindow::populateComboTask()
{
    auto it = taskmanager.FirstTask();
    ui->cmbTask->clear();
    while (it != taskmanager.LastTask())
    {
        ui->cmbTask->addItem(it.key());
        ++it;
    }
}

/**
* @brief Funzione utilizzata per popolare il menu a tendina relativo all'elenco dei parametri relativi al task selezionato
*
*/
void MainWindow::populateComboParameter(QString taskname)
{
    Task* task = taskmanager.GetTask(taskname);
    if (task != NULL)
    {
        auto it = task->FirstParameter();
        ui->cmbParameter->clear();
        while (it != task->LastParameter())
        {
            ui->cmbParameter->addItem(it.key());
            ++it;
        }
    }
}

