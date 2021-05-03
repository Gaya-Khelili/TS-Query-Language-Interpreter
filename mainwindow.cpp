#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include <QMainWindow>
#include"secwindow.h"
#include <QMessageBox>
#include "grammar.h"
#include <qDebug>
#include <iostream>
#include <qcustomplot.h>
#include "data.h"
#include "thirdwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_toolButton_triggered(QAction *arg1)
{

}


//this method makes a call system to open a window or we can not recover the data that we will work

int cpt=0;
void MainWindow::on_pushButton_clicked()
{

    Data data;
    QFileInfo file_name= QFileDialog::getOpenFileName(this,tr(" Open File "), "/Users/fares/Desktop/Projetcodeblocks", "Json Files(*.json);;");
    QString file_path = file_name.filePath() ;
    if(file_path!=NULL){
    if(cpt==0){
    data.readDate(file_path);
    cpt++;
    }
    }

  //  QMessageBox::information(this,tr(" Open File "),file_name);
}

void MainWindow::on_toolButton_clicked()
{
    /*
     * Initailized the AST structure
    */


    Ast::Select_stmt AST;
    Result result ;
    std::string str;
    std::string printAst;
    std::string error;
    QString input=ui->textEdit->toPlainText();
    str = input.toUtf8().constData();


        bool r= client::parsing(str,AST,error);

        if(r) {
            client::print(AST,printAst,result);
            QString QprintAst = QString::fromUtf8(printAst.c_str());
            QPalette p = ui->textBrowser_2->palette();
           //  p.setColor(QPalette::Base, Qt::red);
             p.setColor(QPalette::Text, Qt::white);
             ui->textBrowser->setPalette(p);
             ui->textBrowser_2->setPalette(p);
            ui->textBrowser_2->setText("Parsing succedded \n"+QprintAst);


            QString res;
            for(int i=0;i<result.getcolumns().size();i++){
                for(int j=0;j<result.getcolumns().at(i).size();j++){
                           res+=result.getcolumns().at(i).at(j);
                           res+=" ";
                }
                res+="\n";

            }
            QPalette p1 = ui->textBrowser->palette();
           //  p.setColor(QPalette::Base, Qt::red);
             p.setColor(QPalette::Text, Qt::white);
             ui->textBrowser->setPalette(p1);
             ui->textBrowser->setText(res);
             QCustomPlot* customPlot = new QCustomPlot();
             customPlot->setFixedSize(700,700);

            QVector<double> x(251), y0(251), y1(251);
            for(int i=0;i<result.getcolumns().size();i++){
                customPlot->addGraph();
                customPlot->legend->setVisible(true);
                customPlot->legend->setFont(QFont("Helvetica", 9));
                QPen pen;
                QStringList lineNames;
                lineNames << "Sid1" << "Sid2" << "Sid3" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
                pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));

                customPlot->graph()->setPen(pen);
                customPlot->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
                customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);
                customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

                //customPlot->graph(i)->setBrush(QBrush(QColor(0, 0, 255, 20)));
                for(int j=0;j<result.getcolumns().at(i).size();j++){
                    if(result.getcolumns().at(i).at(j)=="Paris" || result.getcolumns().at(i).at(j)=="Berlin" || result.getcolumns().at(i).at(j)=="Car" ||
                            result.getcolumns().at(i).at(j)=="Technology" || result.getcolumns().at(i).at(j)=="Fashion"    ){

                    }else{
                        x[j] =  j+1;
                        y0[j] =  result.getcolumns().at(i).at(j).toDouble();

                    }

                }
                customPlot->graph(i)->setData(x, y0);

                  customPlot->graph()->rescaleAxes(true);

                // zoom out a bit:
                customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
                customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
                // set blank axis lines:
                customPlot->xAxis->setTicks(false);
                customPlot->yAxis->setTicks(true);
                customPlot->xAxis->setTickLabels(false);
                customPlot->yAxis->setTickLabels(true);
                // make top right axes clones of bottom left axes:
                customPlot->axisRect()->setupFullAxesBox();
                customPlot->show();



          }








          } else {
            QPalette p = ui->textBrowser_2->palette();
           //  p.setColor(QPalette::Base, Qt::red);
             p.setColor(QPalette::Text, Qt::white);
             ui->textBrowser->setPalette(p);
             ui->textBrowser_2->setPalette(p);
            QString Qerror = QString::fromUtf8(error.c_str());
             ui->textBrowser_2->setText("Parsing failed " + Qerror);
        }



    //CodeReaten is a String that contains all the user's request reaten

    //this part of the code gets the text written in the text box
   // QString CodeReaten = ui->textEdit->toPlainText();




    //this part opens a new window where the graph is displayed
   /* SecWindow sec;
    sec.setModal(true);
    sec.exec();*/
}


void MainWindow::on_actionOpen_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionExecut_triggered()
{
    on_toolButton_clicked();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}







void MainWindow::on_actionHistory_triggered()
{
    thirdWindow third;
    third.setModal(true);
    third.help("History");
    third.exec();

}




void MainWindow::on_textEdit_selectionChanged()
{
    QPalette p = ui->textEdit->palette();
     p.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(p);
}



void MainWindow::on_actionContext_triggered()
{
    thirdWindow third;
    third.setModal(true);
    third.help("context");
    third.exec();

}

void MainWindow::on_actionexemples_derequetes_triggered()
{
    thirdWindow third;
    third.setModal(true);
    third.help("exemple requetes");
    third.exec();
}
