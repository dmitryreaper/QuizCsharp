#include "quiz_tree.h"

QuizTre::QuizTre(QWidget *parent) : QWidget(parent), currentQuestionIndex(0), score(0) {
    //Стильно модно молодёжно
    setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; }"
                  "QListWidget { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
                  "QLabel { color: #white; }");
    setupQuestions();        // Добавляем вопросы
    createQuizInterface();   // Создаем интерфейс викторины
}

void QuizTre::setupQuestions() {
    questions.append({"Какой цикл используется в C# для выполнения блока кода, пока условие истинно?",
                      {"for", "while", "do-while", "foreach"}, 1});
    questions.append({"Какой цикл выполняется как минимум один раз, даже если условие ложное?",
                      {"for", "while", "do-while", "foreach"}, 2});
    questions.append({"Какой цикл используется для перебора элементов коллекции или массива?",
                      {"for", "while", "do-while", "foreach"}, 3});
    questions.append({"Какой оператор используется для выхода из цикла до его завершения?",
                      {"break", "continue", "return", "exit"}, 0});
    questions.append({"Какой цикл в C# повторяется фиксированное количество раз?",
                      {"while", "for", "do-while", "foreach"}, 1});
    questions.append({"Какой оператор используется для перехода к следующей итерации цикла, пропуская оставшийся код?",
                      {"break", "continue", "return", "goto"}, 1});
    questions.append({"Какую конструкцию цикла нужно использовать, если известно количество повторений?",
                      {"while", "for", "do-while", "foreach"}, 1});
    questions.append({"Какой цикл используется для бесконечного выполнения, если не заданы условия для завершения?",
                      {"for(;;)", "while(true)", "do-while(true)", "Все вышеперечисленное"}, 3});
    questions.append({"Как остановить бесконечный цикл?",
                      {"break", "continue", "exit", "return"}, 0});
    questions.append({"Что произойдет, если в цикле for не указать условие завершения?",
                      {"Ошибка компиляции", "Цикл завершится сразу", "Цикл станет бесконечным", "Ничего"}, 2});
    questions.append({"Какое ключевое слово используется для создания вложенного цикла?",
                      {"for", "while", "foreach", "Любое из вышеперечисленного"}, 3});
    questions.append({"Какое ключевое слово завершает только текущую итерацию и продолжает выполнение цикла?",
                      {"continue", "break", "return", "exit"}, 0});
    questions.append({"Какой цикл в C# следует использовать для итерации по массиву строк?",
                      {"for", "while", "do-while", "foreach"}, 3});
    questions.append({"Как создать бесконечный цикл с помощью цикла `while`?",
                      {"while(true)", "while(1)", "while(false)", "while(0)"}, 0});
    questions.append({"Как можно использовать цикл for для итерации с шагом в 2?",
                      {"for(int i = 0; i < 10; i++)", "for(int i = 0; i < 10; i += 2)", "for(int i = 10; i > 0; i++)", "for(int i = 0; i < 10; i--)"}, 1});
    questions.append({"Какой цикл в C# выполняется до тех пор, пока условие истинно?",
                      {"while", "if", "for", "switch"}, 0});
    questions.append({"Какую часть цикла for можно опустить?",
                      {"Тело цикла", "Инициализацию", "Условие", "Любую часть"}, 3});
    questions.append({"Что произойдет, если условие в цикле while всегда будет ложным?",
                      {"Цикл выполнится один раз", "Цикл не выполнится", "Цикл выполнится бесконечно", "Произойдет ошибка"}, 1});
    questions.append({"Какую ошибку может вызвать бесконечный цикл?",
                      {"Переполнение памяти", "Слишком быстрое выполнение", "Зависание программы", "Ничего"}, 2});
    questions.append({"Что произойдет при выполнении команды `continue` в цикле for?",
                      {"Цикл завершится", "Текущая итерация завершится, и начнется следующая", "Будет выполнен выход из цикла", "Будет пропущен весь цикл"}, 1});
}

void QuizTre::createQuizInterface() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Лейбл для прогресса викторины
    progressLabel = new QLabel(this);

    progressLabel->setFont(QFont("Arial", 12));
    progressLabel->setFixedSize(300,20);
    layout->addWidget(progressLabel);

    // Лейбл для вопроса
    questionLabel = new QLabel(this);
    questionLabel->setFixedSize(1000,20);
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

    connect(submitButton, &QPushButton::clicked, this, &QuizTre::handleAnswer);

    setLayout(layout);
    loadQuestion();  // Загружаем первый вопрос
}

void QuizTre::loadQuestion() {
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

void QuizTre::handleAnswer() {
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
