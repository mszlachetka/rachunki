#ifndef REKORD_H
#define REKORD_H

#include <QWidget>
#include "QDateEdit"
#include "QComboBox"
#include <QString>
#include <QTableWidgetItem>


class Rekord : public QWidget
{
    Q_OBJECT
public:
    explicit Rekord(QWidget *parent = 0);
    QDateEdit *mDate=new QDateEdit;
signals:

public slots:

};

#endif // REKORD_H
