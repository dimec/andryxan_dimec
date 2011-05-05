#include <QtGui/QApplication>
#include "mainwindow.h"
#include "editablesqlmodel.h"
#include <QtGui>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QLabel>
#include <QApplication>
#include <QTextCodec>

static bool createConnection()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journals.dat");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("create table journal (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into journal values(1, 'Журнал №1', '10')");
    query.exec("insert into journal values(2, 'Журнал №2', '20')");
    query.exec("insert into journal values(3, 'Журнал №3', '30')");
    query.exec("insert into journal values(4, 'Журнал №4', '100')");
    query.exec("insert into journal values(5, 'Журнал №5', '99')");
    query.exec("insert into journal values(6, 'Журнал №6', '55')");


    return true;
}
void initializeModel(QSqlQueryModel *model)
{
    model->setQuery("select * from journal");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Назва"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("К-сть сторінок"));
}

void createView(const QString &title, QSqlQueryModel *model)
{
    static int offset = 0;

    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    view->move(100 + offset, 100 + offset);
    offset += 20;
    view->show();
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    if (!createConnection())
        return 1;

    MainWindow w;



    w.show();
   /* EditableSqlModel regbd;
    initializeModel(&regbd);
    createView(QObject::tr("Editable Query Model"), &regbd); */  //запуск редактора бд



    return a.exec();
}
