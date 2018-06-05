#ifndef STYLESHEETS_H
#define STYLESHEETS_H
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class StyleSheets
{
public:
    StyleSheets();
    static QString getDate()
    {
        QDate currentDate = QDate::currentDate();
        QDate date(2018,6,1); // 1 июня 2018
        QString full = QString::number(date.toJulianDay() - currentDate.toJulianDay());
        full.append(" дней до старта марафона!");
        return full;
    }
    static void setPressedOrdinary(QPushButton * b)
    {   b->setStyleSheet(
                    "border-style:  outset;"
                    "border-width:  1px;"
                    "border-radius: 5px;"
                    "border-color:  beige;"
                    "min-width:     7em;"
                    "padding:       1px;"
                    "border-color:  rgb(80,80,80);"
                    "min-width: 200;"
                    "max-width: 200;"
                    "min-height: 50;"
                    "max-height: 50;");    }

    static void setReleasedOrdinary(QPushButton * b)
    {   b->setStyleSheet(
                    "background-color: rgb(209, 209, 209);"
                    "border-style: outset;"
                    "border-width: 1px;"
                    "border-radius: 5px;"
                    "border-color: beige;"
                    "min-width: 7em;"
                    "padding: 1px;"
                    "border-color: grey;"
                    "min-width: 200;"
                    "max-width: 200;"
                    "min-height: 50;"
                    "max-height: 50;");    }

    static void setPressedOther(QPushButton * b)
    {    b->setStyleSheet(
                    "border-style:  outset;"
                    "border-width:  1px;"
                    "border-radius: 5px;"
                    "border-color:  beige;"
                    "min-width:     7em;"
                    "padding:       1px;"
                    "border-color:  white;"
                    "color: white");    }
    static void setReleasedOther(QPushButton * b)
    {    b->setStyleSheet(
                    "border-style: outset;"
                    "border-width: 1px;"
                    "border-radius: 5px;"
                    "border-color: beige;"
                    "min-width: 7em;"
                    "padding: 1px;"
                    "border-color: grey;"
                    "color: white;" );    }
};

#endif // STYLESHEETS_H
