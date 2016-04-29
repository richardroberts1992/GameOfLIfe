#include "lifewindow.h"
#include <GL/freeglut.h>
#include "lifegrid.h"
#include "QDebug"

int mult = 10;

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
    qDebug() << "S";
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
