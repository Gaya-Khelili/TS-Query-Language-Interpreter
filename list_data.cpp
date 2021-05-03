#include "list_data.h"
QList<Data> list_data::qlist_date;

list_data::list_data()
{

}
/**
 * @brief list_data::getlistdata
 * @return qlist_date
 * Gets the qlist_date
 */
QList<Data> list_data::getlistdata(){
    return  list_data::qlist_date;

}
/**
 * @brief list_data::setlistdata
 * @param qlist_date_
 * Set the value of qlist_date to the parameter
 */
void list_data::setlistdata(QList<Data> qlist_date_){
   list_data::qlist_date = qlist_date_;

}

