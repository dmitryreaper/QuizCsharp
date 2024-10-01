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

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT;

public:
    RegistrationWindow();

private slots:

    void onRegisterClicked();  // Обработчик регистрации

private:
    QLineEdit *usernameEdit;
    QLineEdit *emailEdit;
    QLineEdit *passwordEdit;
};
