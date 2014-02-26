#ifndef GL_SCENE_H
#define GL_SCENE_H

#include <QGLWidget>
#include <QGLShaderProgram>


class GL_scene : public QGLWidget
{
  Q_OBJECT
public:
  explicit GL_scene(QWidget *parent = 0);
protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
signals:
  
public slots:
  void set_Llims(double L0, double L1);
  void set_Elims(double E0, double E1);
  void set_dm2   (double val);
  void set_sin2th(double val);
private:
  QGLShaderProgram *prog = 0;
};

#endif // GL_SCENE_H
