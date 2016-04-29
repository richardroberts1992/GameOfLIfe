#include "lifewindow.h"
#include <GL/freeglut.h>
LifeWindow::LifeWindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

void LifeWindow::paintGL()
{

}

void LifeWindow::initializeGL()
{
    glClearColor(1,0,0,1);
    //glClear();
}

