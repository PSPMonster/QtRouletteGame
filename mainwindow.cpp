#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetUpGui();
    time = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(shuffle()));
    qsrand(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUpGui()
{
    this->setWindowTitle("Black Red White Casino");

    setAutoFillBackground(false);
    QPixmap pixmap=QPixmap(":/new/prefix1/images/bg.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(), QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    ui->lblHajs->setText(QString::number(coins));

    ui->right_3->setStyleSheet("QLabel { background-color : black; }");
    ui->right_2->setStyleSheet("QLabel { background-color : red; }");
    ui->right->setStyleSheet("QLabel { background-color : black; }");

    ui->middle->setStyleSheet("QLabel { background-color : red; }");

    ui->left->setStyleSheet("QLabel { background-color : black; }");
    ui->left_2->setStyleSheet("QLabel { background-color : red; }");
    ui->left_3->setStyleSheet("QLabel { background-color : black; }");
}


void MainWindow::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();
    spent = s.toInt();
    ui->lblHajs->setText(QString::number(coins - spent));
    randSpin = qrand() % 9 + 3;
    qDebug() << randSpin;
    timer->start(500);
    gameStarted = true;
    shuffle();
}


void MainWindow::shuffle()
{

   if (gameStarted == false)
   {
       timer->stop();
   }
   else
   {
       this->time++;
       if (time >= randSpin)
       {
           timer->stop();
           time = 0;

           if (guess == j)
           {
               QString s = ui->lineEdit->text();
               spent *= 2;
               coins += spent;
                   ui->lblHajs->setText(QString::number(coins));
           }
           else
           {
                   QString s = ui->lineEdit->text();
               coins -= spent;
                   ui->lblHajs->setText(QString::number(coins));
           }
       }

       if (j == 1)
       {
           //red = 1
           qDebug() << "j == 1";
           ui->right_3->setStyleSheet("QLabel { background-color : black; }");
           ui->right_2->setStyleSheet("QLabel { background-color : red; }");
           ui->right->setStyleSheet("QLabel { background-color : black; }");

           ui->middle->setStyleSheet("QLabel { background-color : red; }");

           ui->left->setStyleSheet("QLabel { background-color : black; }");
           ui->left_2->setStyleSheet("QLabel { background-color : red; }");
           ui->left_3->setStyleSheet("QLabel { background-color : black; }");

       }
       else
       {
           //black == -1
           qDebug() << "j == -1";
           ui->middle->setStyleSheet("QLabel { background-color : black; }");
           ui->right_3->setStyleSheet("QLabel { background-color : red; }");
           ui->left->setStyleSheet("QLabel { background-color : red; }");
           ui->left_2->setStyleSheet("QLabel { background-color : black; }");
           ui->right->setStyleSheet("QLabel { background-color : red; }");
           ui->right_2->setStyleSheet("QLabel { background-color : black; }");
           ui->left_3->setStyleSheet("QLabel { background-color : red; }");

       }
       j*= -1;
   }
}


//czarne
void MainWindow::on_pushButton_2_clicked()
{
    guess = -1;
}

//czerwone
void MainWindow::on_pushButton_3_clicked()
{
    guess = 1;
}
