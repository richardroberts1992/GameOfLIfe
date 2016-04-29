#include "lifenode.h"
#include <QDebug>
LifeNode::LifeNode(int index, bool stateIn)
{
    xPos = LifeGrid::indexToXCoord(index);
    yPos = LifeGrid::indexToYCoord(index);
    //qDebug() << "intex = " << index << "   x " << xPos << "  y "<<yPos;
    state=stateIn;
    listIndex = index;
    populateGeometry();

}

int LifeNode::getXPos() const
{
    return xPos;
}

void LifeNode::setXPos(int value)
{
    xPos = value;
}

int LifeNode::getYPos() const
{
    return yPos;
}

void LifeNode::setYPos(int value)
{
    yPos = value;
}

int LifeNode::getListIndex() const
{
    return listIndex;
}

void LifeNode::setListIndex(int value)
{
    listIndex = value;
}


void LifeNode::setDead()
{
    state=false;
}

void LifeNode::setAlive()
{
    state=true;
}

bool LifeNode::getState()
{
    return state;
}

double LifeNode::getLX() const
{
    return LX;
}

void LifeNode::setLX(double value)
{
    LX = value;
}

double LifeNode::getRX() const
{
    return RX;
}

void LifeNode::setRX(double value)
{
    RX = value;
}

double LifeNode::getUY() const
{
    return UY;
}

void LifeNode::setUY(double value)
{
    UY = value;
}

double LifeNode::getLY() const
{
    return LY;
}

void LifeNode::setLY(double value)
{
    LY = value;
}

void LifeNode::populateGeometry()
{
//    qDebug() << "index = " << listIndex;
//    qDebug() << "xPos = " << xPos;
//    qDebug() << "yPos = " << yPos;

    int inc = LifeGrid::getIncrement();
    LX = ((xPos)*inc);
    RX = ((xPos+1)*inc);
    UY = ((yPos)*inc);
    LY = ((yPos+1)*inc);
}

void LifeNode::drawLifeNode()
{
    if(this->state){
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2d(LX,UY);
        glVertex2d(RX,UY);
        glVertex2d(RX,LY);
        glVertex2d(LX,LY);
        glEnd();

        glColor3f(0.0f,0.0f,0.f);
        glBegin(GL_LINE_LOOP);
        glVertex2d(LX,UY);
        glVertex2d(RX,UY);
        glVertex2d(RX,LY);
        glVertex2d(LX,LY);
        glEnd();
    }
}

bool LifeNode::getNextState() const
{
    return nextState;
}

void LifeNode::setNextState(bool value)
{
    nextState = value;
}

void LifeNode::setState(bool value)
{
    state = value;
}





