
#include <QList>
#include <QString>
#ifndef COLUMN_H
#define COLUMN_H


class Column
{
public:
    Column();

QList<QString> Opening;
QList<QString> Closing;
QList<QString> Date;
QList<QString> Headquarters;
QList<QString> Industry;
QString col_name;
int sid;
QList<QString> getOpening();
QList<QString> getClosing();
QList<QString> getData();
QList<QString> getHeadquarters();
QList<QString> getIndustry();
QString getCol_name();
int getsid();

void setOpening(QList<QString> Opening);
void setClosing(QList<QString> Closing);
void setData(QList<QString> Date);
void setHeadquarters(QList<QString> Headquarters);
void setIndustry(QList<QString> Industry);
void setCol_name(QString col_name);
void setsid(int sid);
};

#endif // COLUMN_H
