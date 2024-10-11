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
#include <QString>

class GeneralWindow : public QMainWindow
{
    Q_OBJECT

public:
    GeneralWindow(const QString &username, const QString &email, int &scores, QWidget *parent = nullptr);

private:
    QWidget *profileWindow;
    QWidget *achivWindow;
    QWidget *taskWindow;
    QWidget *testwindow;
    QWidget *quiz;
    QWidget *mess;
    QWidget *helpWindow;

    QProgressBar *progressBar;
    QLabel *Level;

    int score;
    QString user;
    QString emai;

public slots:
    void updateScore(int points);
    void saveScoreToDatabase(const QString &username, const QString &email, int score);
    //option

private slots:
    void showAboutProg();
    void showAbout();
};

#endif // GENERALWINDOW_H
