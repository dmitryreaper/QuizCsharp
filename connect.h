#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMainWindow>


//debug and connect database
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class MainWindow;

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(MainWindow *window);

private slots:
    void onStartClicked();  // Обработчик регистрации

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *emailEdit;
    MainWindow *registration;
};

#endif
