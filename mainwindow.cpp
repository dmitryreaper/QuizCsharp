#include "mainwindow.h"

//#include "registration.h"

// General Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setFixedSize(800,460);
    QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie(":/img/giphy.gif");
    label->setMovie(movie);
    movie->start();

    setCentralWidget(label);

    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu("Файл", this);

    QAction *exitAction = new QAction("Выход", this);

    fileMenu->addSeparator();  // Разделитель
    fileMenu->addAction(exitAction);

    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    menuBar->addMenu(fileMenu);

    QMenu *helpMenu = new QMenu("Справка", this);
    QAction *aboutAction = new QAction("О программе", this);
    QAction *aboutProgramm = new QAction("Справка программы", this);

    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutProgramm);

    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
    connect(aboutProgramm, &QAction::triggered, this, &MainWindow::showAboutProgramm);

    menuBar->addMenu(helpMenu);

    setMenuBar(menuBar);

    QPushButton *sign = new QPushButton("Регистрация", this);
    sign->resize(120,40);
    sign->move(450,220);
    registrationWindow = new RegistrationWindow();
    connect(sign, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);

    //Вход пользователя
    QPushButton *sin = new QPushButton("Войти", this);
    sin->resize(120,40);
    sin->move(250, 220);
    startwindow = new StartWindow(this); // передача указателя для уничтожения
    connect(sin, &QPushButton::clicked, this, &MainWindow::showStartWindow);

    //D:/Music/rise.wav
  ////Music start Registration
  //QMediaPlayer* play = new QMediaPlayer;
  //QAudioOutput* audioOutput = new QAudioOutput;
  //play->setAudioOutput(audioOutput);
  //play->setSource(QUrl("D:/Music/rise.mp3"));  // Укажите полный путь к вашему аудиофайлу
  //play->play();
}

//деструктор
MainWindow::~MainWindow()
{
    delete parent();
}

QString imagePath = ":/img/logo.png";

//////////////////////////////////aboutPogram
QString text = QString(
                   "<center><h2>Программа Виртуальный квест по основам C#</h2></center>"
                   "<center><p><img src='%1' width='64' height='64'></p></center>"
                   "<center><p>Version 1.0</p></center>"
                   "<center><p>Autor: Dubnovitskiy Dmitry</p></center>"
                   "<center><p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p></center>"
                   ).arg(imagePath);

//function
void MainWindow::showAboutDialog() {
    QMessageBox::about(this, "О программе", text); // О программе
}

void MainWindow::showAboutProgramm() {
    QMessageBox::about(this, "Использование", "<center>Справка по использованию программы</center>"); // Cправка
}

void MainWindow::showRegistrationWindow()
{
    registrationWindow->show();  // Показываем окно регистрации
}

void MainWindow::showStartWindow()
{
    startwindow->show();  // Показываем окно регистрации
}

