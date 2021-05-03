#include "select.h"
#include "result.h"
#include "iostream"
#include "string.h"
#include "vector"
#include "data.h"
#include "list_data.h"
 Result Select::result ;
Select::Select()
{
}
/**
 * @brief Select::open_table
 * @param table_name
 * @return result
 * Has the table name set to the the given one and the two bool variables set to 1
 */
Result Select::open_table(std::string table_name){
    if(table_name == "Stocks"){
        Select::result.settable_name(table_name);
        Select::result.setall_pos( true);
        Select::result.setall_seqs(true);
    }
        return Select::result ;
 }
/**
 * @brief Select::fetch_seq
 * @param column_name
 * @param cur_results
 * @return cur_results
 * It adds the valid column values in a Column object, marks the column object as
 * sequential, and then appends it in the columns vector.
 */
Result Select::fetch_seq(std::string column_name, Result cur_results){
           QList<QStringList> columns;
           QString string;
           QStringList stringlist;
          if(column_name=="Opening"){
              if(cur_results.getall_seqs()==true){
                    for(int i=0;i<list_data::qlist_date.size();i++){
                         columns.append(list_data::qlist_date.at(i).Opening);
                    }
              }
              else{
                     for(int j=0;j<cur_results.getvalid_seq_ids().size();j++){
                                if(cur_results.getvalid_seq_ids().at(j)==1){
                                        columns.append(list_data::qlist_date.at(0).Opening);
                                  }
                                else  if(cur_results.getvalid_seq_ids().at(j)==2){
                                       columns.append(list_data::qlist_date.at(1).Opening);
                                 }
                              else  if(cur_results.getvalid_seq_ids().at(j)==3){
                                        columns.append(list_data::qlist_date.at(2).Opening);
                                 }
                          }
              }
              cur_results.setcolumns(columns);
             // cur_results.setall_seqs(true);
          }
          else  if(column_name=="Closing"){
              if(cur_results.getall_seqs()==true){
                    for(int i=0;i<list_data::qlist_date.size();i++){
                         columns.append(list_data::qlist_date.at(i).Closing);
                    }
              }
              else{
                        for(int j=0;j<cur_results.getvalid_seq_ids().size();j++){
                                if(cur_results.getvalid_seq_ids().at(j)==1){
                                        columns.append(list_data::qlist_date.at(0).Closing);
                                }
                                else  if(cur_results.getvalid_seq_ids().at(j)==2){
                                        columns.append(list_data::qlist_date.at(1).Closing);
                                }
                                else  if(cur_results.getvalid_seq_ids().at(j)==3){
                                        columns.append(list_data::qlist_date.at(2).Closing);
                                }
             }
                }
              cur_results.setcolumns(columns);
              cur_results.setall_seqs(true);
          }
          return cur_results;
}
/**
 * @brief Select::fetch_non_seq
 * @param column_name
 * @param cur_results
 * @return cur_results
 * Adds the valid sequences in the valid_seq_ids vector, it then sets all_seqs to 0.
 */
Result Select::fetch_non_seq(std::string column_name, Result cur_results){
    QStringList list ;
     QList<QStringList> columns;
    if(column_name=="Headquarters"){
        if(cur_results.getall_seqs()==true){
              for(int i=0;i<list_data::qlist_date.size();i++){
                    list.append(list_data::qlist_date.at(i).Headquarters);
              }
        }
        else{
            for(int j=0;j<cur_results.getvalid_seq_ids().size();j++){
                if(cur_results.getvalid_seq_ids().at(j)==1){
                     list.append(list_data::qlist_date.at(0).Headquarters);
                }
                else  if(cur_results.getvalid_seq_ids().at(j)==2){
                    list.append(list_data::qlist_date.at(1).Headquarters);
                }
                else  if(cur_results.getvalid_seq_ids().at(j)==3){
                     list.append(list_data::qlist_date.at(2).Headquarters);
                }
            }
        }
        columns.push_back(list);
        cur_results.setcolumns(columns);
        cur_results.setall_seqs(true);
   }
    else  if(column_name=="Industry"){
        if(cur_results.getall_seqs()==true){
              for(int i=0;i<list_data::qlist_date.size();i++){
                    list.append(list_data::qlist_date.at(i).Industry);
              }
        }
        else{
            for(int j=0;j<cur_results.getvalid_seq_ids().size();j++){
                if(cur_results.getvalid_seq_ids().at(j)==1){
                     list.append(list_data::qlist_date.at(0).Industry);
                }
                else  if(cur_results.getvalid_seq_ids().at(j)==2){
                    list.append(list_data::qlist_date.at(1).Industry);
                }
                else  if(cur_results.getvalid_seq_ids().at(j)==3){
                     list.append(list_data::qlist_date.at(2).Industry);
                }
            }
        }
        columns.push_back(list);
        cur_results.setcolumns(columns);
        cur_results.setall_seqs(true);
        }
    return cur_results;
}
/**
 * @brief Select::filter_positions
 * @param debut
 * @param fin
 * @param cur_results
 * @return cur_results
 * Only for sequences that are specified in the valid_seq_ids (unless if all_seqs is set to
 * 1, where all sequences are valid) the locations of the valid positions (between start and end) are stored in
 * the valid_pos_locations vector. It then sets all_pos to 0.
 */
Result Select::filter_positions(int debut, int fin,Result cur_results){
    QString string;
    QList<QStringList> column;
    int n=0;
    qDebug () << "debut" << debut << "fin" << fin;
    std::vector<int> valid_pos;
    //if(cur_results.getall_seqs()==true){
        for(int i=0;i<cur_results.getcolumns().size();i++){
            QStringList liststring;
            for(int j= debut-1;j<=fin-1;j++){
                    qDebug () << "j dans filter_position" << j ;
                    string = cur_results.getcolumns().at(i).at(j);
                    liststring.insert(j,string);
                    valid_pos.push_back(j);
            }
            column.push_back(liststring);
          }
        cur_results.setvalid_pos_loctions(valid_pos);
        cur_results.setcolumns(column);
     // }
        return cur_results;
}
/**
 * @brief Select::filter_seq
 * @param col_name
 * @param val_min
 * @param val_max
 * @param cur_results
 * @param ok
 * @return cur_results
 * Sets the valid position locations in the valid_pos_locations vector. It then sets all_pos to 0.
 */
Result  Select::filter_seq(std::string col_name, std::string val_min,int val_max, Result cur_results , bool ok) {
    QString string;
    bool seq = true ;
    int cpt=0;
    std::vector<int> seq_valid_seq;
    QList<QStringList> column;
    qDebug() <<  cur_results.getvalid_pos_loctions();
    std::vector<int> valid_pos;
    bool pos=true;
    int n =0;
    if(col_name == "Opening" || col_name == "Closing"){
        if(val_min == ">"){
             if(ok==true){
                 for(int i=0;i<cur_results.getcolumns().size();i++){
                     QStringList liststring;
                     for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                         if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                         string = cur_results.getcolumns().at(i).at(0);
                                         liststring.append(string);
                         }
                          else if(cur_results.getcolumns().at(i).at(j).toInt()>val_max ){
                                   string = cur_results.getcolumns().at(i).at(j);
                                   liststring.append(string);
                                   cpt++;
                                   valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                               }
                     }
                     if(cpt!=cur_results.getcolumns().at(i).size() ){
                         seq=false;
                     }
                     else{
                         qDebug () << "jes usis avant la " << i+1;
                          seq_valid_seq.push_back(i+1);
                     }
                         column.push_back(liststring);
                           cpt=0;
                    }
                    cur_results.setvalid_seq_ids(seq_valid_seq);
                }
             else{
                 //std::vector<int> valid_pos;
                 for(int i=0;i<cur_results.getcolumns().size();i++){
                        qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                     QStringList liststring;
                     for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                         if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                         string = cur_results.getcolumns().at(i).at(0);
                                         liststring.append(string);
                         }
                          else if(cur_results.getcolumns().at(i).at(j).toInt()>val_max ){
                                   string = cur_results.getcolumns().at(i).at(j);
                                   liststring.append(string);
                                   cpt++;
                                   valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                    // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                               }
                     }
                     qDebug () <<  i+1;
                     if(cpt!=0){
                         //seq_valid_seq.push_back(i+1);
                         seq=false;
                     }
                     /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                         seq=false;

                     }

                     else{
                          seq_valid_seq.push_back(i+1);

                     }*/
                         column.push_back(liststring);
                           cpt=0;
                    }
             }
           }
          else  if(val_min == "<"){
            if(ok==true){
                for(int i=0;i<cur_results.getcolumns().size();i++){
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()<val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                              }
                    }
                    if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;
                    }
                    else{
                        qDebug () << "jes usis avant la " << i+1;
                         seq_valid_seq.push_back(i+1);
                    }
                        column.push_back(liststring);
                          cpt=0;
                   }
                   cur_results.setvalid_seq_ids(seq_valid_seq);
               }
            else{
                //std::vector<int> valid_pos;
                for(int i=0;i<cur_results.getcolumns().size();i++){
                       qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()<val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                   // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                              }
                    }
                    qDebug () <<  i+1;
                    if(cpt!=0){
                        //seq_valid_seq.push_back(i+1);
                        seq=false;
                    }
                    /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;

                    }

                    else{
                         seq_valid_seq.push_back(i+1);

                    }*/
                        column.push_back(liststring);
                          cpt=0;
                   }
            }
      }
        else  if(val_min == ">="){
            if(ok==true){
                for(int i=0;i<cur_results.getcolumns().size();i++){
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()>=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                              }
                    }
                    if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;
                    }
                    else{
                        qDebug () << "jes usis avant la " << i+1;
                         seq_valid_seq.push_back(i+1);
                    }
                        column.push_back(liststring);
                          cpt=0;
                   }
                   cur_results.setvalid_seq_ids(seq_valid_seq);
               }
            else{
                //std::vector<int> valid_pos;
                for(int i=0;i<cur_results.getcolumns().size();i++){
                       qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()>=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                   // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                              }
                    }
                    qDebug () <<  i+1;
                    if(cpt!=0){
                        //seq_valid_seq.push_back(i+1);
                        seq=false;
                    }
                    /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;

                    }

                    else{
                         seq_valid_seq.push_back(i+1);

                    }*/
                        column.push_back(liststring);
                          cpt=0;
                   }
            }
      }
        else  if(val_min == "<="){
            if(ok==true){
                for(int i=0;i<cur_results.getcolumns().size();i++){
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()<=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                              }
                    }
                    if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;
                    }
                    else{
                        qDebug () << "jes usis avant la " << i+1;
                         seq_valid_seq.push_back(i+1);
                    }
                        column.push_back(liststring);
                          cpt=0;
                   }
                   cur_results.setvalid_seq_ids(seq_valid_seq);
               }
            else{
                //std::vector<int> valid_pos;
                for(int i=0;i<cur_results.getcolumns().size();i++){
                       qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()<=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                   // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                              }
                    }
                    qDebug () <<  i+1;
                    if(cpt!=0){
                        //seq_valid_seq.push_back(i+1);
                        seq=false;
                    }
                    /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;

                    }

                    else{
                         seq_valid_seq.push_back(i+1);

                    }*/
                        column.push_back(liststring);
                          cpt=0;
                   }
            }
      }
        else  if(val_min == "="){
            if(ok==true){
                for(int i=0;i<cur_results.getcolumns().size();i++){
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()==val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                              }
                    }
                    if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;
                    }
                    else{
                        qDebug () << "jes usis avant la " << i+1;
                         seq_valid_seq.push_back(i+1);
                    }
                        column.push_back(liststring);
                          cpt=0;
                   }
                   cur_results.setvalid_seq_ids(seq_valid_seq);
               }
            else{
                //std::vector<int> valid_pos;
                for(int i=0;i<cur_results.getcolumns().size();i++){
                       qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()==val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                   // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                              }
                    }
                    qDebug () <<  i+1;
                    if(cpt!=0){
                        //seq_valid_seq.push_back(i+1);
                        seq=false;
                    }
                    /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;

                    }

                    else{
                         seq_valid_seq.push_back(i+1);

                    }*/
                        column.push_back(liststring);
                          cpt=0;
                   }
            }
      }
        else  if(val_min == "!="){
            if(ok==true){
                for(int i=0;i<cur_results.getcolumns().size();i++){
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()!=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                              }
                    }
                    if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;
                    }
                    else{
                        qDebug () << "jes usis avant la " << i+1;
                         seq_valid_seq.push_back(i+1);
                    }
                        column.push_back(liststring);
                          cpt=0;
                   }
                   cur_results.setvalid_seq_ids(seq_valid_seq);
               }
            else{
                //std::vector<int> valid_pos;
                for(int i=0;i<cur_results.getcolumns().size();i++){
                       qDebug () << "je suis la " << cur_results.getvalid_seq_ids();
                    QStringList liststring;
                    for(int j=0 ; j< cur_results.getcolumns().at(i).size(); j++){
                        if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                        string = cur_results.getcolumns().at(i).at(0);
                                        liststring.append(string);
                        }
                         else if(cur_results.getcolumns().at(i).at(j).toInt()!=val_max ){
                                  string = cur_results.getcolumns().at(i).at(j);
                                  liststring.append(string);
                                  cpt++;
                                  valid_pos.push_back(cur_results.getvalid_pos_loctions().at(j));
                                   // qDebug () << valid_pos.at(j) << "j dans filter faux" ;
                              }
                    }
                    qDebug () <<  i+1;
                    if(cpt!=0){
                        //seq_valid_seq.push_back(i+1);
                        seq=false;
                    }
                    /*if(cpt!=cur_results.getcolumns().at(i).size() ){
                        seq=false;

                    }

                    else{
                         seq_valid_seq.push_back(i+1);

                    }*/
                        column.push_back(liststring);
                          cpt=0;
                   }
            }
     }
     }
    if(seq==true){
          cur_results.setall_seqs(true);
    }
    else{
           cur_results.setall_seqs(false);
    }
    if(pos==true){
                cur_results.setall_pos(true);
    }
    else{
         cur_results.setall_pos(false);
    }
    qDebug()<<"valid pasition"<< valid_pos;
    cur_results.setvalid_pos_loctions(valid_pos);
    cur_results.setcolumns(column);
    return cur_results;
}
/**
 * @brief Select::filter_non_seq
 * @param col_name
 * @param val_min
 * @param val_max
 * @param cur_results
 * @return cur_results
 * Adds the valid sequences in the valid_seq_ids vector, it then sets all_seqs to 0.
 */
Result Select::filter_non_seq(std::string col_name, std::string val_min, std::string val_max, Result cur_results){
    QString string;
    bool seq=true;
    std::vector<int> seq_valid_seq;
    std::vector<int> pos_valid = cur_results.getvalid_pos_loctions();
    QList<QStringList> column;
    int cpt=0;
    qDebug () << "val_max " <<QString::fromUtf8(val_max.c_str());
    qDebug () << "val_min " <<QString::fromUtf8(val_min.c_str());
     QStringList liststring;
    if(col_name == "Headquarters" || col_name == "Industry"){
          if(val_min == "="){
            for(int i=0;i<cur_results.getcolumns().size();i++){
                for(int j=0 ; j< cur_results.getcolumns().at(i).size() ; j++){
                            if(cur_results.getcolumns().at(i).at(j)==QString::fromUtf8(val_max.c_str()) ){
                                            string = cur_results.getcolumns().at(i).at(j);
                                            liststring.append(string);
                                            cpt++;
                                            seq_valid_seq.push_back(j+1);
                             }
                   }
                if(cpt!=cur_results.getcolumns().at(i).size()){
                    seq=false;
                }
                cpt=0;
                    column.push_back(liststring);
               }
      }
        else  if(val_min == "!="){
            for(int i=0;i<cur_results.getcolumns().size();i++){
                for(int j=0 ; j< cur_results.getcolumns().at(i).size() ; j++){
                            if(cur_results.getcolumns().at(i).at(j) != QString::fromUtf8(val_max.c_str()) ){
                                            string = cur_results.getcolumns().at(i).at(j);
                                            liststring.append(string);
                                            cpt++;
                                            seq_valid_seq.push_back(j+1);
                             }
                   }
                if(cpt!=cur_results.getcolumns().at(i).size() ){
                    seq=false;
                }
                     cpt=0;
                    column.push_back(liststring);
               }
      }
     }
    if(seq==true){
          cur_results.setall_seqs(true);
    }
    else{
           cur_results.setall_seqs(false);
    }
           cur_results.setcolumns(column);
           cur_results.setvalid_seq_ids(seq_valid_seq);
    return cur_results;
}
/**
 * @brief Select::all
 * @param res
 * @param start
 * @param end
 * @return res
 * Updates the seq_ids vector
 */
Result Select::all(Result res, int start, int end){
   /* int cpt=0;
    QString string;
    std::vector<int> seq_valid_seq;
    std::vector<int>   valid_pos;
             for(int i=0;i<res.getcolumns().size();i++){

                 QStringList liststring;

                 for(int j=0 ; j< res.getcolumns().at(i).size(); j++){
                     if(cur_results.getcolumns().at(i).at(0)=="Headquarters " || cur_results.getcolumns().at(i).at(0) == "Industry" ){
                                     string = cur_results.getcolumns().at(i).at(0);
                                     liststring.append(string);
                     }

                      else*/ /*if(res.getcolumns().at(i).at(j).toInt()>val_max ){

                               string = res.getcolumns().at(i).at(j);
                               liststring.append(string);
                               cpt++;
                               valid_pos.push_back(res.getvalid_pos_loctions().at(j));
                                 seq_valid_seq.push_back(i+1);
                           }


                 }


                 if(cpt!=res.getcolumns().at(i).size() ){
                     seq=false;

                 }

                 else{
                      seq_valid_seq.push_back(i+1);

                 }

                     column.push_back(liststring);
                       cpt=0;
                }*/
    return res;
}
/**
 * @brief Select::any
 * @param res
 * @return res
 * It stores in seq_ids, the seq_id of each sequence for which any position is in the
 * valid_pos_locations.
 */
Result Select::any(Result res){
    Result result ;
    QString string;
    QStringList column;
    QList<QStringList> columns;
    if(res.getall_seqs()!=true){
        for(int i =0;i<res.getvalid_seq_ids().size();i++){
            if(res.getvalid_seq_ids().at(i)==1){
             column.append(res.getcolumns().at(0));
            }
            else if(res.getvalid_seq_ids().at(i)==2){
                column.append(res.getcolumns().at(1));
             }
            else if(res.getvalid_seq_ids().at(i)==3){
                column.append(res.getcolumns().at(2));
             }
        }
    }
    columns.push_back(column);
    res.setcolumns(columns);
    return res;
    return result;
}
/**
 * @brief Select::and_function
 * @param res1
 * @param res2
 * @param seqs
 * @return res1
 * Constructs a new result object that contains the logical and of the two vectors (either
 * the seq_ids or the valid_position_locations).
 */
Result Select::and_function(Result res1, Result res2, bool seqs) {
    std::vector<int> valid_seq;
    std::cout <<"and" ;
    if(seqs==true){
        for(int i =0;i<res1.getvalid_seq_ids().size();i++){
            for(int j =0;j<res2.getvalid_seq_ids().size();j++){
                if( res1.getvalid_seq_ids().at(i)==res2.getvalid_seq_ids().at(j)) {
                        valid_seq.push_back(res1.getvalid_seq_ids().at(i));
                }
            }
        }
            res1.setvalid_seq_ids(valid_seq);
    }
    else{
        for(int i =0;i<res1.getvalid_pos_loctions().size();i++){
            for(int j =0;j<res2.getvalid_pos_loctions().size();j++){
                if( res1.getvalid_pos_loctions().at(i)==res2.getvalid_pos_loctions().at(j)) {
                        valid_seq.push_back(res1.getvalid_pos_loctions().at(i));
                }
            }
        }
            res1.setvalid_pos_loctions(valid_seq);


    }

    return res1;
}
/**
 * @brief Select::or_funtion
 * @param res1
 * @param res2
 * @param seqs
 * @return res1
 * Constructs a new result object that contains the logical or of the two vectors (either the
 * seq_ids or the valid_position_locations).
 */
Result Select::or_funtion(Result res1, Result res2, bool seqs){
    std::vector<int> valid_seq;
    std::cout <<"and" ;
    if(seqs==true){
        for(int i =0;i<res1.getvalid_seq_ids().size();i++){
            valid_seq.push_back(res1.getvalid_seq_ids().at(i));
            for(int j =0;j<res2.getvalid_seq_ids().size();j++){
                valid_seq.push_back(res2.getvalid_seq_ids().at(j));
            }
        }

        res1.setvalid_seq_ids(valid_seq);
    }
    else{
        for(int i =0;i<res1.getvalid_pos_loctions().size();i++){
            valid_seq.push_back(res1.getvalid_pos_loctions().at(i));
            for(int j =0;j<res2.getvalid_pos_loctions().size();j++){
                valid_seq.push_back(res2.getvalid_pos_loctions().at(j));
            }
        }

        res1.setvalid_seq_ids(valid_seq);

    }
    return res1;
}
/**
 * @brief Select::add
 * @param res1
 * @param res2
 * @return res1
 * Merge two result objects
 */
Result Select::add(Result res1, Result res2){
   QList<QStringList> columns;
   columns = res1.getcolumns();
   /*std::vector<int> valid_seq=res1.getvalid_seq_ids();
   for(int i=0;i< res2.getvalid_seq_ids().size();i++){
       if(res2.getvalid_seq_ids().at(i)!=NULL){
        valid_seq.push_back(res2.getvalid_seq_ids().at(i));
       }
       else{
           break;
       }

    }
   std::vector<int> valid_pos=res1.getvalid_pos_loctions();
   for(int i=0;i<res2.getvalid_pos_loctions().size() ;i++){
       if(res2.getvalid_pos_loctions().at(i)!=NULL){
        valid_pos.push_back(res2.getvalid_pos_loctions().at(i));
       }
       else {
           break;
       }

    }*/
   for(int i=0;i< res2.getcolumns().size();i++){
        columns.push_back(res2.getcolumns().at(i));
    }
   /*res1.setvalid_seq_ids(valid_seq);
   res1.setvalid_pos_loctions(valid_pos);*/
   res1.setcolumns(columns);
   qDebug()<<res1.getvalid_pos_loctions();
   qDebug()<<res1.getvalid_seq_ids();
    return res1;
}
/**
 * @brief Select::when
 * @param col_name
 * @param res1
 * @param res2
 * @return res2
 * Filters the results woth col_name
 */
Result Select::when(std::string col_name ,Result res1, Result res2){
    QString string;
    QList<QStringList> columns;
   qDebug () << res1.getvalid_pos_loctions() ;
   qDebug () << "result not when" << res2.getvalid_pos_loctions();
   qDebug () << res2.getcolumns().size();
   std::vector<int> valid_correct;
   // if(col_name ==  "Opening" || col_name =="Closing"){
   for(int i=0;i<res1.getvalid_pos_loctions().size();i++){

           for(int j=0 ; j<res2.getvalid_pos_loctions().size();j++){
           if(res1.getvalid_pos_loctions().at(i)==res2.getvalid_pos_loctions().at(j)){
                                 valid_correct.push_back(j);
           }
       }
   }
      for(int i=0;i< res2.getcolumns().size();i++){
            QStringList liststring;
            if(res2.getcolumns().at(i).at(0)=="Paris" || res2.getcolumns().at(i).at(0) == "Berlin" || res2.getcolumns().at(i).at(0) == "Technology" || res2.getcolumns().at(i).at(0) == "Car" || res2.getcolumns().at(i).at(0) == "Fashion"  ){
                            string = res2.getcolumns().at(i).at(0);
                            liststring.append(string);
            }
            else{
                for(int j=0;j<valid_correct.size();j++){
                                    qDebug () << res2.getcolumns().at(i).at(valid_correct.at(j));
                                   string=res2.getcolumns().at(i).at(valid_correct.at(j));
                                   liststring.append(string);
                 }
            }
            columns.push_back(liststring);
    }
    res2.setcolumns(columns);
    return res2;
}
