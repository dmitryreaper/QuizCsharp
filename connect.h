#pragma once

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

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow();

private slots:
    void onStartClicked();  // Обработчик регистрации

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *emailEdit;
};
