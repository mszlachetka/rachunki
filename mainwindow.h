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


private slots:

   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void init_table();




   void on_pushButton_3_clicked();



   void on_pushButton_4_clicked();

   void init_last_row();
   void aktualizuj_razem();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
