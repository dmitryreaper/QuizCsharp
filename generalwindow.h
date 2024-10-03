// generalwindow.h
#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QProgressBar>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QPixmap>

class GeneralWindow : public QMainWindow
{
    Q_OBJECT

public:
    GeneralWindow(QWidget *parent = nullptr);

private:
    QWidget *profileWindow;
    QWidget *achivWindow;
    QWidget *taskWindow;
    QWidget *testwindow;

private slots:
    void showAboutProg();
    void showAbout();
};

#endif // GENERALWINDOW_H
