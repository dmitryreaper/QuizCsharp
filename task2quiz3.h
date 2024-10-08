#ifndef TASK2QUIZ3_H
#define TASK2QUIZ3_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QVector>
#include <QLayout>

class Task2Quiz3 : public QWidget {
    Q_OBJECT

public:
    explicit Task2Quiz3(QWidget *parent = nullptr);

private:
    struct Question {
        QString text;
        QStringList options;
        int correctAnswerIndex;
    };

    QVector<Question> questions;      // Вектор вопросов
    int currentQuestionIndex;         // Индекс текущего вопроса
    int score;
    QLabel *questionLabel;            // Метка для отображения текста вопроса
    QLabel *progressLabel;
    QVector<QRadioButton*> optionButtons;  // Вектор кнопок для вариантов ответов
    QButtonGroup *buttonGroup;        // Группа кнопок для управления переключением
    QPushButton *submitButton;        // Кнопка для отправки ответа


    void setupQuestions();            // Метод для добавления вопросов
    void createQuizInterface();       // Метод для создания интерфейса викторины
    void loadQuestion();              // Метод для загрузки текущего вопроса

private slots:
    void handleAnswer();              // Метод для обработки ответа на вопрос
};

#endif // QUIZ_H
