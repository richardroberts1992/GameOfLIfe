#include "lifewindow.h"
#include <GL/freeglut.h>
#include "lifegrid.h"
#include "QDebug"

int mult = 2;

LifeWindow::LifeWindow(QWidget *parent) : QOpenGLWidget(parent)
{

    connect(&timer,SIGNAL(timeout()), this, SLOT(update()));
    timer.start(100);
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
    qDebug() << "Finished Setup";

}

void LifeWindow::paintGL()
{
    drawGrid();
}

void LifeWindow::initializeGL()
{
    SLX = 0;
    SRX = LifeGrid::getGridSizeX()*LifeGrid::getIncrement();
    SUY = 0;
    SLY = LifeGrid::getGridSizeY()*LifeGrid::getIncrement();
    glOrtho(SLX,SRX,SLY,SUY,1,-1);
    glDisable(GL_DEPTH_TEST);
}

void LifeWindow::drawGrid()
{
    for(int i =0;i<grid.size();i++){
        grid[i]->drawLifeNode();
    }
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

        if(grid[i]){
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
    qDebug() << "seconds stage";
    for(int i =0;i<size;i++){
        grid[i]->setState(grid[i]->getNextState());
    }
}
bool LifeWindow::checkN(LifeNode* node)
{
     qDebug() << "N";
     int nIndex = LifeGrid::coordToIndex(node->getXPos(),node->getYPos()-1);
     qDebug() << "2";
     if(nIndex>grid.size()){return false;}
     qDebug() << "3";
     LifeNode* n = grid[nIndex];
     n->setState(true);
     qDebug() << n->getState();
     if(grid[nIndex]->getState()){
         qDebug() << "T";
         return true;
     }else{
         qDebug() << "F";
         return false;
     }

}

bool LifeWindow::checkNE(LifeNode* node)
{
    qDebug() << "NE";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos()-1);

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkE(LifeNode* node)
{
    qDebug() << "E";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos());

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkSE(LifeNode* node)
{
    qDebug() << "SE";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()+1,node->getYPos()+1);

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkS(LifeNode* node)
{
    qDebug() << "S";
    int nIndex = LifeGrid::coordToIndex(node->getXPos(),node->getYPos()+1);

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkSW(LifeNode* node)
{
    qDebug() << "SW";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos()+1);

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkW(LifeNode* node)
{
    qDebug() << "W";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos());

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}

bool LifeWindow::checkNW(LifeNode* node)
{
    qDebug() << "NW";
    int nIndex = LifeGrid::coordToIndex(node->getXPos()-1,node->getYPos()-1);

    if(nIndex>grid.size()){return false;}

    if(grid[nIndex]->getState()){
        return true;
    }else{
        return false;
    }
}
