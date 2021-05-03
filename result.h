#ifndef RESULT_H
#define RESULT_H
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <QList>
#include <column.h>
class Result
{
public:
    Result();

    //getter

     std::string gettable_name();
     bool getall_seqs();
     bool getall_pos();
     std::vector<int> getvalid_seq_ids();
     std::vector<int> getvalid_pos_loctions();
     QList<QStringList> getcolumns();
    //setter
     void settable_name(std::string table_name);
     void setall_seqs(bool all_seqs);
     void setall_pos(bool all_pos);
     void setvalid_seq_ids(std::vector<int> valid_seq_ids);
     void setvalid_pos_loctions(std::vector<int> valid_pos_locations);
     void setcolumns(QList<QStringList> columns);

private:


     std::string table_name;
     bool all_seqs;
     bool all_pos;
     std::vector<int> valid_seq_ids;
     std::vector<int> valid_pos_locations;
     QList<QStringList> columns;

};


#endif // RESULT_H
