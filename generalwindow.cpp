#include "generalwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QMovie>

//#include "registration.h"
//#include "connect.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("General Window");
    this->setFixedSize(1280,720);
  //QLabel *label = new QLabel(this);
  //QMovie *movie = new QMovie(":/img/chill.gif");
  //label->setMovie(movie);
  //setCentralWidget(label);
  //movie->start();

    QLabel *Name = new QLabel("Name: ", this);
    Name->resize(50,50);
    Name->move(50,5);
    Name->show();

    QLabel *Level = new QLabel("Level: ", this);
    Level->resize(50,50);
    Level->move(200,5);
    Level->show();
}
