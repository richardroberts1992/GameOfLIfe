#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H
#include <QOpenGLWidget>
#include <QVector>
#include <QTimer>
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

private:
    QTimer timer;
    double SLX;
    double SRX;
    double SUY;
    double SLY;
};

#endif // LIFEWINDOW_H
