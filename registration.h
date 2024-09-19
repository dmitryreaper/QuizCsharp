#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    RegistrationWindow(QWidget *parent = nullptr);

private slots:
    void onRegisterClicked();  // Обработчик регистрации
};
