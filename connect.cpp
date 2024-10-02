#include "connect.h"
#include "generalwindow.h"
#include <QApplication>
#include <QWindow>

StartWindow::StartWindow() {
    setWindowTitle("Окно входа");
    setFixedSize(300, 200);
    QApplication::setStyle("Fusion");

    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Введите имя пользователя");
    usernameEdit->resize(170, 30);

    emailEdit = new QLineEdit(this);
    emailEdit->setPlaceholderText(("Введите ваш email"));
    emailEdit->resize(170, 30);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Введите пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->resize(170, 30);

    QPushButton *registerButton = new QPushButton("Войти", this);

    //Размещение
    usernameEdit->move(70,50);
    emailEdit->move(70,90);
    passwordEdit->move(70,130);
    registerButton->move(100,170);

    layout->addWidget(usernameEdit);
    layout->addWidget(emailEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);

    // Подключаем кнопку к слоту
    connect(registerButton, &QPushButton::clicked, this, &StartWindow::onStartClicked);
}

void StartWindow::onStartClicked() {
    // Получаем введенные данные
    QString username = usernameEdit->text();
    QString email = emailEdit->text();
    QString password = passwordEdit->text();

    // Подключаемся к базе данных
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Dmitry/users.db");

        if (!db.open()) {
            qDebug() << "Error opening database:" << db.lastError().text();
            return;
        }
    }
    // Вывод информации о базе данных
    qDebug() << "Database name:" << db.databaseName();
    qDebug() << "Is database open?" << db.isOpen();

    // Проверяем наличие пользователя в базе данных
    QSqlQuery query;
    query.prepare("SELECT name, email, password FROM users WHERE name = :name AND email = :email AND password = :password;");
    query.bindValue(":name", username);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.exec();

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Если пользователь найден, продолжаем
        QMessageBox::information(this, "Вход", "Вход успешен!");

        // Открываем новое окно
        GeneralWindow *generalWindow = new GeneralWindow();
        generalWindow->show();

        // Закрываем текущее окно
        this->close();
    }
    else {
        // Если пользователь не найден, выводим сообщение об ошибке
        QMessageBox::warning(this, "Ошибка", "Неправильное имя пользователя, email или пароль.");
    }
}
