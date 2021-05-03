#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>


thirdWindow::thirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdWindow)
{
    ui->setupUi(this);
}

thirdWindow::~thirdWindow()
{
    delete ui;
}

void thirdWindow::help(QString help)
{
    if(help == "context")
        ui->textBrowser->setText(" This application help to develop a time series query plan description language, "
                                 " including an interpreter that translates a given time series query into a query plan.\n "
                                 " The project is split in four parts.\n"
                                 " Using the aforementioned rules we can now construct the ASTs (or parse trees) for each one of "
                                 " the predefined example queries.  The whole process is the following: \n"
                                 " Tokenizer (lexical analysis) → Parser (syntax analysis) → AST (parse tree) → Query Tree → PDL\n"
                                 " After the AST (parse tree) is constructed, we feed it in the query tree "
                                 " generator that generates a query tree, which in its turn is passed into the query plan generator, "
                                 " which returns the query plan in our domain specific plan description language called TS-PDL.\n"
                                 " For assisting with the comprehension of the grammar, we hereby append the AST for the simplest "
                                 " (Query #1) and the most complex query (Query #5)");
     if(help == "exemple requetes")
        ui->textBrowser->setText("-------------------------Exemple 1 :-------------------------------\n"
                                 "      select  Opening\n  "
                                 "      from Stocks.\n"
                                 "For all series in stocks, bring all the opening values\n"
                                 "-------------------------Exemple 2 :-------------------------------\n"
                                 "      select Opening[15 : 20] \n"
                                 "      FROM Stocks.\n"
                                 "For all series in stocks, bring the opening value between 15 and 20\n"
                                 "-------------------------Exemple 3 :-------------------------------\n"
                                 "      select Opening[15 : 20] > 25\n\n"
                                 "      FROM Stocks.\n"
                                 "For all series in stocks, bring the opening value between Oct15 2018 and Oct20 2018, only if it is larger than 25 \n"
                                 "-------------------------Exemple 4 :-------------------------------\n"
                                 "      select Opening \n"
                                 "      from Stocks\n"
                                 "      for series where all Opening[3 : 10] < 20.\n"
                                 "For all series in stocks that had all their opening values from the Oct3 2018 to Oct10 2018 below 20, bring the opening value\n"
                                 "-------------------------Exemple 5 :-------------------------------\n"
                                 "      select Opening > 25, Headquarters when Closing[15/10/18 : 20/10/18] > 30\n"
                                 "      from Stocks\n"
                                 "      for series where (Industry = “Technology”) \n"
                                                  "and (all Opening[3 : 10] < 20) \n"
                                 "For all series in stocks that belong to the industry “Technology”, and had all their opening values from the Oct3 to the Oct10 \n"
                                 "2018 below 20, bring the opening value and the headquarters, only if the opening value is larger than 25, only for the positions\n"
                                 "for which the Closing value between Oct15 2018 and Oct20 2018 was above 30.\n"

                                 );
     if(help == "History"){

     }
}


