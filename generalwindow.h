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
#include <QRadioButton>
#include <QProgressBar>

class GeneralWindow : public QMainWindow
{
    Q_OBJECT

public:
    GeneralWindow(const QString &username, QWidget *parent = nullptr);

private:
    QWidget *profileWindow;
    QWidget *achivWindow;
    QWidget *taskWindow;
    QWidget *testwindow;
    QWidget *quiz;
    QWidget *message;
    QWidget *helpWindow;

    //option

private slots:
    void showAboutProg();
    void showAbout();

};

#endif // GENERALWINDOW_H
