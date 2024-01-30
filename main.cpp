#include "widget.h"

#include <QApplication>

#include <QApplication>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QtSql/QSqlError>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");  //连接本地主机
        db.setPort(3306);
        db.setDatabaseName("mysql");
        db.setUserName("root");
        db.setPassword("123456");
        bool ok = db.open();
        if (ok){
            QMessageBox::information(&w, "infor", "link success");
        }
        else {
            QMessageBox::information(&w, "infor", "link failed");
            qDebug()<<"error open database because"<<db.lastError().text();
        }
    return a.exec();
}
