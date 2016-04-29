#ifndef LIFEGRID_H
#define LIFEGRID_H
#include "QVector"

using namespace std;
class LifeGrid
{
public:
    LifeGrid();

    static int getGridSizeX();
    static void setGridSizeX(int value);
    static int getGridSizeY();
    static void setGridSizeY(int value);
    static int indexToXCoord(int index);
    static int indexToYCoord(int index);
    static int coordToIndex(int xPosition, int yPosition);
    static int getIncrement();
    static void setIncrement(int value);


private:
    static int gridSizeX;
    static int gridSizeY;
    static int increment;
};

#endif // LIFEGRID_H
