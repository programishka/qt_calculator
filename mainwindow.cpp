#include "mainwindow.h"
#include "ui_mainwindow.h"

QString previousNumber = "";
QString currentNumber = "";

QString operation = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->b0, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b1, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b2, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b3, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b4, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b5, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b6, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b7, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b8, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));
    connect(ui->b9, SIGNAL(clicked()), this, SLOT(onButtonNumberReleased()));

    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonNumberReleased()
{
    QString name = sender()->objectName();
    name = name.at(name.size()-1);
    currentNumber.append(name);
    ui->lcdNumber->display(QString(currentNumber));

}

void MainWindow::on_bAc_clicked()
{
    currentNumber = "";
    previousNumber = "";
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bAdd_clicked()
{
    previousNumber = QString::number(previousNumber.toDouble() + currentNumber.toDouble());
    currentNumber = "";
    operation = "add";
    ui->lcdNumber->display(QString(currentNumber));

}

void MainWindow::on_bEqual_clicked()
{
    if (operation == "add"){
        currentNumber = QString::number(previousNumber.toDouble() + currentNumber.toDouble());

    }else if (operation == "subtract"){
        currentNumber = QString::number(previousNumber.toDouble() - currentNumber.toDouble());

    }else if (operation == "multiply"){
        currentNumber = QString::number(previousNumber.toDouble() * currentNumber.toDouble());

    }else if (operation == "divide"){
        if (currentNumber.toDouble() == double(0)){
            currentNumber = "Err";
        } else {
            previousNumber = QString::number(previousNumber.toDouble() / currentNumber.toDouble());
        }

    } else if (operation == "percent"){
        previousNumber = QString::number(previousNumber.toDouble() / double(100) * currentNumber.toDouble());
    }

    operation = "";
    previousNumber = "";
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bSubtract_clicked()
{
    previousNumber = QString::number(previousNumber.toDouble() - currentNumber.toDouble());
    currentNumber = "";
    operation = "subtract";
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bMultiply_clicked()
{
    if (previousNumber.toDouble() == double(0)){
        previousNumber = currentNumber;
    }else{
       previousNumber = QString::number(previousNumber.toDouble() * currentNumber.toDouble());
    }

    currentNumber = "";
    operation = "multiply";
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bDividion_clicked()
{
    if (currentNumber.toDouble() == double(0)){
        currentNumber = "Err";
    } else {
        previousNumber = QString::number(previousNumber.toDouble() / currentNumber.toDouble());
        currentNumber = "";
    }

    operation = "divide";
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bDot_clicked()
{
    currentNumber.append(".");
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bAm_clicked()
{
    currentNumber = QString::number(-currentNumber.toDouble());
    ui->lcdNumber->display(QString(currentNumber));
}

void MainWindow::on_bPercent_clicked()
{
    previousNumber = QString::number(previousNumber.toDouble() / double(100) * currentNumber.toDouble());

    currentNumber = "";
    operation = "percent";
    ui->lcdNumber->display(QString(currentNumber));
}
