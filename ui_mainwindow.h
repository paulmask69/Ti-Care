/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *cmbTask;
    QLabel *label;
    QComboBox *cmbParameter;
    QLabel *label_2;
    QTextEdit *txtValue;
    QLabel *label_3;
    QPushButton *buttConfirm;
    QLabel *lblInfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(383, 287);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(383, 287));
        MainWindow->setMaximumSize(QSize(383, 287));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cmbTask = new QComboBox(centralWidget);
        cmbTask->setObjectName(QStringLiteral("cmbTask"));
        cmbTask->setGeometry(QRect(120, 10, 201, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 51, 16));
        cmbParameter = new QComboBox(centralWidget);
        cmbParameter->setObjectName(QStringLiteral("cmbParameter"));
        cmbParameter->setGeometry(QRect(120, 50, 201, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 81, 16));
        txtValue = new QTextEdit(centralWidget);
        txtValue->setObjectName(QStringLiteral("txtValue"));
        txtValue->setGeometry(QRect(120, 90, 201, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 90, 91, 20));
        buttConfirm = new QPushButton(centralWidget);
        buttConfirm->setObjectName(QStringLiteral("buttConfirm"));
        buttConfirm->setGeometry(QRect(120, 140, 201, 31));
        lblInfo = new QLabel(centralWidget);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(120, 180, 201, 31));
        lblInfo->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 383, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nome task", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nome parametro", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Valore parametro</p></body></html>", Q_NULLPTR));
        buttConfirm->setText(QApplication::translate("MainWindow", "CONFERMA", Q_NULLPTR));
        lblInfo->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Valore parametro</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
