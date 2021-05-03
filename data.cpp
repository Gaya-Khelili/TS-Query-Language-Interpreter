

#include "select.h"
#include "list_data.h"
#include "data.h"
/*QString Data::Headquarters ;
QString Data::Industry;
QString Data::table_name;
QList<QString> Data::date;
QList<QString> Data::Opening;
QList<QString> Data::Closing;*/
//QList<Data> Data::qlist_date;
//QList<Data> list_data::qlist_date;


Data::Data()
{


}
/**
 * @brief Data::readDate
 * @param filepath
 * Reads the data in a Json file by finding it with a given filepath
 */
void Data::readDate(QString filepath){

    QFile file_obj(filepath);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<< "Failed to open "<< filepath;
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc= QJsonDocument::fromJson(json_bytes);

    QJsonObject root_obj = json_doc.object();
    QVariantMap root_map = root_obj.toVariantMap();
    QVariantMap stocks_map = root_map["Stocks"].toMap();

    //QVariantList inv_list = root_map["date"].toList();

    QStringList key_list = stocks_map.keys();




        QList<int> listint;

        for(int i=0;i< key_list.size();i++){


         Data data;
         QString key=key_list.at(i);
         QVariantMap sid_map = stocks_map[key].toMap();
                 data.setTable_name("Stocks");
                 data.setHeadquarters(sid_map["Headquarters"].toString() );

                 data.setIndustry( sid_map["Industry"].toString() );

                 data.setDate(sid_map["opening"].toStringList());

                 data.setOpening( sid_map["opening"].toStringList() );

                 data.setClosing( sid_map["closing"].toStringList());

               list_data::qlist_date.push_back(data);
               qDebug () <<i<< list_data::qlist_date.at(i).Closing ;
               listint.push_back(i);
        }

     qDebug () << listint.at(0) ;

     qDebug () << listint.at(1) ;

     qDebug () << listint.at(2) ;


      // qDebug () <<"list_data sans setli" << list_date.at(1).Opening ;
     qDebug () << list_data::qlist_date.at(1).Opening ;

}

/**
 * @brief Data::getTable_name
 * @return table_name
 * Gets the table_name string from the data
 */
QString Data::getTable_name(){
       return table_name;
}
/**
 * @brief Data::getHeadquarters
 * @return Headquarters
 * Gets the Headquarters string from the data
 */
QString Data::getHeadquarters(){
    return Headquarters;
}
/**
 * @brief Data::getIndustry
 * @return Industry
 * Gets the Industry string from the data
 */
QString Data::getIndustry(){
    return Industry;
}
/**
 * @brief Data::getDate
 * @return date
 * Gets the list of strings "date" from the data
 */
QList<QString> Data::getDate(){
    return date;
}
/**
 * @brief Data::getOpening
 * @return Opening
 * Gets the list of string "Opening" from the data
 */
QList<QString> Data::getOpening(){
    return Opening;
}
/**
 * @brief Data::getClosing
 * @return Closing
 * Gets the list of string "Closing" grom the data
 */
QList<QString> Data::getClosing(){
    return Closing;
}
/**
 * @brief Data::setTable_name
 * @param table_name
 * Sets the value of table_name to the parameter
 */
void Data::setTable_name(QString table_name){
        this->table_name = table_name;
}
/**
 * @brief Data::setHeadquarters
 * @param Headquarters
 * Sets the value of Headquarters to the parameter
 */
void Data::setHeadquarters(QString Headquarters){
        this->Headquarters = Headquarters;
}
/**
 * @brief Data::setIndustry
 * @param Industry
 * Sets the value of Headquarters to the parameter
 */
void Data::setIndustry(QString Industry){
        this->Industry = Industry;
}
/**
 * @brief Data::setDate
 * @param date
 * Sets the value of date to the parameter
 */
void Data::setDate( QList<QString> date){
        this->date = date;
}
/**
 * @brief Data::setOpening
 * @param Opening
 * Sets the value of Opening to the parameter
 */
void Data::setOpening(QList<QString> Opening){
        this->Opening = Opening;
}
/**
 * @brief Data::setClosing
 * @param Closing
 * Sets the value of Closing to the parameter
 */
void Data::setClosing(QList<QString> Closing){
        this->Closing = Closing;
}

