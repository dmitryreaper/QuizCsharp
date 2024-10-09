#include "mainwindow.h"
#include <QIcon>

//#include "registration.h"

// General Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setFixedSize(800,460);
    setWindowIcon(QIcon(":/img/ico.png"));
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

QString imagePath = ":/img/ico.png";

//////////////////////////////////aboutPogram
QString text = QString(
                   "<center><h2>Программа Виртуальный квест по основам C#</h2></center>"
                   "<center><p>Version 1.0</p></center>"
                   "<center><p>Autor: Dubnovitskiy Dmitry</p></center>"
                   "<center><p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p></center>"
                   ).arg(imagePath);
QString helpik = QString(
                   "<center><h2>Справка приложения</h2></center>"
                   "<h3>Главные элементы интерфейса</h3>"
                   "<p><b>Кнопка \"Задания\"</b><br>"
                   "Позволяет получить доступ к списку заданий. Каждое задание требует определённого количества очков для открытия. Очки можно заработать, проходя предыдущие задания:<br>"
                   "- Задание 1: Теоретические основы C# (0 очков).<br>"
                   "- Задание 2: Практика написания консольных приложений (500 очков).<br>"
                   "- Задание 3: Создание оконных приложений (2000 очков).<br>"
                   "- Задание 4: Продвинутый уровень создания оконных приложений без конструктора (5000 очков).<br>"
                   "- Задание 5: Использование C# в веб-разработке (8000 очков).<br>"
                   "Чтобы открыть задание, нажмите на его название. Если у вас недостаточно очков, появится сообщение с информацией о необходимом количестве.</p>"
                   "<p><b>Кнопка \"Профиль\"</b><br>"
                   "В разделе \"Профиль\" вы можете посмотреть информацию о вашем аккаунте: имя пользователя, email и текущий уровень очков.</p>"
                   "<p><b>Кнопка \"Достижения\"</b><br>"
                   "В этом разделе отображаются ваши достижения в приложении. После выполнения заданий вы будете зарабатывать различные награды и титулы.</p>"
                   "<p><b>Кнопка \"О программе\"</b><br>"
                   "В этом окне представлена информация о приложении, его версии, авторе и ссылки на исходный код на GitHub.</p>"
                   "<p><b>Кнопка \"Справка\"</b><br>"
                   "Здесь вы можете ознакомиться с инструкциями по использованию приложения.</p>"
                   "<h3>Как заработать очки</h3>"
                   "<p>1. Выполняйте задания в указанной последовательности.<br>"
                   "2. Чем сложнее задание, тем больше очков вы получаете за его выполнение.<br>"
                   "3. Прогресс можно отслеживать в разделе \"Профиль\".</p>"
                   "<h3>Технические требования</h3>"
                   "<p>Операционная система: Windows, Linux, macOS.<br>"
                   "Установленный Qt для запуска приложения.</p>"
                   "<h3>Важно!</h3>"
                   "<p>Чтобы продвигаться по заданиям, убедитесь, что у вас достаточно очков для открытия следующих уровней. Для открытия продвинутых уровней и использования всех возможностей приложения потребуется выполнить предыдущие задания.</p>"
                   "<p>Если у вас возникли вопросы или проблемы с приложением, пожалуйста, обращайтесь к разработчику через "
                   "<a href='https://github.com/dmitryreaper'>GitHub</a>.</p>"
    );

//function
void MainWindow::showAboutDialog() {
    QMessageBox::about(this, "О программе", text); // О программе
}

void MainWindow::showAboutProgramm() {
    QMessageBox::about(this, "Справка", helpik); // Cправка
}

void MainWindow::showRegistrationWindow()
{
    registrationWindow->show();  // Показываем окно регистрации
}

void MainWindow::showStartWindow()
{
    startwindow->show();  // Показываем окно регистрации
}

