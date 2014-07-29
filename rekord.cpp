#include "rekord.h"

Rekord::Rekord(QWidget *parent) :
    QWidget(parent)
{

    this->mDate->date().setDate(QDate::currentDate().year(),QDate::currentDate().month()
            ,QDate::currentDate().daysInMonth());
}
