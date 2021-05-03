
#ifndef LIST_DATA_H
#define LIST_DATA_H
#include <QList>
#include <data.h>

class list_data
{
public:
    list_data();
    static QList<Data> qlist_date;
    static QList<Data> getlistdata();
    static void setlistdata(QList<Data> Qlist_date);
};

#endif // LIST_DATA_H

