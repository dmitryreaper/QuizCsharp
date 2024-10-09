#include "task2quiz3.h"

Task2Quiz3::Task2Quiz3(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0) {
    //Стильно модно молодёжно
    setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; }"
                  "QListWidget { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
                  "QLabel { color: #white; }");
    setupQuestions();
    createQuizInterface();
}

void Task2Quiz3::setupQuestions() {

    questions.append({"Какой метод используется для нахождения квадратного корня числа?",
                      {"Math.Sqrt()", "Math.Pow()", "Math.Square()", "Math.Root()"}, 0});

    questions.append({"Какой метод используется для возведения числа в степень?",
                      {"Math.Pow()", "Math.Sqrt()", "Math.Exp()", "Math.Square()"}, 0});

    questions.append({"Какой метод используется для округления числа?",
                      {"Math.Round()", "Math.Ceil()", "Math.Floor()", "Math.Truncate()"}, 0});

    questions.append({"Какой метод используется для получения абсолютного значения числа?",
                      {"Math.Abs()", "Math.Max()", "Math.Min()", "Math.Round()"}, 0});

    questions.append({"Какой метод возвращает наибольшее из двух чисел?",
                      {"Math.Max()", "Math.Min()", "Math.Greater()", "Math.Larger()"}, 0});

    questions.append({"Какой метод возвращает наименьшее из двух чисел?",
                      {"Math.Min()", "Math.Max()", "Math.Less()", "Math.Smaller()"}, 0});

    questions.append({"Какой метод возвращает целую часть числа путем отбрасывания дробной части?",
                      {"Math.Truncate()", "Math.Floor()", "Math.Round()", "Math.Ceil()"}, 0});

    questions.append({"Какой метод используется для округления числа вниз до ближайшего целого?",
                      {"Math.Floor()", "Math.Round()", "Math.Ceil()", "Math.Truncate()"}, 0});

    questions.append({"Какой метод используется для округления числа вверх до ближайшего целого?",
                      {"Math.Ceil()", "Math.Floor()", "Math.Round()", "Math.Truncate()"}, 0});

    questions.append({"Какой метод используется для нахождения синуса угла (в радианах)?",
                      {"Math.Sin()", "Math.Cos()", "Math.Tan()", "Math.Asin()"}, 0});

    questions.append({"Какой метод используется для нахождения косинуса угла (в радианах)?",
                      {"Math.Cos()", "Math.Sin()", "Math.Tan()", "Math.Acos()"}, 0});

    questions.append({"Какой метод используется для нахождения тангенса угла (в радианах)?",
                      {"Math.Tan()", "Math.Sin()", "Math.Cos()", "Math.Atan()"}, 0});

    questions.append({"Какой метод используется для нахождения арксинуса угла?",
                      {"Math.Asin()", "Math.Sin()", "Math.ArcSin()", "Math.Atan()"}, 0});

    questions.append({"Какой метод используется для нахождения арккосинуса угла?",
                      {"Math.Acos()", "Math.Cos()", "Math.ArcCos()", "Math.Atan()"}, 0});

    questions.append({"Какой метод используется для нахождения арктангенса угла?",
                      {"Math.Atan()", "Math.Tan()", "Math.ArcTan()", "Math.Acos()"}, 0});

    questions.append({"Как в C# округлить число до заданного количества знаков после запятой?",
                      {"Math.Round(value, digits)", "Math.Ceil(value, digits)", "Math.Floor(value, digits)", "Math.Truncate(value, digits)"}, 0});

    questions.append({"Какой метод используется для вычисления натурального логарифма?",
                      {"Math.Log()", "Math.Ln()", "Math.Exp()", "Math.Log10()"}, 0});

    questions.append({"Какой метод используется для вычисления логарифма по основанию 10?",
                      {"Math.Log10()", "Math.Log()", "Math.Ln()", "Math.Exp()"}, 0});

    questions.append({"Какой метод используется для нахождения остатка от деления?",
                      {"%", "Math.Mod()", "Math.Divide()", "Math.Remainder()"}, 0});

    questions.append({"Какой метод используется для получения случайного числа?",
                      {"new Random().Next()", "Math.Random()", "Math.NextRandom()", "Random.Number()"}, 0});

}

void Task2Quiz3::createQuizInterface() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Лейбл для прогресса викторины
    progressLabel = new QLabel(this);

    progressLabel->setFont(QFont("Arial", 12));
    progressLabel->setFixedSize(300,20);
    layout->addWidget(progressLabel);

    // Лейбл для вопроса
    questionLabel = new QLabel(this);
    questionLabel->setFixedSize(800,20);
    questionLabel->setFont(QFont("Arial", 14, QFont::Bold));
    layout->addWidget(questionLabel);

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

    connect(submitButton, &QPushButton::clicked, this, &Task2Quiz3::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void Task2Quiz3::loadQuestion() {
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
    }
}

void Task2Quiz3::handleAnswer() {
    int selectedOption = buttonGroup->checkedId();
    if (selectedOption == questions[currentQuestionIndex].correctAnswerIndex) {
        QMessageBox::information(this, "Результат", "Верно!");
        score+=5;  // Увеличиваем счет
    } else {
        QMessageBox::information(this, "Результат", "Неверно.");
    }

    currentQuestionIndex++;

    if (currentQuestionIndex < questions.size()) {
        loadQuestion();      } else {

        // Сообщение с итоговым результатом
        QMessageBox::information(this, "Результат",
                                 QString("Викторина завершена!\nВаш результат: %1 очков").arg(score));
        this->close();  // Закрыть окно викторины по завершению
    }
}
