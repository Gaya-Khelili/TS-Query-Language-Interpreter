#include "result.h"
#include "iostream"
#include "string.h"
#include <vector>
#include <QList>
#include "column.h"
Result::Result()
{

}
//getter

/**
 * @brief Result::gettable_name
 * @return table_name
 * Gets the value of table_name from Result
 */
std::string Result::gettable_name(){
    return table_name;
}
/**
 * @brief Result::getall_seqs
 * @return all_seqs
 * Gets the value of all_seqs
 */
bool Result::getall_seqs(){
        return all_seqs;
}
/**
 * @brief Result::getall_pos
 * @return all_pos
 * Gets the value of all_pos
 */
bool Result::getall_pos(){
        return all_pos;
}
/**
 * @brief Result::getvalid_seq_ids
 * @return valid_seq_ids
 * Gets the value of valid_seq_ids
 */
std::vector<int> Result::getvalid_seq_ids(){
           return valid_seq_ids;

}
/**
 * @brief Result::getvalid_pos_loctions
 * @return valid_pos_locations
 * Gets the valus of valid_pos_locations
 */
std::vector<int> Result::getvalid_pos_loctions(){
            return valid_pos_locations;
}
/**
 * @brief Result::getcolumns
 * @return columns
 * Gets the valus of columns
 */
QList<QStringList> Result::getcolumns(){
            return columns;
}
//setter
/**
 * @brief Result::settable_name
 * @param table_name
 * Sets the value of table_name to the given parameter
 */
void Result::settable_name(std::string table_name){
    Result::table_name =table_name;
}
/**
 * @brief Result::setall_seqs
 * @param all_seqs
 * Sets the value of all_seqs to the given parameter
 */
void Result::setall_seqs(bool all_seqs){
        Result::all_seqs = all_seqs;
}
/**
 * @brief Result::setall_pos
 * @param all_pos
 * Sets the value of all_pos to the give parameter
 */
void Result::setall_pos( bool all_pos){
           Result::all_pos =all_pos;
}
/**
 * @brief Result::setvalid_seq_ids
 * @param valid_seq_ids
 * Sets the value of valid_seq_ids to the given parameter
 */
void Result::setvalid_seq_ids(std::vector<int> valid_seq_ids){
            Result::valid_seq_ids= valid_seq_ids;
}

/**
 * @brief Result::setvalid_pos_loctions
 * @param valid_seq_ids
 * Sets the value of valid_pos_locations to the given parameter
 */
void Result::setvalid_pos_loctions(std::vector<int> valid_pos_locations)
{
            Result::valid_pos_locations =  valid_pos_locations;
}
/**
 * @brief Result::setcolumns
 * @param columns
 * Sets the value of columns to the given parameter
 */
void Result::setcolumns(QList<QStringList> columns)
{
           Result::columns = columns;
}
