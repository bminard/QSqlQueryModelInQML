#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QSqlError>

#include "sqlquerymodel.h"

static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        qDebug()<<"Cannot open database\n"
                  "Unable to establish a database connection.\n"
                  "This example needs SQLite support. Please read "
                  "the Qt SQL driver documentation for information how "
                  "to build it.\n\n"
                  "Click Cancel to exit.";
        return false;
    }

    QSqlQuery query;
    if(!query.exec("CREATE TABLE COMPANY("
                   "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "NAME           TEXT    NOT NULL,"
                   "AGE            INT     NOT NULL,"
                   "SALARY         REAL"
                   ")")){
        qDebug()<<query.lastError().text();
    }
    for(int i=0; i < 10; i++){
        query.prepare("insert into COMPANY(NAME, AGE, SALARY) values(:name, :age, :salary)");
        query.bindValue(":name", QString("name-%1").arg(i));
        query.bindValue(":age",  (i+1)*1000);
        query.bindValue(":salary", (11-i)*11.5);
        if(!query.exec()){
            qDebug()<<query.lastError().text();
        }
    }
    return true;
}


int main(int argc, char *argv[])
{
    qmlRegisterType<SqlQueryModel>("Foo", 1, 0, "SqlQueryModel");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    if(!createConnection())
        return -1;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("new_project.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
