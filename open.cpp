#include "open.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include <QMainWindow>
#include"secwindow.h"
#include <QMessageBox>
#include <QFile>
#include "mainwindow.h"

Open::Open(QWidget *parent) : QMainWindow(parent)
{

}
/**
 * @brief MainWindow::Read
 * @param Filenom
 * Verifies if the file has been read successfully and prints it.
 */
void MainWindow::Read( QString Filenom)
{
    QFile mFile(Filenom);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
       ui->textBrowser_2->setText(" La lecture du fichier non effectuer ");
       return;
    }
    ui->textBrowser_2->setText(" lecture reussie des données ");
    QTextStream in(&mFile);
    QString mText = in.readAll();

    ui->textBrowser->setText(mText);
    mFile.close();
}
