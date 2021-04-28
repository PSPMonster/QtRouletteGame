#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer(this);


public:
    int j = -1;
    int coins = 1000, spent;
    int time, randSpin, guess;
    bool gameStarted = false;
    bool guessedRight;
    QString s;

private slots:
    void on_pushButton_clicked();

    void shuffle();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void SetUpGui();
};
#endif // MAINWINDOW_H
