#include "openglwidget.h"

void OpenGLWidget::initializeGL()
{
    //调用内容初始化函数
    initializeOpenGLFunctions();
}
void OpenGLWidget::resizeGL(int w, int h)
{
    //当窗口大小改变时，调整界面坐标显示高度和宽度
    glViewport(0, 0, w, h);
}
void OpenGLWidget::paintGL()
{
    //清除之前图形并将背景设置为黑色（设置为黑色纯粹个人爱好！）
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_TEXTURE_2D);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0)
    glDisable(GL_CULL_FACE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenW, screenH, 0, -1, 1);
    //gluPerspective(30, (double)m_Width/m_Height, -1, 1);
    //gluLookAt(m_Width/2,200,m_Height/2, -m_Width/4,0,-m_Height/4, 0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4ub(255, 255, 255, 255);

    qint32 x = 60, y = 60, w = 200, h = 100;

    glBegin(GL_QUADS);
    //glTexCoord2f(0.0f, 0.0f);
    glVertex2i(x, y);
    //glTexCoord2f(1.0f, 0.0f);
    glVertex2i(x + w, y);
    //glTexCoord2f(1.0f, 1.0f);
    glVertex2i(x + w, y + h);
    //glTexCoord2f(0.0f, 1.0f);
    glVertex2i(x, y + h);
    glEnd();

    qint32 x2 = 160, y2 = 360, w2 = 200, h2 = 100;

    glBegin(GL_TRIANGLES);
    //glTexCoord2f(0.0f, 0.0f);
    glVertex2i(x2 + (0.5 * w2), y2 + h2);
    //glTexCoord2f(1.0f, 1.0f);
    glVertex2i(x2, y2);
    //glTexCoord2f(0.0f, 1.0f);
    glVertex2i(x2 + w2, y2);
    glEnd();
}
