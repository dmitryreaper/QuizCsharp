#include "generalwindow.h"

//#include "registration.h"
//#include "connect.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("General Window");
    QFont font("Arial", 12, QFont::Bold);

    this->setFixedSize(1280,720);
    QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie(":/img/chill.gif");
    label->setMovie(movie);
    setCentralWidget(label);
    movie->start();

    QLabel *Name = new QLabel("Name: ", this);
    Name->setFont(font);
    Name->resize(50,50);
    Name->move(50,5);
    Name->setStyleSheet("QLabel { color : white; }");
    Name->show();

    QLabel *Level = new QLabel("Level: ", this);
    Level->setFont(font);
    Level->resize(50,50);
    Level->move(200,5);
    Level->setStyleSheet("QLabel { color : white; }");
    Level->show();

    // Создаем новое окно (виджет)
    QWidget *task = new QWidget(this);
    task->setFixedSize(1000, 600);  // Задаем размер
    task->move(150, 100);  // Задаем положение на главном окне
    task->setStyleSheet("background-color: white;");  // Пример стиля

    // Добавляем текстовое поле или любой другой элемент в новый виджет
    QLabel *titletask = new QLabel("Выбор заданий", task);
    titletask->setFont(font);
    titletask->move(450, 5);  // Позиционируем внутри нового окна
    titletask->setStyleSheet("QLabel { color: black; }");

    // Отображаем дочерний виджет
    task->show();

}
