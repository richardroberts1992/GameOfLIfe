#include "lifewindow.h"
#include <GL/freeglut.h>
#include "GL/GL.h"
#include <GL/glut.h>
#include "lifegrid.h"
#include "QDebug"

LifeWindow::LifeWindow(QWidget *parent) : QOpenGLWidget(parent)
{
    mult=10;
    sliderTimerFrame=300;
    connect(&timer,SIGNAL(timeout()), this, SLOT(update()));
    connect(&stepTimer,SIGNAL(timeout()), this, SLOT(processNextStep()));
    timer.start(100);
    setupGrid();
}

void LifeWindow::paintGL()
{
    drawGrid();
}

void LifeWindow::initializeGL()
{
    setupView();
}

void LifeWindow::resizeGL(int width, int height)
{
    width;
    height;
    setupView();
}

void LifeWindow::drawGrid()
{
    setupView();
    for(int i =0;i<grid.size();i++){
        grid[i]->drawLifeNode();
    }
}

void LifeWindow::setupGrid()
{
    grid.clear();
    LifeGrid::setGridSizeX(16*mult);
    LifeGrid::setGridSizeY(9*mult);
    LifeGrid::setIncrement(10);
    int size = LifeGrid::getGridSizeX()*LifeGrid::getGridSizeY();
    for(int i=0;i<size;i++){
        bool alive=false;
        if(rand() < (RAND_MAX/2)){alive=true;}
        LifeNode *node = new LifeNode(i,alive);
        grid.push_back(node);
    }

    setupView();
}

void LifeWindow::setupView()
{
    glFlush();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    SLX = 0;
    SRX = LifeGrid::getGridSizeX()*LifeGrid::getIncrement();
    SUY = 0;
    SLY = LifeGrid::getGridSizeY()*LifeGrid::getIncrement();
    gluOrtho2D(SLX,SRX,SLY,SUY);

}

void LifeWindow::processNextStep()
{

    int size = grid.size();
    for(int i =0;i<size;i++){
        int count=0;
        if(checkN(grid[i])){count++;};
        if(checkNE(grid[i])){count++;};
        if(checkE(grid[i])){count++;};
        if(checkSE(grid[i])){count++;};
        if(checkS(grid[i])){count++;};
        if(checkSW(grid[i])){count++;};
        if(checkW(grid[i])){count++;};
        if(checkNW(grid[i])){count++;};

        if(grid[i]->getState()){
            if(count < 2 || count > 3){
                grid[i]->setNextState(false);
            }else{
               grid[i]->setNextState(true);
            }
        }else{
            if(count==3){
               grid[i]->setNextState(true);
            }
        }
    }
    for(int i =0;i<size;i++){
        grid[i]->setState(grid[i]->getNextState());
        grid[i]->setNextState(false);
    }
}

int LifeWindow::getMult() const
{
    return mult;
}

void LifeWindow::setMult(int value)
{
    mult = value;
}

int LifeWindow::getSliderTimerFrame() const
{
    return sliderTimerFrame;
}

void LifeWindow::setSliderTimerFrame(int value)
{
    sliderTimerFrame = value;
}

void LifeWindow::killAllNodes()
{
    for(int i =0;i<grid.size();i++){
        grid[i]->setState(false);
        grid[i]->setNextState(false);
    }

}

void LifeWindow::randomlyPopulateNodes()
{
    for(int i =0;i<grid.size();i++){
        bool alive=false;
        if(rand() < (RAND_MAX/2)){alive=true;}
        grid[i]->setState(alive);
        grid[i]->setNextState(false);
    }
}

void LifeWindow::startTimer()
{
    stepTimer.start(sliderTimerFrame);
}

void LifeWindow::endTimer()
{
    stepTimer.stop();
}
bool LifeWindow::checkN(LifeNode* node)
{
     int nIndex = LifeGrid::coordToIndex(node->getXPos(),node->getYPos()-1);
     if(nIndex>grid.size()-1){return false;}
     if(nIndex<0){return false;}
     if(grid[nIndex]->getState()){
         return true;
     }else{
         return false;
     }

}

bool LifeWindow::checkNE(LifeNode* node)
{
    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos()-1);

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkE(LifeNode* node)
{

    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos());

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkSE(LifeNode* node)
{

    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos()+1);

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkS(LifeNode* node)
{

    int nIndex = LifeGrid::coordToIndex(node->getXPos(),node->getYPos()+1);

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkSW(LifeNode* node)
{
    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos()+1);

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkW(LifeNode* node)
{

    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos());

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkNW(LifeNode* node)
{

    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos()-1);

    if(nIndex>grid.size()-1){return false;}
    if(nIndex<0){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

void LifeWindow::mousePressEvent(QMouseEvent *event)
{

    double x = event->x();
    double y = event->y();
    double xRatio = (double)x/width();
    double yRatio = (double)y/height();
    int xPos=(int)LifeGrid::getGridSizeX()*xRatio;
    int yPos=(int)LifeGrid::getGridSizeY()*yRatio;

    int index = LifeGrid::coordToIndex(xPos,yPos);
    grid[index]->setState(!grid[index]->getState());
    //width()

}
