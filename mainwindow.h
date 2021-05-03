#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_toolButton_triggered(QAction *arg1);

    //void Read( QString Filenom);

    void on_toolButton_clicked();



    void on_actionOpen_triggered();

    void on_actionExecut_triggered();

    void on_actionExit_triggered();
    


    

    
    void on_actionHistory_triggered();





    void on_textEdit_selectionChanged();



    void on_actionContext_triggered();

    void on_actionexemples_derequetes_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
