#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "registration.h"
#include "startprogram.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();  // Конструктор

private slots:

private:
    RegistrationWindow *registrationWindow;
    StartWindow *startwindow;

private slots:
    void showAboutProgramm();
    void showAboutDialog();
    void showRegistrationWindow();  // Слоты для показа окна
    void showStartWindow();
};

//button
#endif // MAINWINDOW_H
