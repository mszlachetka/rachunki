/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionO_Qt;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *check_data;
    QCheckBox *chec_tytul;
    QCheckBox *check_przelicznik_godzinowy;
    QCheckBox *check_godziny;
    QCheckBox *check_przelicznik_milazu_refundowanego;
    QCheckBox *check_milaz_refundowany;
    QCheckBox *check_przelicznik_milazu_nierefundowanego;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *check_milaz_nierefundowany;
    QCheckBox *check_przelicznik_czasu;
    QCheckBox *check_czas;
    QCheckBox *check_dochod;
    QCheckBox *check_przelicznik_taxu_dojazdowego;
    QCheckBox *check_tax_dojazdowy;
    QCheckBox *check_inne;
    QCheckBox *check_zysk;
    QCheckBox *check_suma_czasu;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QDateEdit *dateEdit_begin;
    QLabel *label_2;
    QDateEdit *dateEdit_end;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuHELP;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1349, 500);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/obrazki/hajs.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionO_Qt = new QAction(MainWindow);
        actionO_Qt->setObjectName(QStringLiteral("actionO_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 16)
            tableWidget->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(1329, 0));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setTextElideMode(Qt::ElideLeft);
        tableWidget->setRowCount(1);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);

        verticalLayout_4->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        check_data = new QCheckBox(centralWidget);
        check_data->setObjectName(QStringLiteral("check_data"));
        check_data->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(check_data);

        chec_tytul = new QCheckBox(centralWidget);
        chec_tytul->setObjectName(QStringLiteral("chec_tytul"));
        chec_tytul->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(chec_tytul);

        check_przelicznik_godzinowy = new QCheckBox(centralWidget);
        check_przelicznik_godzinowy->setObjectName(QStringLiteral("check_przelicznik_godzinowy"));
        check_przelicznik_godzinowy->setMaximumSize(QSize(130, 16777215));

        horizontalLayout->addWidget(check_przelicznik_godzinowy);

        check_godziny = new QCheckBox(centralWidget);
        check_godziny->setObjectName(QStringLiteral("check_godziny"));
        check_godziny->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(check_godziny);

        check_przelicznik_milazu_refundowanego = new QCheckBox(centralWidget);
        check_przelicznik_milazu_refundowanego->setObjectName(QStringLiteral("check_przelicznik_milazu_refundowanego"));
        check_przelicznik_milazu_refundowanego->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(check_przelicznik_milazu_refundowanego);

        check_milaz_refundowany = new QCheckBox(centralWidget);
        check_milaz_refundowany->setObjectName(QStringLiteral("check_milaz_refundowany"));
        check_milaz_refundowany->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(check_milaz_refundowany);

        check_przelicznik_milazu_nierefundowanego = new QCheckBox(centralWidget);
        check_przelicznik_milazu_nierefundowanego->setObjectName(QStringLiteral("check_przelicznik_milazu_nierefundowanego"));

        horizontalLayout->addWidget(check_przelicznik_milazu_nierefundowanego);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        check_milaz_nierefundowany = new QCheckBox(centralWidget);
        check_milaz_nierefundowany->setObjectName(QStringLiteral("check_milaz_nierefundowany"));
        check_milaz_nierefundowany->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_2->addWidget(check_milaz_nierefundowany);

        check_przelicznik_czasu = new QCheckBox(centralWidget);
        check_przelicznik_czasu->setObjectName(QStringLiteral("check_przelicznik_czasu"));
        check_przelicznik_czasu->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(check_przelicznik_czasu);

        check_czas = new QCheckBox(centralWidget);
        check_czas->setObjectName(QStringLiteral("check_czas"));
        check_czas->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(check_czas);

        check_dochod = new QCheckBox(centralWidget);
        check_dochod->setObjectName(QStringLiteral("check_dochod"));
        check_dochod->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(check_dochod);

        check_przelicznik_taxu_dojazdowego = new QCheckBox(centralWidget);
        check_przelicznik_taxu_dojazdowego->setObjectName(QStringLiteral("check_przelicznik_taxu_dojazdowego"));
        check_przelicznik_taxu_dojazdowego->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(check_przelicznik_taxu_dojazdowego);

        check_tax_dojazdowy = new QCheckBox(centralWidget);
        check_tax_dojazdowy->setObjectName(QStringLiteral("check_tax_dojazdowy"));
        check_tax_dojazdowy->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_2->addWidget(check_tax_dojazdowy);

        check_inne = new QCheckBox(centralWidget);
        check_inne->setObjectName(QStringLiteral("check_inne"));
        check_inne->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(check_inne);

        check_zysk = new QCheckBox(centralWidget);
        check_zysk->setObjectName(QStringLiteral("check_zysk"));
        check_zysk->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(check_zysk);

        check_suma_czasu = new QCheckBox(centralWidget);
        check_suma_czasu->setObjectName(QStringLiteral("check_suma_czasu"));

        horizontalLayout_2->addWidget(check_suma_czasu);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateEdit_begin = new QDateEdit(centralWidget);
        dateEdit_begin->setObjectName(QStringLiteral("dateEdit_begin"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateEdit_begin);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dateEdit_end = new QDateEdit(centralWidget);
        dateEdit_end->setObjectName(QStringLiteral("dateEdit_end"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dateEdit_end);


        horizontalLayout_3->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1349, 21));
        menuHELP = new QMenu(menuBar);
        menuHELP->setObjectName(QStringLiteral("menuHELP"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(dateEdit_begin);
        label_2->setBuddy(dateEdit_end);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuHELP->menuAction());
        menuHELP->addAction(actionO_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionO_Qt->setText(QApplication::translate("MainWindow", "O Qt", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Data", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Tytu\305\202", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Przelicznik Godzinowy (Praca)", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Godziny (Praca)", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Przelicznik Mila\305\274u Refundowanego", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Mila\305\274 Refundowany", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Przelicznik Mila\305\274u Nierefundowanego", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Mila\305\274 Nierefundowany", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Przelicznik  Czasu(Dojazd)", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Czas (Dojazd)", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Suma Czasu", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Doch\303\263d", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Przelicznik Taxu Dojazdowego", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Tax Dojazdowy", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Inne", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Zysk", 0));
        check_data->setText(QApplication::translate("MainWindow", "data", 0));
        chec_tytul->setText(QApplication::translate("MainWindow", "tytu\305\202", 0));
        check_przelicznik_godzinowy->setText(QApplication::translate("MainWindow", "przelicznik godzinowy", 0));
        check_godziny->setText(QApplication::translate("MainWindow", "godziny", 0));
        check_przelicznik_milazu_refundowanego->setText(QApplication::translate("MainWindow", "przelicznik mila\305\274u refundowanego", 0));
        check_milaz_refundowany->setText(QApplication::translate("MainWindow", "mila\305\274 refundowany", 0));
        check_przelicznik_milazu_nierefundowanego->setText(QApplication::translate("MainWindow", "przelicznik mila\305\274u nierefundowanego", 0));
        check_milaz_nierefundowany->setText(QApplication::translate("MainWindow", "mila\305\274 nierefundowany", 0));
        check_przelicznik_czasu->setText(QApplication::translate("MainWindow", "przelicznik czasu", 0));
        check_czas->setText(QApplication::translate("MainWindow", "czas", 0));
        check_dochod->setText(QApplication::translate("MainWindow", "suma czasu", 0));
        check_przelicznik_taxu_dojazdowego->setText(QApplication::translate("MainWindow", "doch\303\263d", 0));
        check_tax_dojazdowy->setText(QApplication::translate("MainWindow", "przelicznik taxu dojazdowego", 0));
        check_inne->setText(QApplication::translate("MainWindow", "tax dojazdowy", 0));
        check_zysk->setText(QApplication::translate("MainWindow", "inne", 0));
        check_suma_czasu->setText(QApplication::translate("MainWindow", "zysk", 0));
        label->setText(QApplication::translate("MainWindow", "Od kiedy", 0));
        label_2->setText(QApplication::translate("MainWindow", "Do kiedy", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Dodaj wpis", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Aktualizuj", 0));
        pushButton_4->setShortcut(QApplication::translate("MainWindow", "Space", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Usun wpis", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Eksportuj do pdf", 0));
        menuHELP->setTitle(QApplication::translate("MainWindow", "HELP", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
