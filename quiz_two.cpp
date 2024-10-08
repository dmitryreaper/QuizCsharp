#include "quiz_two.h"

QuizTwo::QuizTwo(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0) {
    setupQuestions();        // Добавляем вопросы
    createQuizInterface();   // Создаем интерфейс викторины
}

void QuizTwo::setupQuestions() {
    questions.append({"Какой тип данных используется для хранения целого числа в C#?",
                      {"int", "double", "float", "string"}, 0});
    questions.append({"Какой тип данных используется для хранения дробных чисел в C#?",
                      {"int", "double", "bool", "string"}, 1});
    questions.append({"Какой тип данных используется для хранения символа в C#?",
                      {"char", "int", "string", "float"}, 0});
    questions.append({"Какой тип данных используется для хранения логических значений (true/false) в C#?",
                      {"int", "bool", "string", "double"}, 1});
    questions.append({"Какой тип данных в C# является наиболее точным для хранения чисел с плавающей точкой?",
                      {"float", "double", "decimal", "int"}, 2});
    questions.append({"Какой тип данных используется для хранения строки текста в C#?",
                      {"int", "char", "string", "bool"}, 2});
    questions.append({"Какой тип данных в C# имеет наибольший диапазон для хранения целых чисел?",
                      {"byte", "int", "long", "short"}, 2});
    questions.append({"Какой тип данных в C# используется для хранения небольших целых чисел от 0 до 255?",
                      {"byte", "int", "long", "short"}, 0});
    questions.append({"Что из нижеперечисленного не является типом данных в C#?",
                      {"bool", "char", "int", "text"}, 3});
    questions.append({"Какой тип данных используется для хранения числа с фиксированной точностью в C#?",
                      {"float", "double", "decimal", "long"}, 2});
    questions.append({"Каким типом данных можно описать переменную, которая содержит дату и время в C#?",
                      {"string", "DateTime", "int", "float"}, 1});
    questions.append({"Какой тип данных в C# используется для хранения неотрицательных целых чисел?",
                      {"int", "uint", "byte", "bool"}, 1});
    questions.append({"Каким типом данных в C# можно объявить переменную для хранения значения '3.14'?",
                      {"int", "double", "float", "char"}, 1});
    questions.append({"Что произойдет, если присвоить переменной типа int значение большее, чем максимальное допустимое значение?",
                      {"Ошибка компиляции", "Переполнение переменной", "Значение будет округлено", "Ничего"}, 1});
    questions.append({"Какой тип данных используется для хранения длинных целых чисел в C#?",
                      {"short", "long", "int", "byte"}, 1});
    questions.append({"Какой тип данных в C# используется для хранения значений валюты?",
                      {"float", "decimal", "double", "int"}, 1});
    questions.append({"Какой тип данных в C# используется для хранения значения с плавающей точкой с одинарной точностью?",
                      {"double", "float", "decimal", "int"}, 1});
    questions.append({"Какой тип данных используется для хранения значения, не включающего дробную часть, но с очень большим диапазоном?",
                      {"int", "long", "double", "byte"}, 1});
    questions.append({"Какой тип данных в C# используется для хранения 16-битного целого числа?",
                      {"short", "int", "long", "byte"}, 0});
    questions.append({"Какой тип данных в C# используется для хранения последовательности байтов?",
                      {"string", "byte[]", "int", "char"}, 1});
    }

void QuizTwo::createQuizInterface() {
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

    connect(submitButton, &QPushButton::clicked, this, &QuizTwo::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void QuizTwo::loadQuestion() {
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

void QuizTwo::handleAnswer() {
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
