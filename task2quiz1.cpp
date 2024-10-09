#include "task2quiz1.h"

Task2Quiz1::Task2Quiz1(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0), timeRemaining(10) {
    //Стильно модно молодёжно
    setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; }"
                  "QListWidget { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
                  "QLabel { color: #white; }");
    setupQuestions();
    createQuizInterface();
}

void Task2Quiz1::setupQuestions() {
    questions.append(Question{"Какой оператор используется для перехода к следующей итерации цикла, пропуская оставшийся код?", "continue"});
    questions.append(Question{"Какой цикл используется в C# для выполнения блока кода, пока условие истинно?", "while"});
    questions.append(Question{"Как остановить бесконечный цикл?", "break"});
    questions.append(Question{"Как вывести на экран 'Hello world'", "WriteLine(\"Hello world\")"});
    questions.append(Question{"Какой класс используется для записи данных в файл построчно?", "StreamWriter"});
    questions.append(Question{"Как можно использовать цикл for для итерации с шагом в 2 до числа 10?", "for(int i = 0; i < 10; i += 2)"});
    questions.append(Question{"Как создать бесконечный цикл в C# с помощью цикла while?", "while(true)"});
    questions.append(Question{"Как объявить переменную, которая не может изменяться в C#", "const"});
    questions.append(Question{"Какой тип данных в C# используется для хранения символов?", "char"});
    questions.append(Question{"Как завершить команду в C#", ";"});
    questions.append(Question{"Как сделать коментарий в коде на одной строке ?", "////"});
}

void Task2Quiz1::createQuizInterface() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    progressLabel = new QLabel(this);
    progressLabel->setFont(QFont("Arial", 12));
    progressLabel->setFixedSize(300, 20);
    layout->addWidget(progressLabel);

    questionLabel = new QLabel(this);
    questionLabel->setFixedSize(1000, 20);
    questionLabel->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(questionLabel);

    timerLabel = new QLabel(this);
    timerLabel->setFont(QFont("Arial", 12, QFont::Bold));
    timerLabel->setFixedSize(300, 20);
    layout->addWidget(timerLabel);

    questionTimer = new QTimer(this);
    connect(questionTimer, &QTimer::timeout, this, &Task2Quiz1::updateTimer);

    // Поле для ввода ответа
    answerInput = new QLineEdit(this);
    answerInput->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(answerInput);

    // Кнопка для отправки ответа
    submitButton = new QPushButton("Ответить", this);
    submitButton->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &Task2Quiz1::handleAnswer);

    setLayout(layout);
    loadQuestion();
}

void Task2Quiz1::loadQuestion() {
    if (currentQuestionIndex < questions.size()) {
        const Question &question = questions[currentQuestionIndex];

        // Обновляем прогресс вопросов
        progressLabel->setText(QString("Вопрос %1 из %2")
                                   .arg(currentQuestionIndex + 1)
                                   .arg(questions.size()));

        questionLabel->setText(question.text);

        // Очищаем поле для ввода
        answerInput->clear();

        // Запускаем таймер
        timeRemaining = 20;
        timerLabel->setText(QString("Осталось времени: %1 секунд").arg(timeRemaining));
        questionTimer->start(1000);
    }
}

void Task2Quiz1::handleAnswer() {
    questionTimer->stop();  // Останавливаем таймер при ответе
    QString userAnswer = answerInput->text().trimmed();

    if (userAnswer == questions[currentQuestionIndex].correctAnswer) {
        score += 5;
        animateScoreIncrease();
        QMessageBox::information(this, "Результат", "Верно!");

        currentQuestionIndex++;
        if (currentQuestionIndex < questions.size()) {
            loadQuestion();
        } else {
            QMessageBox::information(this, "Результат",
                                     QString("Викторина завершена!\nВаш результат: %1 очков").arg(score));
            this->close();
        }
    } else {
        QMessageBox::information(this, "Результат", "Неверно.");
        currentQuestionIndex++;
        if (currentQuestionIndex < questions.size()) {
            loadQuestion();
        } else {
            QMessageBox::information(this, "Результат",
                                     QString("Викторина завершена!\nВаш результат: %1 очков").arg(score));
            this->close();
        }
    }
}

// Функция для обновления таймера
void Task2Quiz1::updateTimer() {
    timeRemaining--;
    timerLabel->setText(QString("Осталось времени: %1 секунд").arg(timeRemaining));

    if (timeRemaining == 0) {
        questionTimer->stop();
        handleAnswer();
    }
}

// Анимация изменения счета
void Task2Quiz1::animateScoreIncrease() {
    QPropertyAnimation *animation = new QPropertyAnimation(progressLabel, "font");
    animation->setDuration(500);
    QFont biggerFont = progressLabel->font();
    biggerFont.setPointSize(biggerFont.pointSize() + 5);
    animation->setStartValue(progressLabel->font());
    animation->setEndValue(biggerFont);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
