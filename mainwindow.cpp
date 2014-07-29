#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rekord.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_table();
    init_last_row();

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
      if(i+1==10 || i+1==11 || i+1==15)
      {
      itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
      itm->setBackgroundColor(Qt::lightGray);
      }
 ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,i+1,itm);
   }

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
    aktualizuj_razem();
    }


}






void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->currentItem()->setText(ui->tableWidget->item(ui->tableWidget->currentRow(),1
                                                                  )->text()+ui->tableWidget->item(
                                                ui->tableWidget->currentRow(),2)->text());
}

void MainWindow::init_table()
{
    setWindowTitle("Rachunki");
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
       if(i+1==10 || i+1==11 || i+1==15)
       {
       itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
       itm->setBackgroundColor(Qt::lightGray);

       }
  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i+1,itm);
    }

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

    //razem
       aktualizuj_razem();


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
                          ->setText(QString::number(suma_godzin_wszystkich+=ui->tableWidget->item(j,14)->text().toDouble()));
    }

}

