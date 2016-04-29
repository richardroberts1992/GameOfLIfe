#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H
#include <QOpenGLWidget>
#include <QVector>
#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include "lifeNode.h"
class LifeWindow : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit LifeWindow(QWidget *parent = 0);

    void paintGL();
    void initializeGL();
    void drawGrid();
    QVector<LifeNode*> grid;

    //processNextStep
    void processNextStep();

    void killAllNodes();
    void randomlyPopulateNodes();

private:
    QTimer timer;
    double SLX;
    double SRX;
    double SUY;
    double SLY;


    //Neighbour Check
    bool checkN(LifeNode* node);
    bool checkNE(LifeNode* node);
    bool checkE(LifeNode* node);
    bool checkSE(LifeNode* node);
    bool checkS(LifeNode* node);
    bool checkSW(LifeNode* node);
    bool checkW(LifeNode* node);
    bool checkNW(LifeNode* node);

protected:
    void mousePressEvent(QMouseEvent *event);


};

#endif // LIFEWINDOW_H
