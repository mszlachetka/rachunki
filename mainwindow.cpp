#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rekord.h"
#include <QDate>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "sstream"
#include <iostream>
#include <QPrinter>
#include <QPainter>
#include <QDir>



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
    init_short_tablica_nazw();
    ui->dateEdit_end->setDate(QDate::currentDate());

    init_table();
    init_last_row();
    wczytaj();
    aktualizuj_razem();
    ui->tableWidget->setColumnHidden(10,true);
    ui->check_suma_czasu->setHidden(true);


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
    if((ui->tableWidget->currentRow()!=ui->tableWidget->rowCount()-1)  && ui->lineEdit->text().isEmpty())
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
    // gdzies trzeba wkleic ile_na_stronie++;
    QPrinter printer;


    printer.setOutputFileName(ui->linia_tytulowa->text()+".pdf");
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOrientation(QPrinter::Landscape);
    printer.setPaperSize(QPrinter::A4);
    printer.newPage();
    QPainter painter(&printer);
    //tu wpisac  tresc

    QFont mFont;

    QPen mPen;
    mPen.setWidth(2);
    painter.setPen(mPen);
    int xpos=50;
    int ypos=100;
    int cell_height=20;
    int cell_width=55;
    double ile_kolumn;

    int czyzmieniac=1;

    int ile_na_stronie=0;
    licz_okejki(ile_kolumn);

    //Wstep
    mFont.setPixelSize(15);
    painter.setFont(mFont);
    const QString mTitle=ui->linia_tytulowa->text();
    painter.drawText(50,25,mTitle);
    mFont.setPixelSize(11);
    painter.setFont(mFont);

    double suma_godzin_kolumna=0;
    double suma_czasu_kolumna=0;
    double suma_milaz_refundowany=0;
    double suma_milaz_nierefundowany=0;
    double suma_dochod_kolumna=0;
    double suma_zysk_kolumna=0;
    double suma_godzin_wszystkich=0;
    double suma_inne=0;
    double suma_tax=0;

    int site_counter=0;
        int max_site_counter=0;

        max_site_counter=(((ui->tableWidget->rowCount()+1)-(ui->tableWidget->rowCount()+1)%30))/30;
        if((ui->tableWidget->rowCount()+2)%30!=0) max_site_counter++;

    for(int j=1;j<=ui->tableWidget->rowCount();j++)
    {
       czyzmieniac=1;
        for(int i=0;i<ile_kolumn;i++)
        {
            if(j!=ui->tableWidget->rowCount())
            {
                if(!ui->tableWidget->isRowHidden(j-1))
                {
                if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()>=ui->dateEdit_begin->date() )
                 {
                     if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()<=ui->dateEdit_end->date() )
                     {


                if(wybrane_kolumny.at(i)==3) suma_godzin_kolumna+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==5) suma_milaz_refundowany +=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==7) suma_milaz_nierefundowany +=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==9) suma_czasu_kolumna+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==10) suma_godzin_wszystkich+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==11) suma_dochod_kolumna+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==13) suma_tax+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==14) suma_inne+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                if(wybrane_kolumny.at(i)==15) suma_zysk_kolumna+=ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text().toDouble();
                     }
                     else if(czyzmieniac==1 )
                     {
                         czyzmieniac=0;

                     }
                }
                else if(czyzmieniac==1 && i==0)
                {
                    czyzmieniac=0;

                }



            if(ile_na_stronie==30)
            {
                site_counter++;
                painter.drawText(xpos+15*cell_width+5,ypos+(3+ile_na_stronie)*cell_height-5,"strona "+QString::number(site_counter)
                                                 +" z "+QString::number(max_site_counter));
                printer.newPage();
                ile_na_stronie=0;
            }
            if(ile_na_stronie==0)
            {
                mPen.setWidth(3);
                mFont.setPixelSize(15);
                painter.setFont(mFont);
                painter.setPen(mPen);
                painter.drawText(50,25,mTitle);
                mFont.setPixelSize(11);
                painter.setFont(mFont);

                if(i==0)
                {
                    painter.drawRect(xpos+i*cell_width,ypos+(ile_na_stronie)*cell_height,cell_width,cell_height);
                    painter.drawText(xpos+i*cell_width+5,ypos+(1+ile_na_stronie)*cell_height-5,wybrane_short_tablica_nazw[i]);
                }
                if(i==1)
                {
                    painter.drawRect(xpos+i*cell_width,ypos+(ile_na_stronie)*cell_height,cell_width+30,cell_height);
                    painter.drawText(xpos+i*cell_width+5,ypos+(1+ile_na_stronie)*cell_height-5,wybrane_short_tablica_nazw[i]);



                }
                if(i>1)
                {
                    painter.drawRect(30+xpos+i*cell_width,ypos+(ile_na_stronie)*cell_height,cell_width,cell_height);
                    painter.drawText(30+xpos+i*cell_width+5,ypos+(1+ile_na_stronie)*cell_height-5,wybrane_short_tablica_nazw[i]);
                }

                QString description_1;
                QString description_2;
                mFont.setPixelSize(10);
                painter.setFont(mFont);
                for(int k=0;k<16;k++)
                {
                    if(k==0){}
                    else if (k>0 && k<9) description_1+=short_tablica_nazw[k]+"  =  "+tablica_nazw[k]+"     ";
                    else if(k!=10) description_2+=short_tablica_nazw[k]+"  =  "+tablica_nazw[k]+"       ";
                    else description_2+="";
                }
                painter.drawText(50,60,description_1);
                painter.drawText(50,80,description_2);


                mPen.setWidth(2);
                mFont.setPixelSize(11);
                painter.setFont(mFont);
                painter.setPen(mPen);

               if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()>=ui->dateEdit_begin->date() )
                {
                    if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()<=ui->dateEdit_end->date() )
                    {
                        if(j==0)
                        {

                        }
                        else if(i>1)
                        {
                            painter.drawText(30+xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text());
                            painter.drawRect(30+xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);

                        }
                        else if(wybrane_kolumny.at(i)==0)
                        {
                            painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);
                            painter.drawText(xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,
                                             QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().day())+"."+
                                             QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().month())+"."+
                                             QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().year()-2000));

                        }
                        else if(i==1)
                        {
                            painter.drawText(xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text());
                            painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width+30,cell_height);
                        }
                     if(i==ile_kolumn-1) ile_na_stronie++;
                    }



                }



            }
            else if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()>=ui->dateEdit_begin->date() )
            {
                if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,0))->date()<=ui->dateEdit_end->date() )
                {
                    if(j==0)
                    {

                    }
                    else if(i>1)
                    {
                        painter.drawText(30+xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text());
                        painter.drawRect(30+xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);

                    }
                    else if(wybrane_kolumny.at(i)==0)
                    {
                        painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);
                        painter.drawText(xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,
                                         QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().day())+"."+
                                         QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().month())+"."+
                                         QString::number(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(j-1,i))->date().year()-2000));

                    }
                    else if(i==1)
                    {
                        painter.drawText(xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,ui->tableWidget->item(j-1,wybrane_kolumny.at(i))->text());
                        painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width+30,cell_height);
                    }
                     if(i==ile_kolumn-1)  ile_na_stronie++;
                }




            }

            }

        }
         else
            {
                mPen.setWidth(3);
                painter.setPen(mPen);
               if(i==0)
                {
                painter.drawText(xpos+i*cell_width+2,ypos+(2+ile_na_stronie)*cell_height-5,"SUMA");
                painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);
                painter.drawText(xpos+15*cell_width+5,ypos+(33)*cell_height-5,"strona "+QString::number(site_counter+1)//28 bo ilosc +3
                                                +" z "+QString::number(max_site_counter));
               }
               else if(i==1)
                {
                   QString tresc;
                   if(wybrane_kolumny.at(i)==3) tresc=QString::number(suma_godzin_kolumna);
                   if(wybrane_kolumny.at(i)==5) tresc=QString::number(suma_milaz_refundowany);
                   if(wybrane_kolumny.at(i)==7) tresc=QString::number(suma_milaz_nierefundowany) ;
                   if(wybrane_kolumny.at(i)==9) tresc=QString::number(suma_czasu_kolumna);
                   if(wybrane_kolumny.at(i)==10) tresc=QString::number(suma_godzin_wszystkich);
                   if(wybrane_kolumny.at(i)==11) tresc=QString::number(suma_dochod_kolumna);
                   if(wybrane_kolumny.at(i)==13) tresc=QString::number(suma_tax);
                   if(wybrane_kolumny.at(i)==14) tresc=QString::number(suma_inne);
                   if(wybrane_kolumny.at(i)==15) tresc=QString::number(suma_zysk_kolumna);
                painter.drawText(xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,tresc);
                painter.drawRect(xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width+30,cell_height);
               }
               else if(i>1)
               {
                   QString tresc;
                   if(wybrane_kolumny.at(i)==3) tresc=QString::number(suma_godzin_kolumna);
                   if(wybrane_kolumny.at(i)==5) tresc=QString::number(suma_milaz_refundowany);
                   if(wybrane_kolumny.at(i)==7) tresc=QString::number(suma_milaz_nierefundowany) ;
                   if(wybrane_kolumny.at(i)==9) tresc=QString::number(suma_czasu_kolumna);
                   if(wybrane_kolumny.at(i)==10) tresc=QString::number(suma_godzin_wszystkich);
                   if(wybrane_kolumny.at(i)==11) tresc=QString::number(suma_dochod_kolumna);
                   if(wybrane_kolumny.at(i)==13) tresc=QString::number(suma_tax);
                   if(wybrane_kolumny.at(i)==14) tresc=QString::number(suma_inne);
                   if(wybrane_kolumny.at(i)==15) tresc=QString::number(suma_zysk_kolumna);
                   painter.drawText(30+xpos+i*cell_width+5,ypos+(2+ile_na_stronie)*cell_height-5,tresc);
                   painter.drawRect(30+xpos+i*cell_width,ypos+(1+ile_na_stronie)*cell_height,cell_width,cell_height);
               }

               mPen.setWidth(2);
               painter.setPen(mPen);
            }

    }

    }
    painter.end();
}






void MainWindow::init_table()
{
    setWindowTitle("RACHUNKI");
    Rekord *mRekord= new Rekord;
    mRekord->mDate->setDate(QDate::currentDate());
    ui->tableWidget->setCellWidget(0,0,mRekord->mDate);

    ui->tableWidget->horizontalHeader()->setMinimumHeight(50);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Data"<<"Tytul"<<"Przelicznik\nfunta\nbrytyjskiego"<<"Ilosc\nfuntow\nbrytyjskich"
                                               <<"Przelicznik\neuro"<<"Ilosc\neuro"
                                               <<"Przelicznik\ndolara\namerykanskiego"<<"Ilosc\ndolarow\namerykanskich"
                                               <<"Przelicznik\ninnych\nwalut"<<"Ilosc\ninnych\nwalut"
                                               <<"Suma\nczasu"<<"Pieniadze\nw obcych\nwalutach"<<"Przelicznik\npracy\nzarobkowej"<<"Dochód\nz pracy\nzarobkowej"
                                               <<"Inne\npieniadze\nw zlotych\npolskich"<<"Wszystkie\ndostepne\nsrodki");


    for(int i=0;i<16;i++)
    {
        ui->tableWidget->setColumnWidth(i,80);
        if(i==0) ui->tableWidget->setColumnWidth(i,91);
        if(i==4 || i==5 || i==12) ui->tableWidget->setColumnWidth(i,96);
         if(i==6 || i==7) ui->tableWidget->setColumnWidth(i,111);
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



    for(int j=0;j<ui->tableWidget->rowCount()-1;j++)
    {
    QString s_suma_godzin;
    suma_godzin=ui->tableWidget->item(j,3)->text().toDouble()
            +ui->tableWidget->item(j,9)->text().toDouble();
    s_suma_godzin=QString::number(suma_godzin);
    ui->tableWidget->item(j,10)->setText(s_suma_godzin);

    //dochod suma
    double suma_dochodu=0;
    QString s_suma_dochodu;
    suma_dochodu=ui->tableWidget->item(j,2)->text().toDouble()*ui->tableWidget->item(j,3)->text().toDouble()
            +ui->tableWidget->item(j,4)->text().toDouble()*ui->tableWidget->item(j,5)->text().toDouble()
            +ui->tableWidget->item(j,8)->text().toDouble()*ui->tableWidget->item(j,9)->text().toDouble();

    s_suma_dochodu=QString::number(suma_dochodu);
    ui->tableWidget->item(j,11)->setText(s_suma_dochodu);

    //zysk suma
    double suma_zysk=0;
    suma_zysk=suma_dochodu+ui->tableWidget->item(j,14)->text().toDouble();
    QString s_suma_zysk;
    s_suma_zysk=QString::number(suma_zysk);
    ui->tableWidget->item(j,15)->setText(s_suma_zysk);

    //tax dojazdowy
    double suma_tax=0;
    suma_tax=(ui->tableWidget->item(j,5)->text().toDouble()
              +ui->tableWidget->item(j,7)->text().toDouble())
            *ui->tableWidget->item(j,12)->text().toDouble();
    QString s_suma_tax;
    s_suma_tax=QString::number(suma_tax);
    ui->tableWidget->item(j,13)->setText(s_suma_tax);
    }
    //razem
    sortuj();
    aktualizuj_razem();
    if(ui->tableWidget->currentRow()==ui->tableWidget->rowCount()-1) aktualizuj_razem();








    //zapisz
    zapisz("data.xml");
    zapisz("data_backup.xml");


}

void MainWindow::aktualizuj_razem()
{

    double suma_godzin_kolumna=0;
    double suma_czasu_kolumna=0;
    double suma_milaz_refundowany=0;
    double suma_milaz_nierefundowany=0;
    double suma_dochod_kolumna=0;
    double suma_zysk_kolumna=0;
    double suma_godzin_wszystkich=0;
    double suma_inne=0;
    double suma_tax=0;

    int column=ui->tableWidget->currentColumn();
    int row=ui->tableWidget->currentRow();
    for(int i=0;i<ui->tableWidget->rowCount()-1;i++)
    {
        if(!ui->tableWidget->isRowHidden(i))
        {
       if((column==2 || column==4 || column==6) && !ui->tableWidget->item(row,column)->text().isEmpty()
                                                    && ui->tableWidget->item(row,column)->text().toDouble()!=0)
    {
    ui->tableWidget->item(i,2)->setText(ui->tableWidget->item(row,2)->text());
     ui->tableWidget->item(i,4)->setText(ui->tableWidget->item(row,4)->text());
   ui->tableWidget->item(i,6)->setText(ui->tableWidget->item(row,6)->text());
       }
    }
    }


    for(int i=1;i<16;i++)
    {
        if(row_ready.at(ui->tableWidget->currentRow()) && (ui->tableWidget->item(ui->tableWidget->currentRow(),i)->text().isNull() ||
         ui->tableWidget->item(ui->tableWidget->currentRow(),i)->text().isEmpty()) ) ui->tableWidget->item(ui->tableWidget->currentRow(),i)->setText("0");
    }

    for(int j=0;j<ui->tableWidget->rowCount()-1;j++)
    {

        if(!ui->tableWidget->isRowHidden(j))
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
    tablica_nazw[0]="";
    tablica_nazw[1]="tytul";
    tablica_nazw[2]="przel_funt_brytyjski";
    tablica_nazw[3]="ilosc_funt_brytyjski";
    tablica_nazw[4]="przel_euro";
    tablica_nazw[5]="ilosc_euro";
    tablica_nazw[6]="przel_dolara_amerykanskiego";
    tablica_nazw[7]="ilosc_dolarow_amerykanskich";
    tablica_nazw[8]="przel_innej_waluty";
    tablica_nazw[9]="ilosc_innej_waluty";
    tablica_nazw[10]="scisle_tajne";
    tablica_nazw[11]="pieniadze_obce";
    tablica_nazw[12]="przel_pracy_zarobkowej";
    tablica_nazw[13]="dochod_z_pracy_zarobkowej";
    tablica_nazw[14]="inne_pieniadze_w_zlotowkach";
    tablica_nazw[15]="wszystkie_dostepne_srodki";
}

void MainWindow::init_short_tablica_nazw()
{
    short_tablica_nazw[0]="data";
    short_tablica_nazw[1]="tytul";
    short_tablica_nazw[2]="PFB";
    short_tablica_nazw[3]="IFB";
    short_tablica_nazw[4]="PE";
    short_tablica_nazw[5]="IE";
    short_tablica_nazw[6]="PDA";
    short_tablica_nazw[7]="IDA";
    short_tablica_nazw[8]="PIW";
    short_tablica_nazw[9]="IIW";
    short_tablica_nazw[10]="tajne";
    short_tablica_nazw[11]="PO";
    short_tablica_nazw[12]="PPZ";
    short_tablica_nazw[13]="DPZ";
    short_tablica_nazw[14]="IPZ";
    short_tablica_nazw[15]="WDS";
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


int MainWindow::licz_okejki(double &i)
{
    i=0;

    wybrane_kolumny.clear();
    wybrane_short_tablica_nazw.clear();

    if(ui->check_data->isChecked())//
    {
        i++;
        wybrane_kolumny.push_back(0);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[0]);
    }
    if(ui->chec_tytul->isChecked())//
    {
        i++;
        wybrane_kolumny.push_back(1);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[1]);
    }
    if(ui->check_przelicznik_godzinowy->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(2);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[2]);


    }
    if(ui->check_godziny->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(3);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[3]);


    }
    if(ui->check_przelicznik_milazu_refundowanego->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(4);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[4]);


    }
    if(ui->check_milaz_refundowany->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(5);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[5]);


    }


    if(ui->check_przelicznik_milazu_nierefundowanego->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(6);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[6]);


    }
    if(ui->check_milaz_nierefundowany->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(7);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[7]);


    }
    if(ui->check_przelicznik_czasu->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(8);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[8]);


    }

    if(ui->check_czas->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(9);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[9]);
    }
    if(ui->check_suma_czasu->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(10);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[10]);
    }
    if(ui->check_dochod->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(11);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[11]);
    }
    if(ui->check_przelicznik_taxu_dojazdowego->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(12);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[12]);
    }
    if(ui->check_tax_dojazdowy->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(13);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[13]);
    }
    if(ui->check_inne->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(14);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[14]);


    }
    if(ui->check_zysk->isChecked())
    {
        i++;
        wybrane_kolumny.push_back(15);
        wybrane_short_tablica_nazw.push_back(short_tablica_nazw[15]);
    }


    return i;
}






void MainWindow::on_pushButton_5_clicked()
{
    for(int i=1;i<ui->tableWidget->rowCount();i++)
    {
        if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(i-1,0))->date()>=ui->dateEdit_begin->date() )
         {
             if(static_cast<QDateEdit*>(ui->tableWidget->cellWidget(i-1,0))->date()<=ui->dateEdit_end->date() )
             {
               if(ui->tableWidget->item(i-1,1)->text().contains(ui->lineEdit->text()))
               {
                   ui->tableWidget->setRowHidden(i-1,false);
               }
               else ui->tableWidget->setRowHidden(i-1,true);
             }
             else ui->tableWidget->setRowHidden(i-1,true);
        }
        else ui->tableWidget->setRowHidden(i-1,true);
    }
    aktualizuj_razem();
}
