#include "registration.h"
#include <QWindow>
#include <QApplication>

RegistrationWindow::RegistrationWindow()
{
    setWindowTitle("Окно регистрации");
    QApplication::setStyle("Fusion");

    //добавляем поля и кнопку регистрации
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLineEdit *usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Введите имя пользователя");

    QLineEdit *passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Введите пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);

    QLineEdit *email = new QLineEdit(this);
    email->setPlaceholderText("Введите email");

    QPushButton *registerButton = new QPushButton("Зарегистрироваться", this);


    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    usernameEdit->move(150,300);
    email->move(150,350);
    passwordEdit->move(150,400);

    registerButton->move(260,350);

    setLayout(layout);

    // Обработчик нажатия кнопки регистрации (по желанию)
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterClicked);
}

void RegistrationWindow::onRegisterClicked()
{
    // Логика регистрации
    QMessageBox::information(this, "Регистрация", "Регистрация успешна!");
}
