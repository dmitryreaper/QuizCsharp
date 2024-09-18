#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();  // Конструктор

private slots:
    void showAboutProgramm();
    void showAboutDialog();
    void createButtons();
};

//button
#endif // MAINWINDOW_H
