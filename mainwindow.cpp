#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rekord.h"
#include <QDate>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "sstream"
#include <iostream>


using namespace pugi;
using namespace std;

//TAK SIE MOZNA DOBRAC DO DATY
//  if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(0,0))->date()>ui->dateEdit_begin->date())

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMainWindow::showMaximized();

    init_tablica_nazw();

    init_table();
    init_last_row();
    wczytaj();
    aktualizuj_razem();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Rekord *mRekord= new Rekord;

    ui->tableWidget->insertRow(ui->tableWidget->rowCount()-1);

    mRekord->mDate->setDate(QDate::currentDate());
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-2,0,mRekord->mDate);

    for(int i=0;i<15;i++)
    {
        QTableWidgetItem *itm=new QTableWidgetItem;
        itm->setText(NULL);
        if(i+1==10 || i+1==11 || i+1==15 || i+1==13)
        {
            itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
            itm->setBackgroundColor(Qt::lightGray);
        }
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,i+1,itm);        
    }
    row_ready.push_back(true);


}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->tableWidget->currentRow()!=ui->tableWidget->rowCount()-1)
    {
        int previous;
        previous=ui->tableWidget->currentRow();
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());

        if(previous>=ui->tableWidget->rowCount()-1) ui->tableWidget->selectRow(ui->tableWidget->rowCount());
        else ui->tableWidget->selectRow(previous);
        row_ready.pop_back();
        aktualizuj_razem();
    }


}






void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::init_table()
{
    setWindowTitle("Hajsy");
    Rekord *mRekord= new Rekord;
    mRekord->mDate->setDate(QDate::currentDate());
    ui->tableWidget->setCellWidget(0,0,mRekord->mDate);

    ui->tableWidget->horizontalHeader()->setMinimumHeight(50);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setColumnWidth(4,200);
    ui->tableWidget->setColumnWidth(5,150);
    ui->tableWidget->setColumnWidth(6,230);
    ui->tableWidget->setColumnWidth(7,150);
    ui->tableWidget->setColumnWidth(8,150);
    ui->tableWidget->setColumnWidth(12,200);


    ui->tableWidget->setColumnWidth(0,80);

    for(int i=0;i<15;i++)
    {
        QTableWidgetItem *itm=new QTableWidgetItem;
        itm->setText(NULL);
        if(i+1==10 || i+1==11 || i+1==15 || i+1==13)
        {
            itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
            itm->setBackgroundColor(Qt::lightGray);

        }
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i+1,itm);
    }
    row_ready.push_back(true);


}

void MainWindow::init_last_row()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);


    for(int i=0;i<16;i++)
    {
        QTableWidgetItem *itm=new QTableWidgetItem;

        if(i==0)
        {
            itm->setText("Razem");

        }
        else itm->setText(NULL);
        itm->setBackgroundColor(Qt::green);
        itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i,itm);

    }
    row_ready.push_back(true);


}

void MainWindow::on_pushButton_4_clicked()
{
    //godziny suma
    double suma_godzin=0;



    QString s_suma_godzin;
    suma_godzin=ui->tableWidget->item(ui->tableWidget->currentRow(),3)->text().toDouble()
            +ui->tableWidget->item(ui->tableWidget->currentRow(),9)->text().toDouble();
    s_suma_godzin=QString::number(suma_godzin);
    ui->tableWidget->item(ui->tableWidget->currentRow(),10)->setText(s_suma_godzin);

    //dochod suma
    double suma_dochodu=0;
    QString s_suma_dochodu;
    suma_dochodu=ui->tableWidget->item(ui->tableWidget->currentRow(),2)->text().toDouble()*ui->tableWidget->item(ui->tableWidget->currentRow(),3)->text().toDouble()
            +ui->tableWidget->item(ui->tableWidget->currentRow(),4)->text().toDouble()*ui->tableWidget->item(ui->tableWidget->currentRow(),5)->text().toDouble()
            +ui->tableWidget->item(ui->tableWidget->currentRow(),8)->text().toDouble()*ui->tableWidget->item(ui->tableWidget->currentRow(),9)->text().toDouble();

    s_suma_dochodu=QString::number(suma_dochodu);
    ui->tableWidget->item(ui->tableWidget->currentRow(),11)->setText(s_suma_dochodu);

    //zysk suma
    double suma_zysk=0;
    suma_zysk=suma_dochodu+ui->tableWidget->item(ui->tableWidget->currentRow(),14)->text().toDouble();
    QString s_suma_zysk;
    s_suma_zysk=QString::number(suma_zysk);
    ui->tableWidget->item(ui->tableWidget->currentRow(),15)->setText(s_suma_zysk);

    //tax dojazdowy
    double suma_tax=0;
    suma_tax=(ui->tableWidget->item(ui->tableWidget->currentRow(),5)->text().toDouble()
              +ui->tableWidget->item(ui->tableWidget->currentRow(),7)->text().toDouble())
            *ui->tableWidget->item(ui->tableWidget->currentRow(),12)->text().toDouble();
    QString s_suma_tax;
    s_suma_tax=QString::number(suma_tax);
    ui->tableWidget->item(ui->tableWidget->currentRow(),13)->setText(s_suma_tax);

    //razem

    aktualizuj_razem();

 /*  for(int i=1;i<16;i++)
    {
       if( i!=10 && i!=11 && i!=15 && i!=13)
     {
       ui->tableWidget->item(ui->tableWidget->currentRow(),i)->setBackgroundColor(Qt::white);
       }
    }*/






    //zapisz
    zapisz("data.xml");
    zapisz("data_backup.xml");


}

void MainWindow::aktualizuj_razem()
{

    sortuj();
    double suma_godzin_kolumna=0;
    double suma_czasu_kolumna=0;
    double suma_milaz_refundowany=0;
    double suma_milaz_nierefundowany=0;
    double suma_dochod_kolumna=0;
    double suma_zysk_kolumna=0;
    double suma_godzin_wszystkich=0;
    double suma_inne=0;
    double suma_tax=0;

    for(int j=0;j<ui->tableWidget->rowCount()-1;j++)
    {
        ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)
                ->setText(QString::number(suma_godzin_kolumna+=ui->tableWidget->item(j,3)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,9)
                ->setText(QString::number(suma_czasu_kolumna+=ui->tableWidget->item(j,9)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)
                ->setText(QString::number(suma_milaz_refundowany+=ui->tableWidget->item(j,5)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,7)
                ->setText(QString::number(suma_milaz_nierefundowany+=ui->tableWidget->item(j,7)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,10)
                ->setText(QString::number(suma_godzin_wszystkich+=ui->tableWidget->item(j,10)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,15)
                ->setText(QString::number(suma_zysk_kolumna+=ui->tableWidget->item(j,15)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,11)
                ->setText(QString::number(suma_dochod_kolumna+=ui->tableWidget->item(j,11)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,13)
                ->setText(QString::number(suma_tax+=ui->tableWidget->item(j,13)->text().toDouble()));

        ui->tableWidget->item(ui->tableWidget->rowCount()-1,14)
                ->setText(QString::number(suma_inne+=ui->tableWidget->item(j,14)->text().toDouble()));



    }

}

void MainWindow::sortuj()
{

    for(int i=0;i<ui->tableWidget->rowCount()-2;i++)
    {
        for(int j=0;j<ui->tableWidget->rowCount()-2-i;j++)
        {
            if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j,0))->date()
                    >static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j+1,0))->date())
            {
                QTableWidgetItem first[15];
                QTableWidgetItem second[15];

                QDateEdit *first_date=new QDateEdit;
                first_date->setDate(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j,0))->date());
                QDateEdit *second_date=new QDateEdit;
                second_date->setDate(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j+1,0))->date());

                ui->tableWidget->setCellWidget(j,0,second_date);
                ui->tableWidget->setCellWidget(j+1,0,first_date);


                for(int k=0;k<15;k++)
                {
                    first[k].setText(ui->tableWidget->item(j,k+1)->text());
                    second[k].setText(ui->tableWidget->item(j+1,k+1)->text());

                    ui->tableWidget->item(j,k+1)->setText(second[k].text());
                    ui->tableWidget->item(j+1,k+1)->setText(first[k].text());
                }
            }
        }

    }
}

void MainWindow::zapisz(QString nazwa)
{
    xml_document doc;
    xml_node spis = doc.append_child("Zarobki");
    spis.append_attribute("Tytul")="Hajsy";

    for(int i=0; i<ui->tableWidget->rowCount()-1;i++)
    {
        xml_node rekord = spis.append_child("rekord");

        rekord.append_attribute("data_rok") =static_cast<QDateEdit*>(ui->tableWidget->cellWidget(i,0))->date().year();
        rekord.append_attribute("data_miesiac") =static_cast<QDateEdit*>(ui->tableWidget->cellWidget(i,0))->date().month();
        rekord.append_attribute("data_dzien") =static_cast<QDateEdit*>(ui->tableWidget->cellWidget(i,0))->date().day();

        for(int j=1;j<16;j++)
        {
            rekord.append_attribute(tablica_nazw[j].toStdString().c_str()) =ui->tableWidget->item(i,j)->text().toStdString().c_str();
        }



    }

    doc.save_file(nazwa.toStdString().c_str());
}
void MainWindow::wczytaj()
{

    xml_document doc;
    if(doc.load_file("data.xml"))
    {
        xml_node spis = doc.child("Zarobki");
        for(xml_node rekord=spis.child("rekord");rekord;rekord=rekord.next_sibling("rekord"))
        {
            Rekord *mRekord= new Rekord;
            ui->tableWidget->insertRow(ui->tableWidget->rowCount()-1);
            stringstream ss_rok;
            stringstream ss_miesiac;
            stringstream ss_dzien;

            ss_rok<<rekord.attribute("data_rok").value();
            int  rok=0;
            ss_rok>>rok;

            ss_miesiac<<rekord.attribute("data_miesiac").value();
            int  miesiac=0;
            ss_miesiac>>miesiac;

            ss_dzien<<rekord.attribute("data_dzien").value();
            int  dzien=0;
            ss_dzien>>dzien;

            QDate this_date;
            this_date.setDate(rok,miesiac,dzien);
            mRekord->mDate->setDate(this_date);
            ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-2,0,mRekord->mDate);


            for(int i=0;i<15;i++)
            {
                QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setText(rekord.attribute(tablica_nazw[i+1].toStdString().c_str()).value());
                if(i+1==10 || i+1==11 || i+1==15 || i+1==13)
                {
                    itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
                    itm->setBackgroundColor(Qt::lightGray);
                }
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,i+1,itm);
                row_ready.push_back(true);

            }
        }
    }
}

void MainWindow::init_tablica_nazw()
{
    tablica_nazw[1]="tytul";
    tablica_nazw[2]="przelicznik_godzinowy";
    tablica_nazw[3]="godziny";
    tablica_nazw[4]="przelicznik_milazu_refundowanego";
    tablica_nazw[5]="milaz_refundowany";
    tablica_nazw[6]="przelicznik_milazu_niereundowanego";
    tablica_nazw[7]="milaz_nierefundowany";
    tablica_nazw[8]="przelicznik_czasu";
    tablica_nazw[9]="czas";
    tablica_nazw[10]="suma_czasu";
    tablica_nazw[11]="dochod";
    tablica_nazw[12]="przelicznik_taxu_dojazdowego";
    tablica_nazw[13]="tax_dojazdowy";
    tablica_nazw[14]="inne";
    tablica_nazw[15]="zysk";
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(ui->tableWidget->item(row,column)->text().toDouble()<0) ui->tableWidget->item(row,column)->setTextColor(Qt::red);
    else ui->tableWidget->item(row,column)->setTextColor(Qt::black);
}






void MainWindow::on_actionO_Qt_triggered()
{
    QApplication::aboutQt();
}
