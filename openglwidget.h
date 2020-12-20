#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPushButton>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    explicit OpenGLWidget(QWidget *parent = 0) : screenW(640), screenH(480)
    {
        QPushButton *btn = new QPushButton();

        btn->setGeometry(200, 200, 200, 100);

        btn->setText(QStringLiteral("骚猫！"));
        btn->setFlat(true);
        btn->setAutoFillBackground(true);
        QPalette palette = btn->palette();
        palette.setColor(QPalette::Button,QColor(166,166,166,166));
        btn->setPalette(palette);

        btn->setParent(this);
    }

    void setScreenW(qint32 w)
    {
        screenW = w;
    }

    void setScreenH(qint32 h)
    {
        screenW = h;
    }

    qint32 getScreenW(void)
    {
        return screenW;
    }

    qint32 getScreenH(void)
    {
        return screenH;
    }

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    qint32 screenW;
    qint32 screenH;
};

#endif // OPENGLWIDGET_H
