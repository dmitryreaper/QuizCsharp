#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "registration.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();  // Конструктор

private slots:

private:
    RegistrationWindow *registrationWindow;

private slots:
    void showAboutProgramm();
    void showAboutDialog();
    void showRegistrationWindow();  // Слот для показа окна регистрации
};

//button
#endif // MAINWINDOW_H
