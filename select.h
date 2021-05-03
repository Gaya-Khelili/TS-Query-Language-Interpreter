#ifndef SELECT_H
#define SELECT_H
#include "string"
#include "iostream"
#include "result.h"
#include "data.h"
#include "list_data.h"
class Select
{
public:
    Select();
    static Result result ;
    //static list_data list_data;
    static Result open_table(std::string table_name);
    static Result fetch_seq(std::string column_name, Result cur_results);
    static Result filter_positions(int debut, int fin,Result cur_results);
    static Result filter_non_seq(std::string col_name, std::string val_min, std::string val_max, Result cur_results);
    static Result  filter_seq(std::string column_name,std::string val_min, int val_max, Result cur_results,bool ok) ;
    static Result fetch_non_seq(std::string column_name, Result cur_results);
    static Result all(Result res, int start, int end);
    static Result any(Result res);
    static Result and_function(Result res1, Result res2, bool seqs) ;
    static Result or_funtion(Result res1, Result res2, bool seqs);
    static Result add(Result res1,Result res2);
    static Result when(std::string col_name ,Result res1, Result res2);
};
#endif // SELECT_H
