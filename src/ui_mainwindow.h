/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btn_com_refresh;
    QPushButton *btn_com_connect;
    QLabel *label_5;
    QLineEdit *lineEdit_command;
    QPushButton *btn_com_send;
    QPlainTextEdit *plainTextEdit_history;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *comboBox_ports;
    QComboBox *comboBox_speed;
    QComboBox *comboBox_parity;
    QComboBox *comboBox_data_bits;
    QComboBox *comboBox_stop_bits;
    QRadioButton *radioButton_ascii;
    QRadioButton *radioButton_bin;
    QRadioButton *radioButton_oct;
    QRadioButton *radioButton_dec;
    QRadioButton *radioButton_hex;
    QLabel *label_10;
    QPushButton *btn_append_crc;
    QComboBox *comboBox_commands;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 140, 47, 13));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -2, 600, 347));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btn_com_refresh = new QPushButton(tab);
        btn_com_refresh->setObjectName(QStringLiteral("btn_com_refresh"));
        btn_com_refresh->setGeometry(QRect(340, 25, 75, 23));
        btn_com_connect = new QPushButton(tab);
        btn_com_connect->setObjectName(QStringLiteral("btn_com_connect"));
        btn_com_connect->setGeometry(QRect(420, 25, 75, 23));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 47, 13));
        lineEdit_command = new QLineEdit(tab);
        lineEdit_command->setObjectName(QStringLiteral("lineEdit_command"));
        lineEdit_command->setGeometry(QRect(50, 90, 201, 20));
        btn_com_send = new QPushButton(tab);
        btn_com_send->setObjectName(QStringLiteral("btn_com_send"));
        btn_com_send->setGeometry(QRect(260, 90, 75, 23));
        plainTextEdit_history = new QPlainTextEdit(tab);
        plainTextEdit_history->setObjectName(QStringLiteral("plainTextEdit_history"));
        plainTextEdit_history->setGeometry(QRect(10, 120, 321, 121));
        plainTextEdit_history->setReadOnly(true);
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 322, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 5, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        comboBox_ports = new QComboBox(gridLayoutWidget);
        comboBox_ports->setObjectName(QStringLiteral("comboBox_ports"));

        gridLayout->addWidget(comboBox_ports, 2, 4, 1, 1);

        comboBox_speed = new QComboBox(gridLayoutWidget);
        comboBox_speed->setObjectName(QStringLiteral("comboBox_speed"));

        gridLayout->addWidget(comboBox_speed, 2, 5, 1, 1);

        comboBox_parity = new QComboBox(gridLayoutWidget);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));
        comboBox_parity->setEnabled(true);

        gridLayout->addWidget(comboBox_parity, 2, 3, 1, 1);

        comboBox_data_bits = new QComboBox(gridLayoutWidget);
        comboBox_data_bits->setObjectName(QStringLiteral("comboBox_data_bits"));
        comboBox_data_bits->setEnabled(true);

        gridLayout->addWidget(comboBox_data_bits, 2, 0, 1, 1);

        comboBox_stop_bits = new QComboBox(gridLayoutWidget);
        comboBox_stop_bits->setObjectName(QStringLiteral("comboBox_stop_bits"));
        comboBox_stop_bits->setEnabled(true);

        gridLayout->addWidget(comboBox_stop_bits, 2, 1, 1, 1);

        radioButton_ascii = new QRadioButton(tab);
        radioButton_ascii->setObjectName(QStringLiteral("radioButton_ascii"));
        radioButton_ascii->setGeometry(QRect(60, 60, 51, 17));
        radioButton_bin = new QRadioButton(tab);
        radioButton_bin->setObjectName(QStringLiteral("radioButton_bin"));
        radioButton_bin->setEnabled(false);
        radioButton_bin->setGeometry(QRect(120, 60, 41, 17));
        radioButton_oct = new QRadioButton(tab);
        radioButton_oct->setObjectName(QStringLiteral("radioButton_oct"));
        radioButton_oct->setGeometry(QRect(160, 60, 41, 17));
        radioButton_dec = new QRadioButton(tab);
        radioButton_dec->setObjectName(QStringLiteral("radioButton_dec"));
        radioButton_dec->setGeometry(QRect(210, 60, 41, 17));
        radioButton_hex = new QRadioButton(tab);
        radioButton_hex->setObjectName(QStringLiteral("radioButton_hex"));
        radioButton_hex->setGeometry(QRect(260, 60, 41, 17));
        radioButton_hex->setChecked(true);
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 62, 47, 13));
        btn_append_crc = new QPushButton(tab);
        btn_append_crc->setObjectName(QStringLiteral("btn_append_crc"));
        btn_append_crc->setGeometry(QRect(340, 90, 81, 23));
        comboBox_commands = new QComboBox(tab);
        comboBox_commands->setObjectName(QStringLiteral("comboBox_commands"));
        comboBox_commands->setGeometry(QRect(210, 260, 161, 22));
        comboBox_commands->setEditable(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        comboBox_data_bits->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Hist\303\263ria:", Q_NULLPTR));
        btn_com_refresh->setText(QApplication::translate("MainWindow", "Vyh\304\276ada\305\245", Q_NULLPTR));
        btn_com_connect->setText(QApplication::translate("MainWindow", "Pripoji\305\245", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Pr\303\255kaz:", Q_NULLPTR));
        btn_com_send->setText(QApplication::translate("MainWindow", "Odosla\305\245", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Parita:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Stop bity:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "D\303\241tov\303\251 bity:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "R\303\275chlos\305\245:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Port:", Q_NULLPTR));
        comboBox_parity->clear();
        comboBox_parity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Even", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Odd", Q_NULLPTR)
        );
        comboBox_data_bits->clear();
        comboBox_data_bits->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        comboBox_stop_bits->clear();
        comboBox_stop_bits->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
        );
        radioButton_ascii->setText(QApplication::translate("MainWindow", "ASCII", Q_NULLPTR));
        radioButton_bin->setText(QApplication::translate("MainWindow", "Bin", Q_NULLPTR));
        radioButton_oct->setText(QApplication::translate("MainWindow", "Oct", Q_NULLPTR));
        radioButton_dec->setText(QApplication::translate("MainWindow", "Dec", Q_NULLPTR));
        radioButton_hex->setText(QApplication::translate("MainWindow", "Hex", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Form\303\241t:", Q_NULLPTR));
        btn_append_crc->setText(QApplication::translate("MainWindow", "Pripoji\305\245 CRC16", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "S\303\251riov\303\275 port", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "---", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
