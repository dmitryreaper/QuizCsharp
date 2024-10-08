#ifndef TASK2QUIZ1_H
#define TASK2QUIZ1_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include <QMessageBox>

class Task2Quiz1 : public QWidget {
    Q_OBJECT

public:
    explicit Task2Quiz1(QWidget *parent = nullptr);

private:
    struct Question {
        QString text;
        QString correctAnswer;
    };

    QVector<Question> questions; // Список вопросов
    int currentQuestionIndex;    // Текущий индекс вопроса
    int score;                   // Очки пользователя
    int timeRemaining;           // Оставшееся время для ответа

    QLabel *progressLabel;       // Лейбл для отображения прогресса викторины
    QLabel *questionLabel;       // Лейбл для отображения текста вопроса
    QLabel *timerLabel;          // Лейбл для таймера
    QLineEdit *answerInput;      // Поле для ввода ответа
    QPushButton *submitButton;   // Кнопка для отправки ответа
    QTimer *questionTimer;       // Таймер для обратного отсчета

    void setupQuestions();
    void createQuizInterface();
    void loadQuestion();
    void handleAnswer();
    void updateTimer();
    void animateScoreIncrease();
};

#endif // TASK2QUIZ2_H
