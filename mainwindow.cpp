#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->openGLWidget->setSizePolicy();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->openGLWidget->processNextStep();
}

void MainWindow::on_killButton_clicked()
{
    ui->openGLWidget->killAllNodes();
}

void MainWindow::on_randomButton_clicked()
{
    ui->openGLWidget->randomlyPopulateNodes();
}
