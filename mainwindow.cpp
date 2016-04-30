#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setValue(ui->openGLWidget->getMult());

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

void MainWindow::on_startTimerButton_clicked()
{
    ui->openGLWidget->startTimer();
}

void MainWindow::on_endTimerButton_clicked()
{
    ui->openGLWidget->endTimer();
}


void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    int val = (100-position)*10;
    ui->openGLWidget->setSliderTimerFrame(val);
    ui->openGLWidget->startTimer();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->openGLWidget->setMult(arg1);
    ui->openGLWidget->setupGrid();
}
