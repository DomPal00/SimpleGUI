#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <iostream>
#include <QDialog>
#include <QGraphicsScene>

int max;
QColor color, bgColor;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    max = 1024;
    ui->progressBar->setMaximum(max);
    ui->spinBox->setMaximum(max);
    ui->spinBox->setMinimum(1);
    color = Qt::green;
    bgColor = Qt::red;
    ui->textEdit->setTextBackgroundColor(color);
    ui->textEdit->setPalette(QPalette(bgColor));
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(2);
    progress = scene->addRect(20, 220, 752, 90, pen, brush);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->progressBar->setValue(arg1);
    valueChange(arg1);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(((double)(value+1)/100)*max);
    ui->progressBar->setValue(((double)(value+1)/100)*max);
}

void MainWindow::valueChange(int value){
    QString s="";
    for(int i=0;i<value/(max/30);i++){
        s+=" ";
    }
    ui->textEdit->setText(s);


}

void MainWindow::on_pushButton_clicked()
{
    close();
}

