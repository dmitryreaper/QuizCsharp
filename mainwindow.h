#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();  // Конструктор

private slots:
    void showAboutDialog();  // Слот для отображения окна "О программе"
    void showAboutProgramm();
};

#endif // MAINWINDOW_H
