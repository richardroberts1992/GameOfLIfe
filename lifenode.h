#ifndef LIFENODE_H
#define LIFENODE_H
#include "lifegrid.h"
#include "GL/freeglut.h"
class LifeNode
{
public:

    LifeNode(int index, bool stateIn);
    int getXPos() const;
    void setXPos(int value);
    int getYPos() const;
    void setYPos(int value);
    void setDead();
    void setAlive();
    bool getState();
    void setState(bool value);
    int getListIndex() const;
    void setListIndex(int value);

    double getLX() const;
    void setLX(double value);
    double getRX() const;
    void setRX(double value);
    double getUY() const;
    void setUY(double value);
    double getLY() const;
    void setLY(double value);

    void populateGeometry();
    void drawLifeNode();
    bool getNextState() const;
    void setNextState(bool value);



private:
    double LX;
    double RX;
    double UY;
    double LY;

    int listIndex;
    int xPos;
    int yPos;
    bool state;
    bool nextState;

};

#endif // LIFENODE_H
