#include "gamewindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <algorithm> // Для std::shuffle
#include <random>    // Для std::default_random_engine

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), currentTaskIndex(0), totalTasks(0) {
    // Создаем виджеты
    questionsList = new QListWidget(this);
    answersList = new QListWidget(this);
    checkButton = new QPushButton("Проверить ответы", this);
    progressLabel = new QLabel(this);
    QLabel *quiz = new QLabel(this);
    progressLabel->setFont(QFont("Arial", 12, QFont::Bold));
    questionsList->setFont(QFont("Arial", 14, QFont::Bold));
    answersList->setFont(QFont("Arial", 14, QFont::Bold));
    quiz->setFont(QFont("Arial", 12, QFont::Bold));
    quiz->setText("Соедините вопросы с правильными ответами");

    // Устанавливаем возможность перетаскивания
    questionsList->setDragEnabled(true);
    answersList->setAcceptDrops(true);
    answersList->setDragEnabled(true);
    answersList->setDefaultDropAction(Qt::MoveAction);

    // Добавляем задания (список вопросов и правильных ответов)
    tasks.append({{"1. Какой тип данных целочисленный", "2. Какой тип данных самый большой", "3. Строковый тип данных"},
                  {"long", "long double", "String"}});
    tasks.append({{"1. Какой тип данных используется для хранения логических значений (true/false) в C#", "2. Какой тип данных в C# используется для хранения небольших целых чисел от 0 до 255?", "3. Каким типом данных в C# можно объявить переменную для хранения значения '3.14'?"},
                  {"bool", "short", "float"}});
    tasks.append({{"1. Какой тип данных в C# используется для хранения значений валюты?", "2. Какой тип данных используется для хранения символа в C#?", "3. Какой тип данных используется для хранения строки текста в C#?"},
                  {"float", "char", "string"}});

    totalTasks = tasks.size();

    // Вертикальная компоновка
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(quiz);
    layout->addWidget(progressLabel);
    layout->addWidget(questionsList);
    layout->addWidget(answersList);
    layout->addWidget(checkButton);

    setLayout(layout);

    // Устанавливаем первое задание
    setupTask();

    // Соединение сигнала нажатия кнопки с проверкой ответов
    connect(checkButton, &QPushButton::clicked, this, [=]() {
        checkAnswers(answersList);
    });
}

void GameWindow::setupTask() {
    // Очистка списков
    questionsList->clear();
    answersList->clear();

    // Получаем текущее задание (вопросы и ответы)
    QStringList questions = tasks[currentTaskIndex].first;
    QStringList answers = tasks[currentTaskIndex].second;

    // Сохраняем правильные ответы в переменную, которая будет использоваться для проверки
    correctAnswersForCurrentTask = answers;

    // Перемешиваем ответы
    std::random_device rd;
    std::mt19937 g(rd());  // Генератор случайных чисел
    std::shuffle(answers.begin(), answers.end(), g);

    // Добавляем вопросы и перемешанные ответы в соответствующие списки
    for (const QString &question : questions) {
        questionsList->addItem(question);
    }

    for (const QString &answer : answers) {
        answersList->addItem(answer);
    }

    // Обновляем метку прогресса
    progressLabel->setText(QString("Задание %1 из %2").arg(currentTaskIndex + 1).arg(totalTasks));
}

void GameWindow::checkAnswers(QListWidget *answersList) {
    // Получаем список пользовательских ответов
    QStringList userAnswers;
    for (int i = 0; i < answersList->count(); ++i) {
        userAnswers.append(answersList->item(i)->text());
    }

    // Проверяем, совпадают ли ответы пользователя с правильными
    bool allCorrect = true;
    for (int i = 0; i < correctAnswersForCurrentTask.size(); ++i) {
        if (userAnswers.indexOf(correctAnswersForCurrentTask[i]) != i) {
            allCorrect = false;
            break;
        }
    }

    // Показ результата
    if (allCorrect) {
        QMessageBox::information(this, "Результат", "Все ответы верны!");
        nextTask();  // Переходим к следующему заданию
    } else {
        QMessageBox::warning(this, "Результат", "Некоторые ответы неверны.");
    }
}

void GameWindow::nextTask() {
    // Проверяем, есть ли еще задания
    if (currentTaskIndex < totalTasks - 1) {
        currentTaskIndex++;   // Переходим к следующему заданию
        setupTask();          // Обновляем интерфейс для нового задания
    } else {
        QMessageBox::information(this, "Конец", "Вы завершили все задания!");
        this->close();
    }
}
