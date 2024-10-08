#include "quiz_four.h"

QuizFour::QuizFour(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0) {
    setupQuestions();      // Добавляем вопросы
    createQuizInterface(); // Создаем интерфейс викторины
}

void QuizFour::setupQuestions() {
    questions.append({"Какой оператор в C# используется для проверки условия и выполнения кода в зависимости от его истинности?",
                      {"if", "for", "switch", "while"}, 0});
    questions.append({"Какой блок выполняется, если условие в операторе if ложно?",
                      {"if", "else", "else if", "case"}, 1});
    questions.append({"Как записать условие, если нужно выполнить несколько проверок по порядку?",
                      {"if", "else", "else if", "switch"}, 2});
    questions.append({"Какой оператор используется для выбора одного из нескольких вариантов в зависимости от значения переменной?",
                      {"if", "else", "else if", "switch"}, 3});
    questions.append({"Какой оператор используется для завершения ветки в конструкции switch?",
                      {"continue", "break", "return", "exit"}, 1});
    questions.append({"Какой блок используется для обработки исключений, если они возникают в коде?",
                      {"try", "catch", "finally", "Все вышеперечисленное"}, 3});
    questions.append({"Что произойдет, если условие в блоке if истинно?",
                      {"Выполнится блок if", "Выполнится блок else", "Цикл завершится", "Ничего"}, 0});
    questions.append({"Что произойдет, если ни одно условие в блоках if/else if не выполнится?",
                      {"Выполнится блок else", "Выполнится первый блок if", "Произойдет ошибка", "Ничего"}, 0});
    questions.append({"Какое ключевое слово используется для проверки нескольких условий в операторе if?",
                      {"case", "else", "switch", "else if"}, 3});
    questions.append({"Какой оператор используется для выбора действия в зависимости от логического выражения?",
                      {"if", "for", "switch", "while"}, 0});
    questions.append({"Какой оператор используется для проверки логических выражений и выполнения блока кода в зависимости от результата?",
                      {"if", "switch", "case", "while"}, 0});
    questions.append({"Что делает оператор else в конструкции ветвления?",
                      {"Проверяет другое условие", "Завершает программу", "Выполняет код, если предыдущее условие ложно", "Пропускает итерацию"}, 2});
    questions.append({"Что произойдет, если в операторе switch не указать блок default?",
                      {"Произойдет ошибка", "Не выполнится ни один вариант", "Будет выполнено первое условие", "Ничего"}, 3});
    questions.append({"Какой оператор завершает выполнение метода и возвращает значение?",
                      {"break", "return", "continue", "else"}, 1});
    questions.append({"Можно ли использовать условие else без if?",
                      {"Да", "Нет"}, 1});
    questions.append({"Что делает ключевое слово default в конструкции switch?",
                      {"Обрабатывает все остальные случаи, если ни один case не выполнен", "Выводит значение по умолчанию", "Завершает программу", "Пропускает выполнение"}, 0});
    questions.append({"Как проверить несколько условий одновременно в одной конструкции if?",
                      {"С помощью оператора &&", "С помощью оператора ||", "С помощью оператора !", "Все вышеперечисленные"}, 3});
    questions.append({"Какое значение переменной приведет к выполнению блока кода в if, если она имеет тип bool?",
                      {"true", "false", "0", "1"}, 0});
    questions.append({"Какой оператор можно использовать для выполнения одного из двух вариантов в зависимости от условия?",
                      {"Оператор ветвления", "Тернарный оператор", "Логический оператор", "Условный оператор"}, 1});
    questions.append({"Что произойдет, если в конструкции if указать несколько условий через && и одно из них ложно?",
                      {"Выполнится код else", "Проверка завершится", "Все условия проверятся", "Ничего"}, 1});
}

void QuizFour::createQuizInterface() {
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

    connect(submitButton, &QPushButton::clicked, this, &QuizFour::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void QuizFour::loadQuestion() {
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

void QuizFour::handleAnswer() {
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
