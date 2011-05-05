#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QString>
EditableSqlModel regbd;
int search_id=0;
int del_id=0;

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

void MainWindow::on_action_triggered()
{

    QSqlQueryModel *model= &regbd;
    model->setQuery("select * from journal");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Pages"));

    const QString &title=QObject::tr("Editing");


    static int offset = 0;
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    view->move(100 + offset, 100 + offset);
    offset += 20;
    view->show();



}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model= &regbd;
    model->setQuery("select * from journal");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Pages"));

    const QString &title=QObject::tr("Editing");


    static int offset = 0;
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    view->move(100 + offset, 100 + offset);
    offset += 20;
    view->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    QString add1;
    QString add2;
    QString add3;
    QString zapros;
    add1= ui->textEdit->toPlainText();
    add2= ui->textEdit_2->toPlainText();
    add3= ui->textEdit_3->toPlainText();
    int id=add3.toInt();

    zapros= "insert into journal values ( "+add1 +  ",'" + add2 + "','" + add3+ "')"  ;
    QSqlQueryModel *model= &regbd;
    model->setQuery(zapros);

}




void MainWindow::on_action_2_triggered()
{
    close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString del;
    QString zapros;
    del=ui->textEdit_4->toPlainText();
    if(del_id==1)
    zapros= "DELETE FROM journal WHERE id= '" + del+ "'" ;
    if(del_id==2)
    zapros= "DELETE FROM journal WHERE firstname= '" + del+ "'" ;
    if(del_id==3)
    zapros= "DELETE FROM journal WHERE lastname= '" + del+ "'" ;
    QSqlQueryModel *model= &regbd;
    model->setQuery(zapros);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString search;
    QString zapros;
    search=ui->textEdit_5->toPlainText();
    if(search_id==1)
    zapros= "SELECT * FROM JOURNAL WHERE id ='" +search+"'" ;
    if(search_id==2)
    zapros= "SELECT * FROM JOURNAL WHERE firstname ='" +search+"'" ;
    if(search_id==3)
    zapros= "SELECT * FROM JOURNAL WHERE lastname ='" +search+"'" ;

    QSqlQueryModel *model= &regbd;
    model->setQuery(zapros);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Pages"));
    const QString &title=QObject::tr("Editing");
    static int offset = 0;
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    view->move(100 + offset, 100 + offset);
    offset += 20;
    view->show();

}
void MainWindow::on_radioButton_4_released()
{
    del_id=1;
}

void MainWindow::on_radioButton_5_released()
{
    del_id=2;
}

void MainWindow::on_radioButton_6_released()
{
    del_id=3;
}
void MainWindow::on_radioButton_released()
{
    search_id=1;
}

void MainWindow::on_radioButton_2_released()
{
    search_id=2;
}

void MainWindow::on_radioButton_3_released()
{
    search_id=3;
}
