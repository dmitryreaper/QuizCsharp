#include "quiz.h"

Quiz::Quiz(QWidget *parent) : QWidget(parent), currentQuestionIndex(0) {
    setupQuestions();        // Добавляем вопросы
    createQuizInterface();   // Создаем интерфейс викторины
}

void Quiz::setupQuestions() {
    questions.append({"Какой язык программирования мы изучаем?",
                      {"Kotlin", "Node.js", "C#", "Assembler", "C/C++", "Haskell"}, 2});
    questions.append({"Как вывести текст на экран в C#?",
                      {"std::cout << \"Привет!\"", "Console.WriteLine(\"Привет!\");", "echo \"Привет!\";", "Print(\"Привет!\");"}, 1});
    questions.append({"Какой тип данных отвечает за хранение целого числa?",
                      {"for", "double", "inf", "include", "int", "if"}, 4});
    questions.append({"Как хранить текст в C#?",
                      {"number", "string", "text", "int"}, 1});
    questions.append({"Что делает оператор if?",
                      {"Повторяет команды", "Закрытие программы", "Проверяет условие", "Выводит текст"}, 2});
    questions.append({"Что делает цикл for?",
                      {"Выводит текст", "Выполняет команды много раз", "Проверяет условие", "Переход к следующей команде"}, 1});
    questions.append({"Что обозначает \"//\" в С#",
                      {"Комментарий", "Ошибка", "Условие", "Цикл"}, 0});
    questions.append({"Как завершить команду в C#?",
                      {"!", ".", ";", ":"}, 2});
    questions.append({"Что выведет команда `Console.WriteLine(2 + 3);`?",
                      {"23", "5", "Ошибка", "2+3"}, 1});
    questions.append({"Что такое `bool` в C#?",
                      {"Тип данных для текста", "Тип данных для целых чисел", "Тип данных для значений истина/ложь", "Цикл"}, 2});
    questions.append({"Что выведет программа: `int x = 10; Console.WriteLine(x);`?",
                      {"x", "0", "10", "Ошибка"}, 2});
    questions.append({"Что делает функция `Console.ReadLine()`?",
                      {"Считывает данные с экрана", "Выводит данные на экран", "Считывает данные от пользователя", "Создает переменную"}, 2});
    questions.append({"Какой тип данных используется для хранения значений true/false в C#?",
                      {"bool", "int", "string", "float"}, 0});
    questions.append({"Какую команду нужно использовать для создания цикла, который выполняется, пока условие истинно?",
                      {"for", "while", "do", "if"}, 1});
    questions.append({"Что такое массив в C#?",
                      {"Тип данных для целых чисел", "Тип данных для строк", "Последовательность элементов одного типа", "Функция для вывода данных"}, 2});
    questions.append({"Как вызвать метод с параметрами в C#?",
                      {"method()", "method(5)", "method[]", "method{5}"}, 1});
    questions.append({"Какой тип данных в C# используется для хранения символов?",
                      {"string", "char", "int", "bool"}, 1});
    questions.append({"Как создать бесконечный цикл в C#?",
                      {"for(;;)", "while(true)", "do while(true)", "Все вышеперечисленное"}, 3});
    questions.append({"Как объявить переменную, которая не может изменяться в C#?",
                      {"var", "const", "readonly", "static"}, 1});
    questions.append({"Что делает команда `+=` в C#?",
                      {"Прибавляет значение к переменной", "Умножает переменную", "Делает переменную равной нулю", "Создает новую переменную"}, 0});
}

void Quiz::createQuizInterface() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Лейбл для прогресса викторины
    progressLabel = new QLabel(this);

    progressLabel->setFont(QFont("Arial", 12));
    progressLabel->setFixedSize(300,20);
    layout->addWidget(progressLabel);

    // Лейбл для вопроса
    questionLabel = new QLabel(this);
    questionLabel->setFixedSize(500,20);
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

    connect(submitButton, &QPushButton::clicked, this, &Quiz::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void Quiz::loadQuestion() {
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

void Quiz::handleAnswer() {
    int selectedOption = buttonGroup->checkedId();
    if (selectedOption == questions[currentQuestionIndex].correctAnswerIndex) {
        QMessageBox::information(this, "Результат", "Верно! +5 очков");
    } else {
        QMessageBox::information(this, "Результат", "Неверно. Попробуйте снова.");
    }

    currentQuestionIndex++;

    if (currentQuestionIndex < questions.size()) {
        loadQuestion();  // Загружаем следующий вопрос
    } else {
        QMessageBox::information(this, "Результат", "Викторина завершена!\nПоздравляем!");
        this->close();  // Закрыть окно викторины по завершению
    }
}
