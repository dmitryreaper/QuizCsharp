#include <QVBoxLayout>
#include <QMessageBox>
#include <QFont>
#include <QTimer>
#include <QPropertyAnimation>
#include "task2quiz2.h"

Task2Quiz2::Task2Quiz2(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0), timeRemaining(10) {
    //Стильно модно молодёжно
    setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; }"
                  "QListWidget { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
                  "QLabel { color: #white; }");
    setupQuestions();
    createQuizInterface();
}

void Task2Quiz2::setupQuestions() {

    questions.append({"Какой метод используется для записи строки текста в файл?",
                      {"File.WriteAllText()", "Console.WriteLine()", "Stream.Write()", "File.AppendText()"}, 0});

    questions.append({"Какой метод позволяет прочитать весь текст из файла?",
                      {"File.ReadAllText()", "Console.ReadLine()", "Stream.Read()", "File.Read()"}, 0});

    questions.append({"Какой метод используется для добавления текста в конец файла?",
                      {"File.AppendAllText()", "File.WriteAllText()", "Console.Write()", "File.AddText()"}, 0});

    questions.append({"Какой класс используется для чтения данных из файла построчно?",
                      {"StreamReader", "FileReader", "ConsoleReader", "TextReader"}, 0});

    questions.append({"Какой класс используется для записи данных в файл построчно?",
                      {"StreamWriter", "FileWriter", "ConsoleWriter", "TextWriter"}, 0});

    questions.append({"Какой метод класса StreamReader используется для чтения одной строки из файла?",
                      {"ReadLine()", "Read()", "ReadToEnd()", "ReadNextLine()"}, 0});

    questions.append({"Какой метод класса StreamWriter используется для записи одной строки в файл?",
                      {"WriteLine()", "Write()", "AppendLine()", "PrintLine()"}, 0});

    questions.append({"Какой метод используется для закрытия потока чтения из файла?",
                      {"Close()", "Finish()", "End()", "Terminate()"}, 0});

    questions.append({"Какой метод используется для закрытия потока записи в файл?",
                      {"Close()", "Finish()", "End()", "Terminate()"}, 0});

    questions.append({"Какой метод класса File проверяет, существует ли файл?",
                      {"Exists()", "CheckFile()", "IsFile()", "FileExists()"}, 0});

    questions.append({"Какой метод класса File используется для удаления файла?",
                      {"Delete()", "Remove()", "Erase()", "Clear()"}, 0});

    questions.append({"Какой метод класса File копирует файл в другое место?",
                      {"Copy()", "Move()", "Transfer()", "Duplicate()"}, 0});

    questions.append({"Какой метод класса File перемещает файл в другую директорию?",
                      {"Move()", "Copy()", "Transfer()", "Rename()"}, 0});

    questions.append({"Какой метод используется для открытия файла для чтения и записи?",
                      {"File.Open()", "File.ReadWrite()", "File.Access()", "File.Create()"}, 0});

    questions.append({"Какой метод используется для асинхронной записи данных в файл?",
                      {"WriteAsync()", "Write()", "WriteLineAsync()", "AppendAsync()"}, 0});

    questions.append({"Какой метод используется для асинхронного чтения данных из файла?",
                      {"ReadAsync()", "ReadLineAsync()", "Read()", "ReadToEndAsync()"}, 0});

    questions.append({"Какой метод класса File читает все строки из файла в массив строк?",
                      {"ReadAllLines()", "ReadLines()", "GetLines()", "ReadToArray()"}, 0});

    questions.append({"Какой метод используется для записи всех строк массива в файл?",
                      {"WriteAllLines()", "WriteLines()", "AddLines()", "WriteToArray()"}, 0});

    questions.append({"Какой метод класса File считывает весь файл в один массив байтов?",
                      {"ReadAllBytes()", "GetBytes()", "ReadBytes()", "ReadAllToByteArray()"}, 0});

    questions.append({"Какой метод класса File записывает массив байтов в файл?",
                      {"WriteAllBytes()", "WriteBytes()", "WriteToFile()", "SaveBytes()"}, 0});

}

void Task2Quiz2::createQuizInterface() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Лейбл для прогресса викторины
    progressLabel = new QLabel(this);
    progressLabel->setFont(QFont("Arial", 12));
    progressLabel->setFixedSize(300, 20);
    layout->addWidget(progressLabel);

    // Лейбл для вопроса
    questionLabel = new QLabel(this);
    questionLabel->setFixedSize(800, 20);
    questionLabel->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(questionLabel);

    // Лейбл для таймера
    timerLabel = new QLabel(this);
    timerLabel->setFont(QFont("Arial", 12, QFont::Bold));
    timerLabel->setFixedSize(300, 20);
    layout->addWidget(timerLabel);

    // Таймер обратного отсчета
    questionTimer = new QTimer(this);
    connect(questionTimer, &QTimer::timeout, this, &Task2Quiz2::updateTimer);

    // Группа кнопок с вариантами ответа
    buttonGroup = new QButtonGroup(this);
    for (int i = 0; i < 5; ++i) {  // Максимум 5 вариантов ответа
        QRadioButton *optionButton = new QRadioButton(this);
        optionButton->setFont(QFont("Arial", 14, QFont::Bold));
        optionButtons.append(optionButton);
        layout->addWidget(optionButton);
        buttonGroup->addButton(optionButton, i);
    }

    // Кнопка для отправки ответа
    submitButton = new QPushButton("Ответить", this);
    submitButton->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &Task2Quiz2::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void Task2Quiz2::loadQuestion() {
    if (currentQuestionIndex < questions.size()) {
        const Question &question = questions[currentQuestionIndex];

        // Обновляем прогресс вопросов
        progressLabel->setText(QString("Вопрос %1 из %2")
                                   .arg(currentQuestionIndex + 1)
                                   .arg(questions.size()));

        questionLabel->setText(question.text);

        // Обновляем варианты ответов
        for (int i = 0; i < optionButtons.size(); ++i) {
            if (i < question.options.size()) {
                optionButtons[i]->setText(question.options[i]);
                optionButtons[i]->setVisible(true);
            } else {
                optionButtons[i]->setVisible(false);
            }
        }

        // Запускаем таймер
        timeRemaining = 10;  // Даем игроку 10 секунд на ответ
        timerLabel->setText(QString("Осталось времени: %1 секунд").arg(timeRemaining));
        questionTimer->start(1000);  // Таймер обновляется каждую секунду
    }
}

void Task2Quiz2::handleAnswer() {
    questionTimer->stop();  // Останавливаем таймер при ответе
    int selectedOption = buttonGroup->checkedId();

    if (selectedOption == questions[currentQuestionIndex].correctAnswerIndex) {
        score += 5;  // Увеличиваем счет
        animateScoreIncrease();  // Запускаем анимацию изменения счета
        QMessageBox::information(this, "Результат", "Верно!");
    } else {
        QMessageBox::information(this, "Результат", "Неверно.");
    }

    currentQuestionIndex++;

    if (currentQuestionIndex < questions.size()) {
        loadQuestion();
    } else {
        QMessageBox::information(this, "Результат",
                                 QString("Викторина завершена!\nВаш результат: %1 очков").arg(score));
        this->close();
    }
}

// Функция для обновления таймера
void Task2Quiz2::updateTimer() {
    timeRemaining--;
    timerLabel->setText(QString("Осталось времени: %1 секунд").arg(timeRemaining));

    if (timeRemaining == 0) {
        questionTimer->stop();
        handleAnswer();  // Автоматически обработать отсутствие ответа
    }
}

// Анимация изменения счета
void Task2Quiz2::animateScoreIncrease() {
    // Пример анимации для визуального изменения очков (увеличение размера)
    QPropertyAnimation *animation = new QPropertyAnimation(progressLabel, "font");
    animation->setDuration(500);
    QFont biggerFont = progressLabel->font();
    biggerFont.setPointSize(biggerFont.pointSize() + 5);
    animation->setStartValue(progressLabel->font());
    animation->setEndValue(biggerFont);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
