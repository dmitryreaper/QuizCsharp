#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "registration.h"
#include "connect.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMediaPlayer>
#include <QAudioOutput>
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
    MainWindow(QWidget *parent = nullptr);  // Конструктор
    ~MainWindow();

private:
    RegistrationWindow *registrationWindow;
    StartWindow *startwindow;

private slots:
    void showAboutProgramm();
    void showAboutDialog();
    void showRegistrationWindow();  // Слоты для показа окна
    void showStartWindow();

};

#endif // MAINWINDOW_H
