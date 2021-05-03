#ifndef GRAMMAR_H
#define GRAMMAR_H
#define BOOST_SPIRIT_DEBUG
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/home/classic/core.hpp>
#include <boost/variant.hpp>
#include <boost/utility.hpp>
#include <boost/fusion/adapted.hpp>
#include <iostream>
#include <string>
#include "mainwindow.h"
#include "select.h"
#include "result.h"
namespace Ast {
    using namespace boost::spirit;
    struct Value_string ;
    struct Value_int;
    /**
     * @brief Value_int_or_string
     * Verifies if the defined value is an int or a string
     * returns 1 for a string and returns 2 for an int
     */
    typedef   boost::variant< boost::recursive_wrapper<Value_string> , boost::recursive_wrapper<Value_int> > Value_int_or_string;
    // the path to variant references_Or_colname
      struct my_visitor6
    : public boost::static_visitor<int>
    {
          /**
     * @brief operator ()
     * @param reff
     * @return 1
     */
    int operator()(const Value_string& reff) const
    {
        return 1;
    }
    /**
     * @brief operator ()
     * @param colname
     * @return 2
     */
    int operator()(const Value_int& colname) const
    {
        return 2;
    }
     };
    struct Col_Reference;
    struct Col_Predicate;
    struct Col_Projection;
    struct References ;
    struct Col_name ;
    /**
     * @brief reference_Or_predicate
     * Verifies if the defined value is a Col_Predicate or a Col_Reference
     * return 1 for a Col_Predicate and 2 for a Col_Reference
     */
    typedef   boost::variant< boost::recursive_wrapper<Col_Reference> , boost::recursive_wrapper<Col_Predicate> > reference_Or_predicate;
    // the path to variant reference_or_predicate
     struct my_visitor5
    : public boost::static_visitor<int>
    {
    int operator()(const Col_Predicate& predicate) const
    {
        return 1;
    }
    int operator()(const Col_Reference& reff) const
    {
        return 2;
    }
    };
     /**
     * @brief references_Or_colname
     * Verifies if the defined value is a References or a Col_name
     * return 1 for a References and 2 for a Col_name
     */
    typedef   boost::variant< boost::recursive_wrapper<References> , boost::recursive_wrapper<Col_name> > references_Or_colname;
    // the path to variant references_Or_colname
      struct my_visitor4
    : public boost::static_visitor<int>
    {
    int operator()(const References& reff) const
    {
        return 1;
    }
    int operator()(const Col_name& colname) const
    {
        return 2;
    }
    };
    //
    struct Seq_and_log_expr;
    struct Seq_or_log_expr;
    struct Seq_all_log_expr;
    struct Seq_any_log_expr;
    /**
     * @brief Seq_Log_Expr
     * Verifies if the defined value is a Col_Predicate or a Seq_and_log_expr or a Seq_or_log_expr or a Seq_all_log_expr
     * or a Seq_any_log_expr.
     * return 1 for a Col_Predicate, 2 for a Seq_and_log_expr, 3 for a Seq_or_log_expr ,4 for a Seq_all_log_expr,
     * 5 for a Seq_any_log_expr.
     */
    typedef   boost::variant< boost::recursive_wrapper<Col_Predicate> , boost::recursive_wrapper<Seq_and_log_expr>
     , boost::recursive_wrapper<Seq_or_log_expr> ,boost::recursive_wrapper<Seq_all_log_expr> ,
      boost::recursive_wrapper<Seq_any_log_expr>  > Seq_Log_Expr;
    // the path to variant
      struct my_visitor3
    : public boost::static_visitor<int>
    {
    int operator()(const Col_Predicate& col_predicate) const
    {
        return 1;
    }
    int operator()(const Seq_and_log_expr& seq_and_log_expr) const
    {
        return 2;
    }
     int operator()(const Seq_or_log_expr& seq_or_log_expr) const
    {
        return 3;
    }
    int operator()(const Seq_all_log_expr& seq_all_log_expr) const
    {
        return 4;
    }
    int operator()(const Seq_any_log_expr& Seq_any_log_expr) const
    {
        return 5;
    }
    };
    struct Pos_and_log_expr;
    struct Pos_or_log_expr;
    /**
     * @brief Pos_Log_Expr
     * Verifies if the defined value is a Col_Predicate or a Pos_and_log_expr or a Pos_or_log.
     * Return 1 for a Col_Predicate , 2 for a Pos_and_log_expr , 3 for a Pos_and_log_expr.
     */
    typedef   boost::variant< boost::recursive_wrapper<Col_Predicate> , boost::recursive_wrapper<Pos_and_log_expr>,boost::recursive_wrapper<Pos_or_log_expr> > Pos_Log_Expr;
        struct my_visitor2
    : public boost::static_visitor<int>
    {
    int operator()(const Col_Predicate& col_predicate) const
    {
        return 1;
    }
    int operator()(const Pos_and_log_expr& pos_and_log_expr) const
    {
        return 2;
    }
       int operator()(const Pos_or_log_expr& pos_or_log_expr) const
    {
        return 3;
    }
    };
       /**
     * @brief Col_projectionOrCol_projection
     * Verifies if the defined value is a Col_projection or a pair of Col_projection
     * Returns 1 for a Col_projection and 2 for a pair of Col_projection
     */
    typedef   boost::variant< boost::recursive_wrapper<Col_Projection> ,boost::recursive_wrapper<std::pair<Col_Projection,Col_Projection>>  > Col_projectionOrCol_projection;
       struct my_visitor1
    : public boost::static_visitor<int>
    {
    int operator()(const Col_Projection& col_projection) const
    {
        return 1;
    }
    int operator()(const  std::pair<Col_Projection,Col_Projection>& pair_col_projection) const
    {
        return 2;
    }
    };
    //  structures for the grammar

     /**
      * @brief The From_stmt struct
      */
     struct From_stmt{
          std::string table_name;
     };
    //project list
     /**
        * @brief The Col_name struct
        */
       struct Col_name{
            std::string col_name;
    };
       /**
     * @brief The References struct
     */
    struct References{
             Col_name col_name;
             int start;
             int endd;
    };
    /**
     * @brief The Col_Reference struct
     */
    struct   Col_Reference{
            references_Or_colname reforcolname;
    };
    /**
     * @brief The Value_string struct
     */
    struct Value_string{
        std::string value;
    };
    /**
     * @brief The Value_int struct
     */
    struct Value_int{
        int value;
    };
    /**
      * @brief The Col_Predicate struct
      */
     struct Col_Predicate{
        Col_Reference col_reference;
        std::string predicate;
        Value_int_or_string variante_value;
    };
    /**
    * @brief The Col_Projection struct
    */
   struct Col_Projection{
            reference_Or_predicate reforpred;
   };
    /**
     * @brief The Project_List struct
     */
    struct Project_List{
        Col_projectionOrCol_projection col_projection;
    };
    /**
      * @brief The Select_project_from struct
      */
     struct  Select_project_from{
             Project_List project_list;
             From_stmt from_stmt;
     };
    // when
     /**
      * @brief The Pos_log_expr struct
      */
   struct Pos_log_expr{
             Pos_Log_Expr pos_log_expr;
     };
     /**
    * @brief The Pos_and_log_expr struct
    */
   struct Pos_and_log_expr{
            Pos_log_expr pos_log_expr;
            Pos_log_expr pos_log_expr2;
   };
     /**
       * @brief The Pos_or_log_expr struct
       */
    struct Pos_or_log_expr{
            Pos_log_expr pos_log_expr;
            Pos_log_expr pos_log_expr2;
    };
    /**
     * @brief The When_Stmt struct
     */
    struct When_Stmt{
            Pos_log_expr pos_log_expr;
    };
     /**
      * @brief The Select_when struct
      */
     struct  Select_when{
        Project_List project_list;
        When_Stmt when_stmt;
        From_stmt from_stmt;
     };
     /**
      * @brief The Seq_log_expr struct
      */
     struct  Seq_log_expr{
         Seq_Log_Expr seq_log_expr;
     };
     /**
      * @brief The Seq_and_log_expr struct
      */
     struct Seq_and_log_expr{
        Ast::Seq_log_expr seq_log_expr;
        Ast::Seq_log_expr seq_log_expr2;
     };
     /**
     * @brief The Seq_or_log_expr struct
     */
    struct Seq_or_log_expr{
          Ast::Seq_log_expr seq_log_expr;
          Ast::Seq_log_expr seq_log_expr2;
    };
    /**
      * @brief The Seq_all_log_expr struct
      */
    struct Seq_all_log_expr{
        Col_Predicate col_predicate;
    };
    /**
     * @brief The Seq_any_log_expr struct
     */
    struct Seq_any_log_expr{
        Col_Predicate col_predicate;
    };
    struct  Select_project_from;
    struct     Select_where;
    struct  Select_when;
    struct Select_when_where;
    /**
     * @brief variante_Select_Stmt
     * Verifies if the defined value is a Select_project_from or a Select_where or a Select_when
     * Return 1 for a Select_project_from , 2 for a Select_where, 3 for a Select_when.
     */
    typedef   boost::variant< boost::recursive_wrapper<Select_project_from> , boost::recursive_wrapper<Select_where>
    ,boost::recursive_wrapper<Select_when>,boost::recursive_wrapper<Select_when_where>  > variante_Select_Stmt;
     struct my_visitor
    : public boost::static_visitor<int>
    {
    int operator()(const Ast::Select_project_from& project_form) const
    {
        return 1;
    }
    int operator()(const Ast::Select_where& where) const
    {
        return 2;
    }
     int operator()(const Ast::Select_when& when) const
    {
        return 3;
    }
    int operator()(const Ast::Select_when_where& when_where) const
    {
        return 4;
    }
    };
     /**
       * @brief The Where_Stmt struct
       */
      struct Where_Stmt{
         Seq_log_expr seq_log_expr;
     };
     /**
      * @brief The Select_where struct
      */
     struct     Select_where{
             Project_List project_list;
             From_stmt from_stmt;
             Where_Stmt where_stmt;
     };
     /**
     * @brief The Select_when_where struct
     */
    struct Select_when_where{
            Project_List project_list;
            When_Stmt when_stmt;
            From_stmt from_stmt;
            Where_Stmt where_stmt;
    };
    struct Select_stmt {
        variante_Select_Stmt select_stmt;
    };
}
// Adapting the structures with grammar
/**
 *  @brief Adapting the structures with the grammar
 *
*/



BOOST_FUSION_ADAPT_STRUCT(Ast::From_stmt,
                            (std::string , table_name)
)
// project_list stmt
BOOST_FUSION_ADAPT_STRUCT(Ast::Col_name,
                          (std::string , col_name)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::References,
                            (Ast::Col_name ,col_name)
                            (int ,start)
                            (int, endd)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Col_Reference,
                             (Ast::references_Or_colname,reforcolname)
)
BOOST_FUSION_ADAPT_STRUCT(Ast::Value_string,
                          (std::string , value)
)
BOOST_FUSION_ADAPT_STRUCT(Ast::Value_int,
                          (int , value)
)
BOOST_FUSION_ADAPT_STRUCT(Ast::Col_Predicate,
                            (Ast::Col_Reference, col_reference)
                            (std::string, predicate)
                            (Ast::Value_int_or_string, variante_value)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Col_Projection,
                          (Ast::reference_Or_predicate , reforpred)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Project_List,
                            ( Ast::Col_projectionOrCol_projection , col_projection)
)
// select stmt
 BOOST_FUSION_ADAPT_STRUCT( Ast::Select_project_from ,
                          (Ast::Project_List, project_list)
                          (Ast::From_stmt, from_stmt)
                         )
//when stmt
BOOST_FUSION_ADAPT_STRUCT( Ast::Pos_log_expr,
            (Ast::Pos_Log_Expr ,pos_log_expr)
)
BOOST_FUSION_ADAPT_STRUCT( Ast::Pos_and_log_expr,
             ( Ast::Pos_log_expr , pos_log_expr)
              ( Ast::Pos_log_expr , pos_log_expr2)
    )
 BOOST_FUSION_ADAPT_STRUCT( Ast::Pos_or_log_expr,
             ( Ast::Pos_log_expr , pos_log_expr)
               ( Ast::Pos_log_expr , pos_log_expr2)
    )
BOOST_FUSION_ADAPT_STRUCT( Ast::When_Stmt,
            (Ast::Pos_log_expr , pos_log_expr)
    )
BOOST_FUSION_ADAPT_STRUCT( Ast::Select_when ,
                          (Ast::Project_List, project_list)
                           (Ast::When_Stmt , when_stmt)
                          (Ast::From_stmt, from_stmt)
                         )
// where stmt
BOOST_FUSION_ADAPT_STRUCT(Ast::Seq_log_expr,
                          (Ast::Seq_Log_Expr ,seq_log_expr)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Seq_and_log_expr ,
                            ( Ast::Seq_log_expr, seq_log_expr)
                          ( Ast::Seq_log_expr, seq_log_expr2)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Seq_or_log_expr,
                              ( Ast::Seq_log_expr , seq_log_expr)
                          ( Ast::Seq_log_expr, seq_log_expr2)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Seq_all_log_expr,
                           ( Ast::Col_Predicate ,col_predicate)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Seq_any_log_expr,
                            ( Ast::Col_Predicate ,col_predicate)
                          )
BOOST_FUSION_ADAPT_STRUCT(Ast::Where_Stmt,
                          (Ast::Seq_log_expr ,seq_log_expr)
                          )
BOOST_FUSION_ADAPT_STRUCT( Ast::Select_where ,
                          (Ast::Project_List, project_list)
                          (Ast::From_stmt, from_stmt)
                          (Ast::Where_Stmt, where_stmt)
                         )
BOOST_FUSION_ADAPT_STRUCT( Ast::Select_when_where ,
                          (Ast::Project_List, project_list)
                          (Ast::When_Stmt , when_stmt)
                          (Ast::From_stmt, from_stmt)
                          (Ast::Where_Stmt, where_stmt)
                         )
BOOST_FUSION_ADAPT_STRUCT( Ast::Select_stmt ,
                          (Ast::variante_Select_Stmt , select_stmt )
                         )
namespace client
{
    using namespace boost::spirit;
    template <typename Iterator>
    /**
     * @brief The sql_parser struct
     */
    struct sql_parser : qi::grammar<Iterator,Ast::Select_stmt(), ascii::space_type> {
          /* initialized our rules */
        //Select stmt
        qi::rule<Iterator , Ast::Select_stmt(),ascii::space_type>  select_stmt;
        qi::rule<Iterator , Ast::Select_project_from(),ascii::space_type>  select_project_from;
        qi::rule<Iterator , Ast::Select_where(),ascii::space_type>  select_where;
        qi::rule<Iterator , Ast::Select_when(),ascii::space_type>  select_when;
        qi::rule<Iterator , Ast::Select_when_where(),ascii::space_type>  select_when_where;
        //all rules of project_list
         qi::rule<Iterator , Ast::From_stmt(), ascii::space_type>  from_stmt;
        qi::rule<Iterator , Ast::Project_List(),ascii::space_type>  project_list;
        qi::rule<Iterator ,  Ast::Col_Projection(),ascii::space_type>  col_projection;
         qi::rule<Iterator ,  std::pair<Ast::Col_Projection,Ast::Col_Projection>(),ascii::space_type> pair_col_projection;
        qi::rule<Iterator ,Ast::Col_Reference() ,ascii::space_type> col_reference;
        qi::rule<Iterator , Ast::Col_name (),ascii::space_type>  col_name;
        qi::rule<Iterator , int  () ,ascii::space_type> start;
        qi::rule<Iterator , int () ,ascii::space_type> endd;
        qi::rule<Iterator , Ast::Value_int_or_string (),ascii::space_type> value;
        qi::rule<Iterator , Ast::Value_int (),ascii::space_type> value_int;
        qi::rule<Iterator , Ast::Value_string (),ascii::space_type> value_string;
        qi::rule<Iterator ,  Ast::Col_Predicate() ,ascii::space_type> col_predicate;
        qi::rule<Iterator ,  Ast::References () ,ascii::space_type> references;
        qi::rule<Iterator , std::string() ,ascii::space_type> predicate;
        qi::rule<Iterator,  std::string() ,ascii::space_type> alphanum;
        //all rules of from_stmt
        qi::rule<Iterator , std::string () ,ascii::space_type>  table_name;
        //all rules of where_stmt
        qi::rule<Iterator , Ast::Where_Stmt (),ascii::space_type>  where_stmt;
        qi::rule<Iterator , Ast::Seq_log_expr (),ascii::space_type>  seq_log_expr;
        qi::rule<Iterator , Ast::Seq_and_log_expr (),ascii::space_type>  seq_and_log_expr;
        qi::rule<Iterator , Ast::Seq_or_log_expr (),ascii::space_type>  seq_or_log_expr;
        qi::rule<Iterator , Ast::Seq_all_log_expr (),ascii::space_type>  seq_all_log_expr;
        qi::rule<Iterator , Ast::Seq_any_log_expr (),ascii::space_type>  seq_any_log_expr;
        //all rules of when
        qi::rule<Iterator , Ast::When_Stmt (),ascii::space_type>  when_stmt;
        qi::rule<Iterator , Ast::Pos_log_expr (),ascii::space_type>  pos_log_expr;
        qi::rule<Iterator , Ast::Pos_and_log_expr (),ascii::space_type>  pos_and_log_expr;
        qi::rule<Iterator , Ast::Pos_or_log_expr (),ascii::space_type>  pos_or_log_expr;
        qi::rule<Iterator,  std::string() ,ascii::space_type> GE;
        qi::rule<Iterator,  std::string() ,ascii::space_type> LE;
        qi::rule<Iterator,  std::string() ,ascii::space_type> NE;
        qi::rule<Iterator,  std::string() ,ascii::space_type> G;
        qi::rule<Iterator,  std::string() ,ascii::space_type> L;
        qi::rule<Iterator,  std::string() ,ascii::space_type> E;
        /**
         * @brief sql_parser
         */
        sql_parser() : sql_parser::base_type(select_stmt) {
      // define the special caractere
        /* define our rules */
        // select
        select_stmt %= select_project_from
            |select_where
            |select_when
            |select_when_where
            ;
        select_project_from %=  "select" >> project_list >> "from" >> from_stmt >> ";" ;
        //project
        using ascii::char_;
        project_list %= ( pair_col_projection ) | (  col_projection ) ;
        pair_col_projection %= ( col_projection >> ',' >> col_projection ) ;
        col_projection %=  (  col_predicate |  col_reference   )   ;
      //  col_predicate
        col_predicate %= col_reference >> predicate  >> value ;
       // col_reference
        col_reference %=( references | col_name );
        references %=
                    ( col_name >> '[' >> start >> ":]"  )
                |     ( col_name >> "[:" >> endd >> ']' )
                |   ( col_name >> '[' >> start >> ':' >> endd >> ']' )  ;
         col_name %=alphanum;
         using qi::int_;
         start %= uint_;
         endd %= uint_;
        // predicate
        predicate %= GE
             |LE
             |NE
             |G
             |L
             |E;
        GE %= ">=";
        LE %= "<=";
        NE %= "!=";
        G %='>';
        L %='<';
        E %='=';
        value %= value_int | value_string ;
        value_int %= uint_;
        value_string %=  "\"" >>  alphanum >> "\"" ;
        // from

        from_stmt %= table_name;
        table_name %= alphanum | ( alphanum >> ',' >> table_name )  ;
        // alphabetic and numeric
         alphanum %= ascii::no_case[qi::lexeme[(ascii::alpha >> *(ascii::alnum | '_'))]];
        //where_stmt
        select_where %=  "select" >> project_list >> "from" >> from_stmt >> "for series where" >> where_stmt >> ";" ;
        where_stmt %=  seq_log_expr ;
        seq_log_expr %= col_predicate
                | seq_all_log_expr
                | seq_any_log_expr
                | seq_and_log_expr
                | seq_or_log_expr
                 ;
        seq_and_log_expr %= "(" >> seq_log_expr >> ")" >> "and" >> "(" >> seq_log_expr >> ")" ;
        seq_or_log_expr %= "(" >> seq_log_expr >> ")" >> "or" >> "(" >> seq_log_expr >> ")" ;
        seq_all_log_expr %= "all"  >> col_predicate  ;
        seq_any_log_expr %= "any" >> col_predicate  ;
        //whene_stmt
        select_when %= "select" >> project_list >> "when" >> when_stmt >> "from" >> from_stmt >> ";" ;
        when_stmt %= pos_log_expr;
        pos_log_expr %=col_predicate
                | pos_and_log_expr
                | pos_or_log_expr
                 ;
        pos_and_log_expr %=  "(" >> pos_log_expr >> ")" >> "and" >> "(" >> pos_log_expr >> ")"  ;
        pos_or_log_expr %=   "(" >> pos_log_expr  >> ")" >> "or"  >> "(" >> pos_log_expr >> ")"  ;
        //project_when_where
        select_when_where %= "select" >> project_list >> "when" >> when_stmt >> "from" >> from_stmt >> "for series where" >> where_stmt >> ";" ;
        //display the nodes
       /* BOOST_SPIRIT_DEBUG_NODES((select_stmt)(project_list)(from_stmt)(where_stmt)(col_projection)(col_predicate)(col_reference)
                                 (predicate)(value)(col_name)(table_name)(alphanum)(seq_log_expr)(seq_and_log_expr)(seq_or_log_expr)
                                 (seq_all_log_expr)(seq_any_log_expr));
        }*/
    }
};
// fonction which parses
    /**
     * @brief Parsing
     * @param str contains the string which would be parsed
     * @param AST the AST which would be filled
     * @return True if the parsing succeeds false if it fails
     */
bool parsing(std::string str, Ast::Select_stmt &AST , std::string &error){
      using boost::spirit::ascii::space;
      typedef std::string::const_iterator iterator_type;
      typedef client::sql_parser<iterator_type> sql_parser;
      //our grammar
        sql_parser s;
        std::string::const_iterator iter = str.begin();
        std::string::const_iterator ends = str.end();
        bool r = phrase_parse(iter, ends, s, space, AST);
        if (iter != ends) {
            error = "Remaining unparsed: '" + std::string(iter, ends) ;
        }
    return r;
}
// fonction which prints the AST
/**
 * @brief Astquery_1_2_3
 * @param AST
 * @param printAst
 */
void Astquery_1_2_3(Ast::Select_stmt &AST,std::string &printAst,Result &result ){
    // query 1 and 2 and 3
                Ast::Select_project_from project_from;
                Ast::Col_Projection colprojection;
                Ast::Col_Predicate pred;
                Ast::Col_Reference reff;
                Ast::References references ;
                Ast::Col_name col_name;
                Ast::Value_int value_int;
                Ast::Value_string value_string;
                int choice2;
                int choice3;
                int choice4;
                int choice5;
                project_from= boost::get<Ast::Select_project_from>(AST.select_stmt);
                   // print name of table name in the AST S
                printAst = "table name : " + project_from.from_stmt.table_name +"\n";
                result = Select::open_table(project_from.from_stmt.table_name);
                Result result3 ;
                choice2 = boost::apply_visitor(Ast::my_visitor1() ,project_from.project_list.col_projection );
                if(choice2 == 1){
                          colprojection = boost::get<Ast::Col_Projection>(project_from.project_list.col_projection );
                          choice3 = boost::apply_visitor(Ast::my_visitor5() ,colprojection.reforpred);
                          //switch between col_reference and col_predicate
                          if(choice3==1){
                                pred= boost::get<Ast::Col_Predicate>(colprojection.reforpred);
                                 choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value );
                                 if(choice5==1){
                                     value_string = boost::get<Ast::Value_string>(pred.variante_value );
                                     printAst+= "value : " + value_string.value  + "\n" ;
                                 }
                                 else if (choice5==2){
                                     value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                     printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                 }
                                 printAst += pred.predicate + "\n";
                                //switch between reference and col_name
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                     printAst+= "col name : " + references.col_name.col_name+"\n" ;
                                     printAst+=  "start : " + std::to_string(references.start) + "\n";
                                     printAst+= "end : " + std::to_string(references.endd) +"\n";
                                     qDebug () <<"je suis dans col_predicate query1 ";
                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(references.col_name.col_name, result);
                                               result = Select::filter_positions(references.start, references.endd,result);
                                               result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,true);
                                     }
                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                qDebug () <<"je susi en bon en droit";
                                                result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                                result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                     }
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                     printAst +=  "col_name : " + col_name.col_name ;
                                     if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(col_name.col_name, result);
                                               result = Select::filter_positions(1,30,result);
                                               result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,true);
                                     }
                                     else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( col_name.col_name,  result);
                                                result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                     }
                                }
                          }
                          else if(choice3==2){
                                reff= boost::get<Ast::Col_Reference>(colprojection.reforpred);
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(reff.reforcolname);
                                    printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst+=  "start : " + std::to_string(references.start) +"\n";
                                    printAst+=  "end : "+ std::to_string(references.endd) +"\n";
                                    if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                              result = Select::fetch_seq(references.col_name.col_name, result);
                                              result = Select::filter_positions(references.start, references.endd,result);
                                    }
                                    else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                               result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                    }
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                     printAst+= "col_name : " +col_name.col_name ;
                                     if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(col_name.col_name, result);
                                     }
                                     else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( col_name.col_name,  result);
                                     }
                                }
                        }
                     }
                    // for seconde col_projection with the vector ( col_projection',' col_projection )
                     else if (choice2 == 2){
                        result3=result;
                         std::pair<Ast::Col_Projection,Ast::Col_Projection> pair_col_projection =boost::get<std::pair<Ast::Col_Projection,Ast::Col_Projection>>(project_from.project_list.col_projection );
                              //  browse the pair
                           // first col projection
                        choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.first.reforpred);
                                  //switch between col_reference and col_predicate
                                if(choice3==1){
                                        pred= boost::get<Ast::Col_Predicate>(pair_col_projection.first.reforpred);
                                        choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                        if(choice5==1){
                                            value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                            printAst+= "value : " + value_string.value  + "\n" ;
                                        }
                                        else if (choice5==2){
                                            value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                            printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                        }
                                        //switch between reference and col_name
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                                            printAst += "start  : " + std::to_string(references.start)  +"\n";
                                             printAst += "end : " + std::to_string(references.endd) + "\n";
                                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                       result = Select::fetch_seq(references.col_name.col_name, result);
                                                       result = Select::filter_positions(references.start, references.endd,result);
                                                       result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,true);
                                             }
                                             else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                        result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                                        result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                             }
                                        }
                                        else if(choice4==2){
                                            col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                            printAst += "col_name : "   + col_name.col_name + "\n" ;
                                            if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                      result = Select::fetch_seq(col_name.col_name, result);
                                                      result = Select::filter_positions(1,30,result);
                                                      result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,true);
                                            }
                                            else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                       result = Select::fetch_non_seq( col_name.col_name,  result);
                                                       result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                            }
                                        }
                                  }
                                  else if(choice3==2){
                                        reff= boost::get<Ast::Col_Reference>(pair_col_projection.first.reforpred);
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(reff.reforcolname);
                                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                                             printAst +=  "start : " + std::to_string(references.start) + "\n";
                                             printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                       result = Select::fetch_seq(references.col_name.col_name, result);
                                                       result = Select::filter_positions(references.start, references.endd,result);
                                             }
                                             else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                        result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                             }
                                        }
                                        else if(choice4==2){
                                            col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                             printAst += "col_name : " +col_name.col_name +"\n";
                                             if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                       result = Select::fetch_seq(col_name.col_name, result);
                                             }
                                             else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                        result = Select::fetch_non_seq( col_name.col_name,  result);
                                             }
                                        }
                                }
                                // seconde col_projection
                                choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.second.reforpred);
                                          //switch between col_reference and col_predicate
                                        if(choice3==1){
                                                pred= boost::get<Ast::Col_Predicate>(pair_col_projection.second.reforpred) ;
                                                choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                                if(choice5==1){
                                                    value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                                    printAst+= "value : " + value_string.value  + "\n" ;
                                                }
                                                else if (choice5==2){
                                                    value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                                    printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                                }
                                                //switch between reference and col_name
                                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                                if(choice4==1){
                                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                                   printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                    printAst += "start  : " + std::to_string(references.start)  +"\n";
                                                     printAst += "end : " + std::to_string(references.endd) + "\n";
                                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                               result3 = Select::fetch_seq(references.col_name.col_name, result3);
                                                               result3 = Select::filter_positions(references.start, references.endd,result3);
                                                               result3 = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result3,true);
                                                     }
                                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                                result3 = Select::fetch_non_seq( references.col_name.col_name,  result3);
                                                                result3 = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result3);
                                                     }
                                                }
                                                else if(choice4==2){
                                                    col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                                    printAst += "col_name : "   + col_name.col_name + "\n" ;
                                                    if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                              result3 = Select::fetch_seq(col_name.col_name, result3);
                                                              result3 = Select::filter_positions(0, 30,result3);
                                                              result3 = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result3,true);
                                                    }
                                                    else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                               result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                                               result3 = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result3);
                                                    }
                                                }
                                          }
                                          else if(choice3==2){
                                                reff= boost::get<Ast::Col_Reference>(pair_col_projection.second.reforpred);
                                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                                if(choice4==1){
                                                     references= boost::get<Ast::References>(reff.reforcolname);
                                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                     printAst +=  "start : " + std::to_string(references.start) + "\n";
                                                     printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                               result3 = Select::fetch_seq(col_name.col_name, result);
                                                               result3 = Select::filter_positions(references.start, references.endd,result3);
                                                     }
                                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                                result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                                     }
                                                }
                                                else if(choice4==2){
                                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                                     printAst += "col_name : " +col_name.col_name +"\n";
                                                     if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                               result3 = Select::fetch_seq(col_name.col_name, result3);
                                                     }
                                                     else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                                result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                                     }
                                                }
                                        }
                                        result = Select::add(result,result3);
                    }
   }
//déclaration des fonctions
void Ast_where_or_expr_left(Ast::Seq_or_log_expr & seq_or_log_expr ,std::string& printAst, Result& result);
void Ast_where_or_expr_right(Ast::Seq_or_log_expr & seq_or_log_expr ,std::string& printAst,Result& result);
void Ast_where_and_expr_right(Ast::Seq_and_log_expr & seq_and_log_expr ,std::string& printAst,Result& result);
/**
 * @brief Ast_where_and_expr
 * @param seq_and_log_expr
 */
void Ast_where_and_expr_left(Ast::Seq_and_log_expr & seq_and_log_expr ,std::string& printAst , Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_or_log_expr seq_or_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice4;
    int choice5;
    int choice3;
    // left and
    choice5 = boost::apply_visitor(Ast::my_visitor3() , seq_and_log_expr.seq_log_expr.seq_log_expr);
    if(choice5==1){
           col_predicate = boost::get<Ast::Col_Predicate>(seq_and_log_expr.seq_log_expr.seq_log_expr);
                    choice4 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                     if(choice4==1){
                              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                              printAst+= "value : " + value_string.value  + "\n" ;
                     }
                     else if (choice4==2){
                              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                      }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                     if(choice3==1){
                              references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                              printAst += "col name : " + references.col_name.col_name+"\n" ;
                              printAst += "start : " + std::to_string(references.start) + "\n";
                              printAst += "end : "+ std::to_string(references.endd) +"\n";
                       }
                      else if(choice3==2){
                               col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                 printAst += "col_name : " +col_name.col_name +"\n";
                                 if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                           result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                                         //  result = Select::all( result ,references.start, references.endd );
                                }
                        }
                      return ;
     }//end of choice==1
    else if(choice5==2){
             seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(seq_and_log_expr.seq_log_expr.seq_log_expr);
             Ast_where_and_expr_right(seq_and_log_expr , printAst , result );
             Result result2;
             Ast_where_and_expr_left(seq_and_log_expr , printAst,result2);
              result = Select::and_function(result, result2, true);
    }//end of choice5==2
    else if(choice5==3){
        seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(seq_or_log_expr.seq_log_expr.seq_log_expr);
        Ast_where_or_expr_left(seq_or_log_expr , printAst,result);
        Result result2;
        Ast_where_or_expr_right(seq_or_log_expr,printAst,result2);
         result = Select::or_funtion(result, result2, true);
    }//end of choice5==3
    else if(choice5==4){
        Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(seq_and_log_expr.seq_log_expr.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                           result = Select::fetch_seq(references.col_name.col_name, result);
                           result = Select::filter_positions(references.start, references.endd,result);
                           result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                         //  result = Select::all( result ,references.start, references.endd );
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end of choice5==4
    else if(choice5==5){
        Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(seq_and_log_expr.seq_log_expr.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_any_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_any_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_any_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end choice5==5
}
    //right and
void Ast_where_and_expr_right(Ast::Seq_and_log_expr & seq_and_log_expr ,std::string& printAst , Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_or_log_expr seq_or_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice4;
    int choice5;
    int choice3;
    choice5 = boost::apply_visitor(Ast::my_visitor3() , seq_and_log_expr.seq_log_expr2.seq_log_expr);
    if(choice5==1){
           col_predicate = boost::get<Ast::Col_Predicate>(seq_and_log_expr.seq_log_expr2.seq_log_expr);
                    choice4 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                     if(choice4==1){
                              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                              printAst+= "value : " + value_string.value  + "\n" ;
                     }
                     else if (choice4==2){
                              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                      }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                     if(choice3==1){
                              references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                              printAst += "col name : " + references.col_name.col_name+"\n" ;
                              printAst += "start : " + std::to_string(references.start) + "\n";
                              printAst += "end : "+ std::to_string(references.endd) +"\n";
                       }
                      else if(choice3==2){
                               col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                 printAst += "col_name : " +col_name.col_name +"\n";
                                 if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                           result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                                         //  result = Select::all( result ,references.start, references.endd );
                                }
                        }
                      return ;
     }//end of choice==1
    else if(choice5==2){
             seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(seq_and_log_expr.seq_log_expr2.seq_log_expr);
             Ast_where_and_expr_right(seq_and_log_expr , printAst , result);
             Result result2;
             Ast_where_and_expr_left(seq_and_log_expr , printAst , result2);
              result = Select::and_function(result, result2, true);
    }//end of choice5==2
    else if(choice5==3){
        seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
        Ast_where_or_expr_left(seq_or_log_expr , printAst,result);
        Result result2;
        Ast_where_or_expr_right(seq_or_log_expr,printAst,result2);
        result = Select::or_funtion(result, result2, true);
    }//end of choice5==3
    else if(choice5==4){
        Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(seq_and_log_expr.seq_log_expr2.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                           result = Select::fetch_seq(references.col_name.col_name, result);
                           result = Select::filter_positions(references.start, references.endd,result);
                            result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                           //  result = Select::all( result ,references.start, references.endd );
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end of choice5==4
    else if(choice5==5){
        Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(seq_and_log_expr.seq_log_expr2.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_any_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_any_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_any_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end choice5==5
}
void Ast_where_or_expr_right(Ast::Seq_or_log_expr & seq_or_log_expr ,std::string& printAst);
//left OR
/**
 * @brief Ast_where_and_expr
 * @param seq_and_log_expr
 */
void Ast_where_or_expr_left(Ast::Seq_or_log_expr & seq_or_log_expr ,std::string& printAst ,Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_and_log_expr seq_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice4;
    int choice5;
    int choice3;
    // left and
    choice5 = boost::apply_visitor(Ast::my_visitor3() , seq_or_log_expr.seq_log_expr.seq_log_expr);
    if(choice5==1){
           col_predicate = boost::get<Ast::Col_Predicate>(seq_or_log_expr.seq_log_expr.seq_log_expr);
                    choice4 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                     if(choice4==1){
                              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                              printAst+= "value : " + value_string.value  + "\n" ;
                     }
                     else if (choice4==2){
                              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                      }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                     if(choice3==1){
                              references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                              printAst += "col name : " + references.col_name.col_name+"\n" ;
                              printAst += "start : " + std::to_string(references.start) + "\n";
                              printAst += "end : "+ std::to_string(references.endd) +"\n";
                       }
                      else if(choice3==2){
                               col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                 printAst += "col_name : " +col_name.col_name +"\n";
                                 if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                           result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                                         //  result = Select::all( result ,references.start, references.endd );
                                }
                        }
                      return ;
     }//end of choice==1
    else if(choice5==2){
             seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(seq_or_log_expr.seq_log_expr.seq_log_expr);
             Ast_where_and_expr_left(seq_and_log_expr , printAst , result);
             Result result2;
             Ast_where_and_expr_right(seq_and_log_expr, printAst ,result2);
             result = Select::and_function(result, result2, true);
    }//end of choice5==2
    else if(choice5==3){
                seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(seq_or_log_expr.seq_log_expr.seq_log_expr);
                Ast_where_or_expr_left(seq_or_log_expr , printAst,result);
                Result result2;
                Ast_where_or_expr_right(seq_or_log_expr,printAst,result2);
                result = Select::or_funtion(result, result2, true);
    }//end of choice5==3
    else if(choice5==4){
        Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(seq_or_log_expr.seq_log_expr.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                           result = Select::fetch_seq(references.col_name.col_name, result);
                           result = Select::filter_positions(references.start, references.endd,result);
                            result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                           //  result = Select::all( result ,references.start, references.endd );
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end of choice5==4
    else if(choice5==5){
        Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(seq_or_log_expr.seq_log_expr.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_any_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_any_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_any_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end choice5==5
}
//Righ OR
/**
 * @brief Ast_where_or_expr_right
 * @param seq_or_log_expr
 * @param printAst
 */
void Ast_where_or_expr_right(Ast::Seq_or_log_expr & seq_or_log_expr ,std::string& printAst , Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_and_log_expr seq_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice4;
    int choice5;
    int choice3;
    // left and
    choice5 = boost::apply_visitor(Ast::my_visitor3() , seq_or_log_expr.seq_log_expr2.seq_log_expr);
    if(choice5==1){
           col_predicate = boost::get<Ast::Col_Predicate>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
                    choice4 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                     if(choice4==1){
                              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                              printAst+= "value : " + value_string.value  + "\n" ;
                     }
                     else if (choice4==2){
                              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                      }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                     if(choice3==1){
                              references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                              printAst += "col name : " + references.col_name.col_name+"\n" ;
                              printAst += "start : " + std::to_string(references.start) + "\n";
                              printAst += "end : "+ std::to_string(references.endd) +"\n";
                       }
                      else if(choice3==2){
                               col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                 printAst += "col_name : " +col_name.col_name +"\n";
                                 if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                           result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                                         //  result = Select::all( result ,references.start, references.endd );
                                }
                        }
                      return ;
     }//end of choice==1
    else if(choice5==2){
             seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
             Ast_where_and_expr_left(seq_and_log_expr , printAst,result);
             Result result2;
             Ast_where_and_expr_right(seq_and_log_expr, printAst,result2);
              result = Select::and_function(result, result2, true);
    }//end of choice5==2
    else if(choice5==3){
                seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
                Ast_where_or_expr_left(seq_or_log_expr , printAst,result);
                Result result2;
                Ast_where_or_expr_right(seq_or_log_expr,printAst,result2);
                 result = Select::or_funtion(result, result2, true);
    }//end of choice5==3
    else if(choice5==4){
        Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                           result = Select::fetch_seq(references.col_name.col_name, result);
                           result = Select::filter_positions(references.start, references.endd,result);
                            result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                           //  result = Select::all( result ,references.start, references.endd );
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end of choice5==4
    else if(choice5==5){
        Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(seq_or_log_expr.seq_log_expr2.seq_log_expr);
                 choice4 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_any_log_expr.col_predicate.variante_value);
                  if(choice4==1){
                           value_string = boost::get<Ast::Value_string>(Seq_any_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice4==2){
                           value_int = boost::get<Ast::Value_int>(Seq_any_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                   }
                  choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                  if(choice3==1){
                           references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                           printAst += "start : " + std::to_string(references.start) + "\n";
                           printAst += "end : "+ std::to_string(references.endd) +"\n";
                    }
                   else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                     }
                   return ;
    }//end choice5==5
}
/**
 * @brief Astquery4
 * @param AST
 * @param printAst
 */
void Astquery4(Ast::Select_stmt &AST,std::string &printAst,Result &result){
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Col_Predicate col_predicate;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_or_log_expr Seq_or_log_expr;
    Ast::Seq_and_log_expr Seq_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
        where= boost::get<Ast::Select_where>(AST.select_stmt);
        //where stmt
        printAst = "Where : \n";
        printAst += where.from_stmt.table_name;
              result = Select::open_table(where.from_stmt.table_name);
               Result result2;
               result2 = Select::open_table(where.from_stmt.table_name);
               Result result3;
        choice2= boost::apply_visitor(Ast::my_visitor3() , where.where_stmt.seq_log_expr.seq_log_expr);
                if(choice2 == 1){
                        col_predicate = boost::get<Ast::Col_Predicate>(where.where_stmt.seq_log_expr.seq_log_expr);
                        choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                        if(choice5==1){
                            value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                            printAst+= "value : " + value_string.value  + "\n" ;
                        }
                        else if (choice5==2){
                            value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                            printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                        }
                         choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                            if(choice3==1){
                                 references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                                 printAst += "col name : " + references.col_name.col_name+"\n" ;
                                 printAst += "start : " + std::to_string(references.start) +"\n";
                                 printAst +=  "end : " + std::to_string(references.endd) +"\n";
                            }
                            else if(choice3==2){
                                col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                  printAst +=  "col_name : " +col_name.col_name +"\n";
                                  if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                            result = Select::fetch_non_seq( col_name.col_name,  result);
                                            result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                                            //result = Select::all( result ,references.start, references.endd );
                                 }
                            }
                }
                else if(choice2==2){
                            Seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(where.where_stmt.seq_log_expr.seq_log_expr);
                            Ast_where_and_expr_left(Seq_and_log_expr,printAst,result);
                            Ast_where_and_expr_right(Seq_and_log_expr,printAst,result2);
                            result = Select::and_function(result, result2, true);
                }
                else if(choice2==3){
                       Seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(where.where_stmt.seq_log_expr.seq_log_expr);
                       Ast_where_or_expr_left(Seq_or_log_expr , printAst,result);
                       Ast_where_or_expr_right(Seq_or_log_expr, printAst,result2);
                       result = Select::or_funtion(result, result2, true);
                }
                 else if(choice2==4){
                         Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(where.where_stmt.seq_log_expr.seq_log_expr);
                         qDebug () << "je susi dans all where";
                         choice5 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                         if(choice5==1){
                             value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                             printAst+= "value : " + value_string.value  + "\n" ;
                         }
                         else if (choice5==2){
                             value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                             printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                         }
                         choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                            if(choice3==1){
                                 references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                                 printAst += "col name : " + references.col_name.col_name+"\n" ;
                                 printAst += "start : "+std::to_string(references.start) +"\n";
                                 printAst += "end : " + std::to_string(references.endd) + "\n";
                                 result = Select::fetch_seq(references.col_name.col_name, result);
                                 result = Select::filter_positions(references.start, references.endd,result);
                                  result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                                 //  result = Select::all( result ,references.start, references.endd );
                            }
                            else if(choice3==2){
                                col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                                printAst += "col_name : " +col_name.col_name +"\n" ;
                            }
                            //if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                          //  }
                }
                else if(choice2==5){
                         Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(where.where_stmt.seq_log_expr.seq_log_expr);
                         choice5 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                         if(choice5==1){
                             value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                             printAst+= "value : " + value_string.value  + "\n" ;
                         }
                         else if (choice5==2){
                             value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                             printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                         }
                         choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                            if(choice3==1){
                                 references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                                 printAst +=  "col name : " + references.col_name.col_name+"\n" ;
                                 printAst +=  "start : " + std::to_string(references.start) +"\n";
                                 printAst +=  "end : " + std::to_string(references.endd) +"\n";
                            }
                            else if(choice3==2){
                                col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                                 printAst +=  "col_name : " +col_name.col_name +"\n";
                            }
                }
        //from stmt
        printAst +="table_name : "+where.from_stmt.table_name+"\n";
        //project_list
        choice2 = boost::apply_visitor(Ast::my_visitor1() ,where.project_list.col_projection );
        if(choice2 == 1){
                colprojection = boost::get<Ast::Col_Projection>(where.project_list.col_projection );
                choice3 = boost::apply_visitor(Ast::my_visitor5() ,colprojection.reforpred);
                          //switch between col_reference and col_predicate
                        if(choice3==1){
                                pred= boost::get<Ast::Col_Predicate>(colprojection.reforpred);
                                choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value );
                                if(choice5==1){
                                    value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                    printAst+= "value : " + value_string.value  + "\n" ;
                                }
                                else if (choice5==2){
                                    value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                    printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                }
                                //switch between reference and col_name
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                   printAst += "col name : " + references.col_name.col_name+"\n" ;
                                    printAst += "start  : " + std::to_string(references.start)  +"\n";
                                     printAst += "end : " + std::to_string(references.endd) + "\n";
                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(references.col_name.col_name, result);
                                               result = Select::filter_positions(references.start, references.endd,result);
                                               result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,true);
                                     }
                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                                result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                     }
                                }
                                else if(choice4==2){
                                    col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                    printAst += "col_name : "   + col_name.col_name + "\n" ;
                                    if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                              result = Select::fetch_seq(col_name.col_name, result);
                                              result = Select::filter_positions(1,30,result);
                                              result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,true);
                                    }
                                    else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                               result = Select::fetch_non_seq(col_name.col_name,  result);
                                               result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                    }
                                }
                          }
                          else if(choice3==2){
                                reff= boost::get<Ast::Col_Reference>(colprojection.reforpred);
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(reff.reforcolname);
                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst +=  "start : " + std::to_string(references.start) + "\n";
                                     printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(references.col_name.col_name, result);
                                               result = Select::filter_positions(references.start, references.endd,result);
                                     }
                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                     }
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                     printAst += "col_name : " +col_name.col_name +"\n";
                                     if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(col_name.col_name, result);
                                     }
                                     else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( col_name.col_name,  result);
                                     }
                                }
                        }
            }
            // for seconde col_projection with the vector ( col_projection',' col_projection )
            else if (choice2 == 2){
            result3 = result;
            std::pair<Ast::Col_Projection,Ast::Col_Projection> pair_col_projection =boost::get<std::pair<Ast::Col_Projection,Ast::Col_Projection>>(where.project_list.col_projection );
             //  browse the pair
                   // first col projection
                choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.first.reforpred);
                          //switch between col_reference and col_predicate
                        if(choice3==1){
                                pred= boost::get<Ast::Col_Predicate>(pair_col_projection.first.reforpred);
                                choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                if(choice5==1){
                                    value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                    printAst+= "value : " + value_string.value  + "\n" ;
                                }
                                else if (choice5==2){
                                    value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                    printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                }
                                //switch between reference and col_name
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                   printAst += "col name : " + references.col_name.col_name+"\n" ;
                                    printAst += "start  : " + std::to_string(references.start)  +"\n";
                                     printAst += "end : " + std::to_string(references.endd) + "\n";
                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(references.col_name.col_name, result);
                                               result = Select::filter_positions(references.start, references.endd,result);
                                               result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,true);
                                     }
                                }
                                else if(choice4==2){
                                    col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                    printAst += "col_name : "   + col_name.col_name + "\n" ;
                                    if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                              result = Select::fetch_seq(col_name.col_name, result);
                                                result = Select::filter_positions(1,30,result);
                                              result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,true);
                                    }
                                    else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                               result = Select::fetch_non_seq(col_name.col_name,  result);
                                               result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                    }
                                }
                          }
                          else if(choice3==2){
                                reff= boost::get<Ast::Col_Reference>(pair_col_projection.first.reforpred);
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(reff.reforcolname);
                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst +=  "start : " + std::to_string(references.start) + "\n";
                                     printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                     if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(references.col_name.col_name, result);
                                               result = Select::filter_positions(references.start, references.endd,result);
                                     }
                                     else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                     }
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                     printAst += "col_name : " +col_name.col_name +"\n";
                                     if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                               result = Select::fetch_seq(col_name.col_name, result);
                                     }
                                     else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                result = Select::fetch_non_seq( col_name.col_name,  result);
                                     }
                                }
                        }
                        // seconde col_projection
                        choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.second.reforpred);
                                  //switch between col_reference and col_predicate
                                if(choice3==1){
                                        pred= boost::get<Ast::Col_Predicate>(pair_col_projection.second.reforpred);
                                        choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                        if(choice5==1){
                                            value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                            printAst+= "value : " + value_string.value  + "\n" ;
                                        }
                                        else if (choice5==2){
                                            value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                            printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                        }
                                        //switch between reference and col_name
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                                            printAst += "start  : " + std::to_string(references.start)  +"\n";
                                             printAst += "end : " + std::to_string(references.endd) + "\n";
                                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                       result3 = Select::fetch_seq(references.col_name.col_name, result3);
                                                       result3 = Select::filter_positions(references.start, references.endd,result3);
                                                       result3 = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result3,true);
                                             }
                                        }
                                        else if(choice4==2){
                                            col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                            printAst += "col_name : "   + col_name.col_name + "\n" ;
                                            if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                      result3 = Select::fetch_seq(col_name.col_name, result3);
                                                      result3 = Select::filter_positions(1,30,result3);
                                                      result3 = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result3,true);
                                            }
                                            else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                       result3 = Select::fetch_non_seq(col_name.col_name,  result3);
                                                       result3 = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result3);
                                            }
                                        }
                                  }
                                  else if(choice3==2){
                                        reff= boost::get<Ast::Col_Reference>(pair_col_projection.second.reforpred);
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(reff.reforcolname);
                                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                                             printAst +=  "start : " + std::to_string(references.start) + "\n";
                                             printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                       result3 = Select::fetch_seq(references.col_name.col_name, result3);
                                                       result3 = Select::filter_positions(references.start, references.endd,result3);
                                             }
                                             else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                        result3 = Select::fetch_non_seq( references.col_name.col_name,  result3);
                                             }
                                        }
                                        else if(choice4==2){
                                            col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                             printAst += "col_name : " +col_name.col_name +"\n";
                                             if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                       result3 = Select::fetch_seq(col_name.col_name, result3);
                                             }
                                             else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                        result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                             }
                                        }
                                }
            result = Select::add( result,  result3);
            }
}
/**
  * @brief AstqueryWhen
  * @param AST
  * @param printAst
  */
//déclaration des fonctions
void Ast_when_and_expr_left(Ast::Pos_or_log_expr & pos_and_log_expr ,std::string& printAst,Result& result,Result& reuslt2);
void Ast_when_and_expr_right(Ast::Pos_and_log_expr & pos_and_log_expr ,std::string& printAst,Result& result_when,Result& reuslt);
void Ast_when_or_expr_left(Ast::Pos_or_log_expr & pos_or_log_expr ,std::string& printAst,Result& result_when,Result& reuslt);
void Ast_when_or_expr_right(Ast::Pos_or_log_expr & pos_or_log_expr ,std::string& printAst,Result& result_when,Result& reuslt);
/**
 * @brief Ast_where_and_expr
 * @param seq_and_log_expr
 */
void Ast_when_and_expr_left(Ast::Pos_and_log_expr & pos_and_log_expr ,std::string& printAst,Result& result,Result& result2){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Pos_or_log_expr pos_or_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice5;
    int choice3;
    choice2 = boost::apply_visitor(Ast::my_visitor2() , pos_and_log_expr.pos_log_expr.pos_log_expr);
    if(choice2==1){
          col_predicate = boost::get<Ast::Col_Predicate>(pos_and_log_expr.pos_log_expr.pos_log_expr);
          choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
          if(choice5==1){
              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
              printAst+= "value : " + value_string.value  + "\n" ;
          }
          else if (choice5==2){
              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
          }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                        if(choice3==1){
                             references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                             printAst += "start : "+ std::to_string(references.start) +"\n";
                             printAst += "end  : "+ std::to_string(references.endd)+"\n";
                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){

                                        result = Select::fetch_seq(references.col_name.col_name, result);
                                        result = Select::filter_positions(references.start, references.endd,result);
                                        result = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result,true);
                                        result = Select::when( references.col_name.col_name , result,  result);
                              }
                        }
                        else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                             printAst += "col_name when : " +col_name.col_name +"\n";
                        }
    }
    else if(choice2==2){
                pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(pos_and_log_expr.pos_log_expr.pos_log_expr);
                 Ast_when_and_expr_left(pos_and_log_expr ,printAst,result,result2);
                 Ast_when_and_expr_right(pos_and_log_expr ,printAst,result,result2);
    }
    else if(choice2==3){
                pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(pos_and_log_expr.pos_log_expr.pos_log_expr);
                Ast_when_or_expr_left(pos_or_log_expr ,printAst,result,result2);
                Ast_when_or_expr_right(pos_or_log_expr ,printAst,result,result2);
    }
}
    //right and
void Ast_when_and_expr_right(Ast::Pos_and_log_expr & pos_and_log_expr, std::string& printAst,Result& result_when,Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Pos_or_log_expr pos_or_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice5;
    int choice3;
    choice2 = boost::apply_visitor(Ast::my_visitor2() , pos_and_log_expr.pos_log_expr2.pos_log_expr);
    if(choice2==1){
          col_predicate = boost::get<Ast::Col_Predicate>(pos_and_log_expr.pos_log_expr2.pos_log_expr);
          choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
          if(choice5==1){
              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
              printAst+= "value : " + value_string.value  + "\n" ;
          }
          else if (choice5==2){
              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
          }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                        if(choice3==1){
                             references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                             printAst += "start : "+ std::to_string(references.start) +"\n";
                             printAst += "end  : "+ std::to_string(references.endd)+"\n";
                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                          qDebug () << "when stmt" << result_when.getall_seqs() << result_when.getvalid_seq_ids();
                                        result_when = Select::fetch_seq(references.col_name.col_name, result_when);
                                        result_when = Select::filter_positions(references.start, references.endd,result_when);
                                        result_when = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result_when,true);
                                        result_when = Select::when( references.col_name.col_name , result_when,  result_when);
                              }
                        }
                        else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                             printAst += "col_name when : " +col_name.col_name +"\n";
                        }
    }
    else if(choice2==2){
                pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(pos_and_log_expr.pos_log_expr2.pos_log_expr);
                 Ast_when_and_expr_left(pos_and_log_expr ,printAst,result_when,result);
                 Ast_when_and_expr_right(pos_and_log_expr ,printAst,result_when,result);
    }
    else if(choice2==3){
                pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(pos_and_log_expr.pos_log_expr2.pos_log_expr);
                Ast_when_or_expr_left(pos_or_log_expr ,printAst,result_when,result);
                Ast_when_or_expr_right(pos_or_log_expr ,printAst,result_when,result);
    }
}
//left OR
/**
 * @brief Ast_where_and_expr
 * @param seq_and_log_expr
 */
void Ast_when_or_expr_left(Ast::Pos_or_log_expr & pos_or_log_expr ,std::string& printAst,Result& result_when,Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Pos_and_log_expr pos_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice5;
    int choice3;
    choice2 = boost::apply_visitor(Ast::my_visitor2() , pos_or_log_expr.pos_log_expr.pos_log_expr);
    if(choice2==1){
          col_predicate = boost::get<Ast::Col_Predicate>(pos_or_log_expr.pos_log_expr.pos_log_expr);
          choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
          if(choice5==1){
              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
              printAst+= "value : " + value_string.value  + "\n" ;
          }
          else if (choice5==2){
              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
          }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                        if(choice3==1){
                             references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                             printAst += "start : "+ std::to_string(references.start) +"\n";
                             printAst += "end  : "+ std::to_string(references.endd)+"\n";
                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                          qDebug () << "when stmt" << result_when.getall_seqs() << result_when.getvalid_seq_ids();
                                        result_when = Select::fetch_seq(references.col_name.col_name, result_when);
                                        result_when = Select::filter_positions(references.start, references.endd,result_when);
                                        result_when = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result_when,true);
                                        result_when = Select::when( references.col_name.col_name , result_when,  result_when);
                              }
                        }
                        else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                             printAst += "col_name when : " +col_name.col_name +"\n";
                        }
    }
    else if(choice2==2){
                pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(pos_or_log_expr.pos_log_expr.pos_log_expr);
                 Ast_when_and_expr_left(pos_and_log_expr ,printAst,result_when,result);
                 Ast_when_and_expr_right(pos_and_log_expr ,printAst,result_when,result);
    }
    else if(choice2==3){
                pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(pos_or_log_expr.pos_log_expr.pos_log_expr);
                Ast_when_or_expr_left(pos_or_log_expr ,printAst,result_when,result);
                Ast_when_or_expr_right(pos_or_log_expr , printAst,result_when,result);
    }
}
//Righ OR
/**
 * @brief Ast_where_or_expr_right
 * @param seq_or_log_expr
 * @param printAst
 */
void Ast_when_or_expr_right(Ast::Pos_or_log_expr & pos_or_log_expr ,std::string& printAst,Result& result_when,Result& result){
    Ast::Col_Predicate col_predicate;
    Ast::Select_where where;
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Pos_and_log_expr pos_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice5;
    int choice3;
    choice2 = boost::apply_visitor(Ast::my_visitor2() , pos_or_log_expr.pos_log_expr2.pos_log_expr);
    if(choice2==1){
          col_predicate = boost::get<Ast::Col_Predicate>(pos_or_log_expr.pos_log_expr2.pos_log_expr);
          choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
          if(choice5==1){
              value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
              printAst+= "value : " + value_string.value  + "\n" ;
          }
          else if (choice5==2){
              value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
          }
                     choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                        if(choice3==1){
                             references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                             printAst += "start : "+ std::to_string(references.start) +"\n";
                             printAst += "end  : "+ std::to_string(references.endd)+"\n";
                             if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                          qDebug () << "when stmt" << result_when.getall_seqs() << result_when.getvalid_seq_ids();
                                        result_when = Select::fetch_seq(references.col_name.col_name, result_when);
                                        result_when = Select::filter_positions(references.start, references.endd,result_when);
                                        result_when = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result_when,true);
                                        result_when = Select::when( references.col_name.col_name , result_when,  result_when);
                              }
                        }
                        else if(choice3==2){
                            col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                             printAst += "col_name when : " +col_name.col_name +"\n";
                        }
    }
    else if(choice2==2){
                pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(pos_or_log_expr.pos_log_expr2.pos_log_expr);
                 Ast_when_and_expr_left(pos_and_log_expr ,printAst,result_when,result);
                 Ast_when_and_expr_right(pos_and_log_expr ,printAst,result_when,result);
    }
    else if(choice2==3){
                pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(pos_or_log_expr.pos_log_expr2.pos_log_expr);
                Ast_when_or_expr_left(pos_or_log_expr ,printAst,result_when,result);
                Ast_when_or_expr_right(pos_or_log_expr , printAst,result_when,result);
    }
}

 void AstqueryWhen( Ast::Select_stmt &AST,std::string &printAst,Result &result){

        Ast::Col_name  col_name;
        Ast::Col_Projection colprojection;
        Ast::Col_Predicate pred;
        Ast::Col_Reference reff;
        Ast::References references ;
        Ast::Col_Predicate col_predicate;
        Ast::Pos_and_log_expr pos_and_log_expr;
        Ast::Pos_or_log_expr pos_or_log_expr;
        Ast::Value_int value_int;
        Ast::Value_string value_string;



        int choice2;
        int choice3;
        int choice4;
        int choice5 ;
        Ast::Select_when when_stmt;
        when_stmt= boost::get<Ast::Select_when>(AST.select_stmt);

        printAst = "Table_name : " + when_stmt.from_stmt.table_name +"\n";
         result = Select::open_table(when_stmt.from_stmt.table_name);
         Result result_and_or =  Select::open_table(when_stmt.from_stmt.table_name);
        choice2 = boost::apply_visitor(Ast::my_visitor1() , when_stmt.project_list.col_projection );
        if(choice2 == 1){
                colprojection = boost::get<Ast::Col_Projection>( when_stmt.project_list.col_projection);

                choice3 = boost::apply_visitor(Ast::my_visitor5() ,colprojection.reforpred);
                          //switch between col_reference and col_predicate
                        if(choice3==1){
                                pred= boost::get<Ast::Col_Predicate>(colprojection.reforpred);
                                choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                if(choice5==1){
                                    value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                    printAst+= "value : " + value_string.value  + "\n" ;
                                }
                                else if (choice5==2){
                                    value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                    printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;

                                }
                                //switch between reference and col_name
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                    printAst += "col name : " + references.col_name.col_name+"\n" ;
                                    printAst +="start  : " +std::to_string(references.start)+"\n";
                                    printAst +="end : "+std::to_string(references.endd)+"\n";
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                    printAst += "col_name : " +col_name.col_name +"\n" ;

                                }
                                if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                          result = Select::fetch_seq(references.col_name.col_name, result);
                                          result = Select::filter_positions(references.start, references.endd,result);


                                          result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,false);
                                }
                                else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                           result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                }

                          }
                          else if(choice3==2){

                                reff= boost::get<Ast::Col_Reference>(colprojection.reforpred);
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(reff.reforcolname);
                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst += "start : "+std::to_string(references.start)+"\n";
                                    printAst += "end : "+ std::to_string(references.endd)+"\n";
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                     printAst += "col_name : " +col_name.col_name +"\n";

                                }
                                if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                          result = Select::fetch_seq(col_name.col_name, result);
                                }
                                else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                }
                        }

            }
                    // for seconde col_projection with the vector ( col_projection',' col_projection )
            else if (choice2 == 2){
            std::pair<Ast::Col_Projection,Ast::Col_Projection> pair_col_projection =boost::get<std::pair<Ast::Col_Projection,Ast::Col_Projection>>(when_stmt.project_list.col_projection );
             //  browse the pair


                   // first col projection
                choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.first.reforpred);
                          //switch between col_reference and col_predicate
                        if(choice3==1){
                                pred= boost::get<Ast::Col_Predicate>(pair_col_projection.first.reforpred);
                                choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                if(choice5==1){
                                    value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                    printAst+= "value : " + value_string.value  + "\n" ;
                                }
                                else if (choice5==2){
                                    value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                    printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;

                                }
                                //switch between reference and col_name
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                   printAst += "col name : " + references.col_name.col_name+"\n" ;
                                    printAst += "start  : " + std::to_string(references.start)  +"\n";
                                     printAst += "end : " + std::to_string(references.endd) + "\n";
                                }
                                else if(choice4==2){
                                    col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                    printAst += "col_name : "   + col_name.col_name + "\n" ;

                                }
                                if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                          result = Select::fetch_seq(references.col_name.col_name, result);
                                          result = Select::filter_positions(references.start, references.endd,result);


                                          result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,false);
                                }
                                else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                           result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                }

                          }
                          else if(choice3==2){

                                reff= boost::get<Ast::Col_Reference>(pair_col_projection.first.reforpred);
                                choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                if(choice4==1){
                                     references= boost::get<Ast::References>(reff.reforcolname);
                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst +=  "start : " + std::to_string(references.start) + "\n";
                                     printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                }
                                else if(choice4==2){
                                    col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                     printAst += "col_name : " +col_name.col_name +"\n";

                                }
                                if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                          result = Select::fetch_seq(col_name.col_name, result);
                                }
                                else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                }
                        }
                        // seconde col_projection
                        choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.second.reforpred);
                                  //switch between col_reference and col_predicate
                                if(choice3==1){
                                        pred= boost::get<Ast::Col_Predicate>(pair_col_projection.second.reforpred);
                                        choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                        if(choice5==1){
                                            value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                            printAst+= "value : " + value_string.value  + "\n" ;
                                        }
                                        else if (choice5==2){
                                            value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                            printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;

                                        }
                                        //switch between reference and col_name
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                                            printAst += "start  : " + std::to_string(references.start)  +"\n";
                                             printAst += "end : " + std::to_string(references.endd) + "\n";
                                        }
                                        else if(choice4==2){
                                            col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                            printAst += "col_name : "   + col_name.col_name + "\n" ;

                                        }
                                        if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                  result = Select::fetch_seq(references.col_name.col_name, result);
                                                  result = Select::filter_positions(references.start, references.endd,result);


                                                  result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,false);
                                        }
                                        else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                   result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                                   result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                        }

                                  }
                                  else if(choice3==2){

                                        reff= boost::get<Ast::Col_Reference>(pair_col_projection.second.reforpred);
                                        choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                        if(choice4==1){
                                             references= boost::get<Ast::References>(reff.reforcolname);
                                             printAst += "col name : " + references.col_name.col_name+"\n" ;
                                             printAst +=  "start : " + std::to_string(references.start) + "\n";
                                             printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                        }
                                        else if(choice4==2){
                                            col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                             printAst += "col_name : " +col_name.col_name +"\n";

                                        }
                                        if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                  result = Select::fetch_seq(col_name.col_name, result);
                                        }
                                        else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                   result = Select::fetch_non_seq( col_name.col_name,  result);
                                        }
                                }

            }

            //when
            printAst += "when : \n";

            choice2 = boost::apply_visitor(Ast::my_visitor2() , when_stmt.when_stmt.pos_log_expr.pos_log_expr);

            if(choice2==1){
                  col_predicate = boost::get<Ast::Col_Predicate>(when_stmt.when_stmt.pos_log_expr.pos_log_expr);
                  choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                  if(choice5==1){
                      value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                      printAst+= "value : " + value_string.value  + "\n" ;
                  }
                  else if (choice5==2){
                      value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                      printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;

                  }
                             choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                                if(choice3==1){
                                     references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                                     printAst += "col name : " + references.col_name.col_name+"\n" ;
                                     printAst += "start : "+ std::to_string(references.start) +"\n";
                                     printAst += "end  : "+ std::to_string(references.endd)+"\n";
                                     result = Select::fetch_seq( references.col_name.col_name,  result);
                                     result = Select::filter_positions(references.start, references.endd,result);


                                     result = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result,true);
                                }
                                else if(choice3==2){
                                    col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                     printAst += "col_name when : " +col_name.col_name +"\n";

                                }

                                 if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                           result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                }
            }

            else if(choice2==2){
                         pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(when_stmt.when_stmt.pos_log_expr.pos_log_expr);
                         Ast_when_and_expr_left(pos_and_log_expr ,printAst,result,result);
                         Ast_when_and_expr_right(pos_and_log_expr ,printAst,result_and_or,result_and_or);
                         result = Select::and_function(result, result_and_or, false);

            }
            else if(choice2==3){

                        pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(when_stmt.when_stmt.pos_log_expr.pos_log_expr);
                        Ast_when_or_expr_left(pos_or_log_expr ,printAst,result,result);
                        Ast_when_or_expr_right(pos_or_log_expr , printAst,result_and_or,result_and_or);
                        result = Select::or_funtion(result, result_and_or, false);
            }
 }

 /**
 * @brief Astquery5
 * @param AST
 * @param printAst
 */
void Astquery5(Ast::Select_stmt &AST,std::string &printAst,Result &result){
    Ast::Col_name  col_name;
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    Ast::Col_Predicate col_predicate;
    Ast::Pos_and_log_expr pos_and_log_expr;
    Ast::Pos_or_log_expr pos_or_log_expr;
    Ast::Seq_any_log_expr Seq_any_log_expr;
    Ast::Seq_all_log_expr Seq_all_log_expr;
    Ast::Seq_or_log_expr Seq_or_log_expr;
    Ast::Seq_and_log_expr Seq_and_log_expr;
    Ast::Value_int value_int;
    Ast::Value_string value_string;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
         Ast::Select_when_where  when_where;
        qDebug () << "req 5 ";
        when_where= boost::get<Ast::Select_when_where>(AST.select_stmt);
           // where
        printAst += "Where  : \n";
        result = Select::open_table(when_where.from_stmt.table_name);
        Result result2;
        result2 = Select::open_table(when_where.from_stmt.table_name);
        Result result3;
        Result result_when;
        Result result_and_or = Select::open_table(when_where.from_stmt.table_name);
        choice2= boost::apply_visitor(Ast::my_visitor3() , when_where.where_stmt.seq_log_expr.seq_log_expr);
              if(choice2 == 1){
                      col_predicate = boost::get<Ast::Col_Predicate>(when_where.where_stmt.seq_log_expr.seq_log_expr);
                      choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                      if(choice5==1){
                          value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                          printAst+= "value : " + value_string.value  + "\n" ;
                      }
                      else if (choice5==2){
                          value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                          printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                      }
                       choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                          if(choice3==1){
                               references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                               printAst += "col name : " + references.col_name.col_name+"\n" ;
                               printAst += "start : " + std::to_string(references.start) +"\n";
                               printAst +=  "end : " + std::to_string(references.endd) +"\n";
                          }
                          else if(choice3==2){
                              col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                printAst +=  "col_name : " +col_name.col_name ;
                                if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                          result = Select::fetch_non_seq( col_name.col_name,  result);
                                          result = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result);
                               }
                           }
              }
              else if(choice2==2){
                  Seq_and_log_expr = boost::get<Ast::Seq_and_log_expr>(when_where.where_stmt.seq_log_expr.seq_log_expr);
                  Ast_where_and_expr_left(Seq_and_log_expr,printAst,result);
                  Ast_where_and_expr_right(Seq_and_log_expr,printAst,result2);
                  qDebug () << "avant all ";
                  result = Select::and_function(result, result2, true);
              }
              else if(choice2==3){
                      Seq_or_log_expr = boost::get<Ast::Seq_or_log_expr>(when_where.where_stmt.seq_log_expr.seq_log_expr);
                      Ast_where_or_expr_left(Seq_or_log_expr , printAst,result);
                      Result result2;
                      Ast_where_or_expr_right(Seq_or_log_expr, printAst,result2);
                      result = Select::or_funtion(result, result2, true);
              }
               else if(choice2==4){
                          Seq_all_log_expr = boost::get<Ast::Seq_all_log_expr>(when_where.where_stmt.seq_log_expr.seq_log_expr);
                          choice5 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_all_log_expr.col_predicate.variante_value);
                          if(choice5==1){
                              value_string = boost::get<Ast::Value_string>(Seq_all_log_expr.col_predicate.variante_value);
                              printAst+= "value : " + value_string.value  + "\n" ;
                          }
                          else if (choice5==2){
                              value_int = boost::get<Ast::Value_int>(Seq_all_log_expr.col_predicate.variante_value );
                              printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                          }
                       choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                          if(choice3==1){
                               references= boost::get<Ast::References>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                               printAst += "col name : " + references.col_name.col_name+"\n" ;
                               printAst += "start : "+std::to_string(references.start) +"\n";
                               printAst += "end : " + std::to_string(references.endd) + "\n";
                               if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                         result = Select::fetch_seq(references.col_name.col_name, result);
                                         result = Select::filter_positions(references.start, references.endd,result);
                                         result = Select::filter_seq(references.col_name.col_name,Seq_all_log_expr.col_predicate.predicate,value_int.value,result,true);
                                         result = Select::all(result, 0, 0);
                               }
                          }
                          else if(choice3==2){
                              col_name= boost::get<Ast::Col_name>(Seq_all_log_expr.col_predicate.col_reference.reforcolname);
                              printAst += "col_name : " +col_name.col_name +"\n";
                          }
              }
              else if(choice2==5){
                       Seq_any_log_expr = boost::get<Ast::Seq_any_log_expr>(when_where.where_stmt.seq_log_expr.seq_log_expr);
                       choice5 =  boost::apply_visitor(Ast::my_visitor6() ,Seq_any_log_expr.col_predicate.variante_value);
                       if(choice5==1){
                           value_string = boost::get<Ast::Value_string>(Seq_any_log_expr.col_predicate.variante_value);
                           printAst+= "value : " + value_string.value  + "\n" ;
                       }
                       else if (choice5==2){
                           value_int = boost::get<Ast::Value_int>(Seq_any_log_expr.col_predicate.variante_value );
                           printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                       }
                       choice3 = boost::apply_visitor(Ast::my_visitor4() ,Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                          if(choice3==1){
                               references= boost::get<Ast::References>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                               printAst +=  "col name : " + references.col_name.col_name+"\n" ;
                               printAst +=  "start : " + std::to_string(references.start) +"\n";
                               printAst +=  "end : " + std::to_string(references.endd) +"\n";
                          }
                          else if(choice3==2){
                              col_name= boost::get<Ast::Col_name>(Seq_any_log_expr.col_predicate.col_reference.reforcolname);
                               printAst +=  "col_name : " +col_name.col_name +"\n" ;
                          }
                          if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                    result = Select::fetch_seq(references.col_name.col_name, result);
                                    result = Select::filter_positions(references.start, references.endd,result);
                                    result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,true);
                          }
                         /* else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                     result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                     result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                          }*/
              }
                //project_list
              //from stmt
              printAst += "Project list \n";
              printAst += "table_name : "+when_where.from_stmt.table_name+"\n";
              result3 = result;
              //project_list
              choice2 = boost::apply_visitor(Ast::my_visitor1() ,when_where.project_list.col_projection );
              if(choice2 == 1){
                      colprojection = boost::get<Ast::Col_Projection>(when_where.project_list.col_projection );
                      choice3 = boost::apply_visitor(Ast::my_visitor5() ,colprojection.reforpred);
                                //switch between col_reference and col_predicate
                              if(choice3==1){
                                      pred= boost::get<Ast::Col_Predicate>(colprojection.reforpred);
                                      choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                      if(choice5==1){
                                          value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                          printAst+= "value : " + value_string.value  + "\n" ;
                                      }
                                      else if (choice5==2){
                                          value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                          printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                      }
                                      //switch between reference and col_name
                                      choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                      if(choice4==1){
                                           references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                         printAst += "col name : " + references.col_name.col_name+"\n" ;
                                          printAst += "start  : " + std::to_string(references.start)  +"\n";
                                           printAst += "end : " + std::to_string(references.endd) + "\n";
                                           if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                     result = Select::fetch_seq(references.col_name.col_name, result);
                                                     result = Select::filter_positions(references.start, references.endd,result);
                                                     result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,false);
                                           }
                                           else if(references.col_name.col_name == "Headquarters" || references.col_name.col_name == "Industry" ){
                                                      result = Select::fetch_non_seq( references.col_name.col_name,  result);
                                                      result = Select::filter_non_seq(references.col_name.col_name,pred.predicate,value_string.value,result);
                                           }
                                      }
                                      else if(choice4==2){
                                          col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                          printAst += "col_name : "   + col_name.col_name + "\n" ;
                                          if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                    result = Select::fetch_seq(col_name.col_name, result);
                                                    result = Select::filter_positions(1, 30,result);
                                                   result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,false);
                                          }
                                          else if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                     result = Select::fetch_non_seq( col_name.col_name,  result);
                                                     result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                          }
                                      }
                                }
                                else if(choice3==2){
                                      reff= boost::get<Ast::Col_Reference>(colprojection.reforpred);
                                      choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                      if(choice4==1){
                                           references= boost::get<Ast::References>(reff.reforcolname);
                                           printAst += "col name : " + references.col_name.col_name+"\n" ;
                                           printAst +=  "start : " + std::to_string(references.start) + "\n";
                                           printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                           result = Select::fetch_seq(references.col_name.col_name, result);
                                           result = Select::filter_positions(references.start, references.endd,result);
                                      }
                                      else if(choice4==2){
                                          col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                           printAst += "col_name : " +col_name.col_name +"\n";
                                           if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                     result = Select::fetch_seq(col_name.col_name, result);
                                                    // result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result);
                                           }
                                           if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                      result = Select::fetch_non_seq( col_name.col_name,  result);
                                           }
                                      }
                              }
                  }
                          // for seconde col_projection with the vector ( col_projection',' col_projection )
                    /**
                     *  for the quiry contain two colone examp Opening[1,2], Headquarters
                     *
                     */
                  else if (choice2 == 2){
                        result3=result;
                        std::pair<Ast::Col_Projection,Ast::Col_Projection> pair_col_projection =boost::get<std::pair<Ast::Col_Projection,Ast::Col_Projection>>(when_where.project_list.col_projection );
                         //  browse the pair
                               // first col projection
                            choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.first.reforpred);
                                      //switch between col_reference and col_predicate
                                    if(choice3==1){
                                            pred= boost::get<Ast::Col_Predicate>(pair_col_projection.first.reforpred);
                                            choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                            if(choice5==1){
                                                value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                                printAst+= "value : " + value_string.value  + "\n" ;
                                            }
                                            else if (choice5==2){
                                                value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                                printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                            }
                                            //switch between reference and col_name
                                            choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                            if(choice4==1){
                                                 references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                               printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                printAst += "start  : " + std::to_string(references.start)  +"\n";
                                                 printAst += "end : " + std::to_string(references.endd) + "\n";
                                                 if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                           result = Select::fetch_seq(references.col_name.col_name, result);
                                                           result = Select::filter_positions(references.start, references.endd,result);
                                                           result = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result,false);
                                                 }
                                            }
                                            else if(choice4==2){
                                                col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                                printAst += "col_name : "   + col_name.col_name + "\n" ;
                                                if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                          result = Select::fetch_non_seq( col_name.col_name,  result);
                                                          result = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result);
                                               }
                                                else  if(col_name.col_name == "Closing" ||col_name.col_name == "Opening" ){
                                                    result = Select::fetch_seq(col_name.col_name, result);
                                                    result = Select::filter_positions(1, 30,result);
                                                     result = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result,false);
                                                }
                                            }
                                      }
                                      else if(choice3==2){
                                            reff= boost::get<Ast::Col_Reference>(pair_col_projection.first.reforpred);
                                            choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                            if(choice4==1){
                                                 references= boost::get<Ast::References>(reff.reforcolname);
                                                 printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                 printAst +=  "start : " + std::to_string(references.start) + "\n";
                                                 printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                                  result = Select::fetch_seq(col_name.col_name, result);
                                                  result = Select::filter_positions(references.start, references.endd,result);
                                            }
                                            else if(choice4==2){
                                                col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                                 printAst += "col_name : " +col_name.col_name +"\n";
                                                 if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                           result = Select::fetch_non_seq( col_name.col_name,  result);
                                                }
                                                 else if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                          result = Select::fetch_seq( col_name.col_name,  result);
                                                 }
                                            }
                                    }
                                    // seconde col_projection
                                    choice3 = boost::apply_visitor(Ast::my_visitor5() ,pair_col_projection.second.reforpred);
                                              //switch between col_reference and col_predicate
                                            if(choice3==1){
                                                    pred= boost::get<Ast::Col_Predicate>(pair_col_projection.second.reforpred);
                                                    choice5 =  boost::apply_visitor(Ast::my_visitor6() ,pred.variante_value);
                                                    if(choice5==1){
                                                        value_string = boost::get<Ast::Value_string>(pred.variante_value);
                                                        printAst+= "value : " + value_string.value  + "\n" ;
                                                    }
                                                    else if (choice5==2){
                                                        value_int = boost::get<Ast::Value_int>(pred.variante_value );
                                                        printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                                                    }
                                                    //switch between reference and col_name
                                                    choice4 = boost::apply_visitor(Ast::my_visitor4() ,pred.col_reference.reforcolname);
                                                    if(choice4==1){
                                                         references= boost::get<Ast::References>(pred.col_reference.reforcolname);
                                                       printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                        printAst += "start  : " + std::to_string(references.start)  +"\n";
                                                         printAst += "end : " + std::to_string(references.endd) + "\n";
                                                         if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                                   result3 = Select::fetch_seq(references.col_name.col_name, result3);
                                                                   result3 = Select::filter_positions(references.start, references.endd,result3);
                                                                   result3 = Select::filter_seq(references.col_name.col_name,pred.predicate,value_int.value,result3,false);
                                                         }
                                                    }
                                                    else if(choice4==2){
                                                        col_name = boost::get<Ast::Col_name>(pred.col_reference.reforcolname);
                                                        printAst += "col_name : "   + col_name.col_name + "\n" ;
                                                        if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                                  result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                                                  result3 = Select::filter_non_seq(col_name.col_name,pred.predicate,value_string.value,result3);
                                                       }
                                                        else if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                                 result3 = Select::fetch_seq( col_name.col_name,  result3);
                                                                 result3 = Select::filter_positions(1, 30,result3);
                                                                 result3 = Select::filter_seq(col_name.col_name,pred.predicate,value_int.value,result3,false);
                                                        }
                                                    }
                                              }
                                              else if(choice3==2){
                                                    reff= boost::get<Ast::Col_Reference>(pair_col_projection.second.reforpred);
                                                    choice4 = boost::apply_visitor(Ast::my_visitor4() ,reff.reforcolname);
                                                    if(choice4==1){
                                                         references= boost::get<Ast::References>(reff.reforcolname);
                                                         printAst += "col name : " + references.col_name.col_name+"\n" ;
                                                         printAst +=  "start : " + std::to_string(references.start) + "\n";
                                                         printAst +=   "end : " + std::to_string(references.endd) + "\n";
                                                         result3 = Select::fetch_seq(col_name.col_name, result3);
                                                         result3 = Select::filter_positions(references.start, references.endd,result3);
                                                    }
                                                    else if(choice4==2){
                                                        col_name= boost::get<Ast::Col_name>(reff.reforcolname);
                                                         printAst += "col_name : " +col_name.col_name +"\n";
                                                         if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                             qDebug () << "on est là" ;
                                                                    result3 = Select::fetch_non_seq( col_name.col_name,  result3);
                                                         }
                                                         else if(col_name.col_name == "Closing" || col_name.col_name == "Opening" ){
                                                                  result3 = Select::fetch_seq( col_name.col_name,  result3);
                                                         }
                                                    }
                                            }
                              result = Select::add(result,result3);
                        }
              //when
              printAst += "when : \n";
             // printAst += "Table_name : " + when_where.from_stmt.table_name +"\n";
              choice2 = boost::apply_visitor(Ast::my_visitor2() , when_where.when_stmt.pos_log_expr.pos_log_expr);
              if(choice2==1){
                    result_when = result;
                    col_predicate = boost::get<Ast::Col_Predicate>(when_where.when_stmt.pos_log_expr.pos_log_expr);
                    choice5 =  boost::apply_visitor(Ast::my_visitor6() ,col_predicate.variante_value);
                    if(choice5==1){
                        value_string = boost::get<Ast::Value_string>(col_predicate.variante_value);
                        printAst+= "value : " + value_string.value  + "\n" ;
                    }
                    else if (choice5==2){
                        value_int = boost::get<Ast::Value_int>(col_predicate.variante_value );
                        printAst+= "value : " + std::to_string(value_int.value)  + "\n" ;
                    }
                               choice3 = boost::apply_visitor(Ast::my_visitor4() ,col_predicate.col_reference.reforcolname);
                                  if(choice3==1){
                                       references= boost::get<Ast::References>(col_predicate.col_reference.reforcolname);
                                       printAst += "col name : " + references.col_name.col_name+"\n" ;
                                       printAst += "start : "+ std::to_string(references.start) +"\n";
                                       printAst += "end : "+ std::to_string(references.endd)+"\n";
                                       if(references.col_name.col_name == "Closing" || references.col_name.col_name == "Opening" ){
                                                    qDebug () << "when stmt" << result_when.getall_seqs() << result_when.getvalid_seq_ids();
                                                  result_when = Select::fetch_seq(references.col_name.col_name, result_when);
                                                  result_when = Select::filter_positions(references.start, references.endd,result_when);
                                                  result_when = Select::filter_seq(references.col_name.col_name,col_predicate.predicate,value_int.value,result_when,true);
                                                  result = Select::when( references.col_name.col_name , result_when,  result);
                                        }
                                  }
                                  else if(choice3==2){
                                      col_name= boost::get<Ast::Col_name>(col_predicate.col_reference.reforcolname);
                                       printAst += "col_name : " +col_name.col_name +"\n" ;
                                       if(col_name.col_name == "Headquarters" || col_name.col_name == "Industry" ){
                                                  result_when = Select::fetch_non_seq( col_name.col_name,  result);
                                                  result_when = Select::filter_non_seq(col_name.col_name,col_predicate.predicate,value_string.value,result_when);
                                       }
                                       else  if(col_name.col_name == "Opening" || col_name.col_name == "Closing" ){
                                           result_when = Select::fetch_seq( col_name.col_name,  result_when);
                                           result_when = Select::filter_seq(col_name.col_name,col_predicate.predicate,value_int.value,result_when,true);
                                }
                                  }
                          //
              }
              else if(choice2==2){

                            pos_and_log_expr = boost::get<Ast::Pos_and_log_expr>(when_where.when_stmt.pos_log_expr.pos_log_expr);
                           Ast_when_and_expr_left(pos_and_log_expr ,printAst,result,result);
                           Ast_when_and_expr_right(pos_and_log_expr ,printAst,result_and_or,result_and_or);
                            result = Select::and_function(result, result_and_or, false);
              }
              else if(choice2==3){
                           pos_or_log_expr = boost::get<Ast::Pos_or_log_expr>(when_where.when_stmt.pos_log_expr.pos_log_expr);
                          Ast_when_or_expr_left(pos_or_log_expr ,printAst,result,result);
                          Ast_when_or_expr_right(pos_or_log_expr , printAst,result_and_or,result_and_or);
                          result = Select::or_funtion(result, result_and_or, false);
              }
 }
/**
 * @brief print
 * @param AST
 * @param printAst
 */
void print( Ast::Select_stmt &AST,std::string &printAst,Result &result){
    // select stmt
    //project list
    Ast::Col_Projection colprojection;
    Ast::Col_Predicate pred;
    Ast::Col_Reference reff;
    Ast::References references ;
    int choice;
    // apply_visitor  switch between our variante
    choice = boost::apply_visitor(Ast::my_visitor() , AST.select_stmt );
                if(choice == 1){
                   Astquery_1_2_3( AST , printAst, result);
                }
                else if(choice == 2){
                    //query 4
                   Astquery4( AST,printAst,result);
                }
                else if(choice == 3){
                    //when query
                   AstqueryWhen( AST,printAst ,result);
                }
                else if(choice == 4){
                    //query 5
                    Astquery5( AST , printAst , result );
                }
}
}// end of namespace client
#endif // GRAMMAR_H
