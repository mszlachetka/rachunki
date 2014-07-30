#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rekord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
        QString tablica_nazw[16];//niech bedzie za duzo , nie ma co szukac teraz
        QVector <bool> row_ready;


private slots:

   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void init_table();
    void init_tablica_nazw();

    void zapisz(QString nazwa);
    void wczytaj();

   void on_pushButton_3_clicked();



   void on_pushButton_4_clicked();

   void init_last_row();
   void aktualizuj_razem();

   void sortuj();


    void on_tableWidget_cellChanged(int row, int column);





    void on_actionO_Qt_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
