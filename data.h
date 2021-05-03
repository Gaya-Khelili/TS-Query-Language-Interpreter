#ifndef DATA_H
#define DATA_H
#include <iostream>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonValuePtr>
#include <QJsonValueRefPtr>
#include <QJsonValueRef>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QIODevice>
#include <QByteArray>
#include <QTextStream>
#include <QCoreApplication>
#include <QVariantMap>
#include <QList>


class Data
{
public :
    QString table_name;
    QString Headquarters;
    QString Industry;
    QList<QString> date;
    QList<QString> Opening;
    QList<QString> Closing;



    //static QList<Data> qlist_date;
    Data();


     void readDate(QString filepath);
     QString getTable_name();
     QString getHeadquarters();
     QString getIndustry();
     QList<QString> getDate();
     QList<QString> getOpening();
     QList<QString> getClosing();

     void setTable_name(QString table_name);
     void setHeadquarters(QString Headquarters);
     void setIndustry(QString Industry);
     void setDate( QList<QString> date);
     void setOpening(QList<QString> Opening);
     void setClosing(QList<QString> Closing);


};

#endif // DATA_H
