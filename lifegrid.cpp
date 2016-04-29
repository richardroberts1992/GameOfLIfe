#include "lifegrid.h"
#include <QDebug>
int LifeGrid::gridSizeX;
int LifeGrid::gridSizeY;
int LifeGrid::increment;

LifeGrid::LifeGrid()
{
    increment = 10;
    gridSizeX = 16;
    gridSizeY = 9;

}

int LifeGrid::getGridSizeX()
{
    return gridSizeX;
}

void LifeGrid::setGridSizeX(int value)
{
    gridSizeX = value;
}

int LifeGrid::getGridSizeY()
{
    return gridSizeY;
}

void LifeGrid::setGridSizeY(int value)
{
    gridSizeY = value;
}

int LifeGrid::indexToXCoord(int index)
{
    if(index==0){
        return 0;
    }
    int x = (int)index%gridSizeX;
    return x;


}

int LifeGrid::indexToYCoord(int index)
{
    if(index==0){
        return 0;
    }
    int y = (int)index/gridSizeX;
    return y;
}

int LifeGrid::coordToIndex(int xPosition, int yPosition)
{
    int index = xPosition+(gridSizeX*yPosition);
    return index;
}

int LifeGrid::getIncrement()
{
    return increment;
}

void LifeGrid::setIncrement(int value)
{
    increment = value;
}


