#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connect.h"
#include "registration.h"
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


class GeneralWindow : public QMainWindow {
    Q_OBJECT

public:
    GeneralWindow(QWidget *parent = nullptr);  // Конструктор
    ~GeneralWindow();

private:
    GeneralWindow *generalWindow;
    StartWindow *startwindow;
    RegistrationWindow *regwindow;

private slots:
    void DeleteWindow();
};

#endif // MAINWINDOW_H
