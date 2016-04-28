#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H
#include <QOpenGLWidget>

class LifeWindow : public QOpenGLWidget
{
    Q_OBJECT
public:
    LifeWindow();

    void paintGL();
    void initializeGL();

};

#endif // LIFEWINDOW_H
