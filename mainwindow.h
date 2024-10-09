#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registration.h"
#include "connect.h"
#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QMovie>

#include <QPixmap>
#include <QLabel>
#include <QPalette>
#include <QBrush>
#include <QResizeEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    RegistrationWindow *registrationWindow;
    StartWindow *startwindow;
    MainWindow *window;

private slots:
    void showAboutProgramm();
    void showAboutDialog();
    void showRegistrationWindow();
    void showStartWindow();
};

#endif
