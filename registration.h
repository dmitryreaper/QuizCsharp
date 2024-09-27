#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMainWindow>

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT;

public:
    RegistrationWindow();

private slots:

    void onRegisterClicked();  // Обработчик регистрации
};
