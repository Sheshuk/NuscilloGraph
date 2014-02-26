#include "gl_scene.h"
#include <QErrorMessage>
GL_scene::GL_scene(QWidget *parent) :
  QGLWidget(parent),prog(0)
{
}
//setter slots:
void GL_scene::set_Llims(double L0, double L1){
  prog->setUniformValue("Llims",float(L0),float(L1));
  repaint();
};
void GL_scene::set_Elims(double E0, double E1){
  prog->setUniformValue("Elims",float(E0),float(E1));
  repaint();
};
void GL_scene::set_dm2   (double val){
  prog->setUniformValue("dm2",float(val));
  repaint();
};
void GL_scene::set_sin2th(double val){
  prog->setUniformValue("Sin2Th",float(val));
  repaint();
};
//----------------------------------------
void GL_scene::initializeGL(){
  glClearColor(0.0, 0.0, 0.2, 0.0);
  glEnable(GL_DEPTH_TEST);
  prog=new QGLShaderProgram();
  prog->addShaderFromSourceFile(QGLShader::Vertex,  "../NuOsc/shader/nuosc.vert");
  prog->addShaderFromSourceFile(QGLShader::Fragment,"../NuOsc/shader/nuosc.frag");
  printf("Shaders are %s\n",prog->hasOpenGLShaderPrograms()?"ENABLED":"disabled");
  if(prog->link()==false){
      QErrorMessage* msg=new QErrorMessage();
      printf("LOG: %s\n",prog->log().data_ptr());
      msg->showMessage(prog->log()+" end_Log");
      msg->show();
    }
  prog->bind();
}

void GL_scene::resizeGL(int w, int h){
  // setup viewport, projection etc.:
  glViewport(0, 0, (GLint)w, (GLint)h);
}

void GL_scene::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glBegin(GL_QUADS);
  glColor4f(0.0,1.0,0.0,1.0);
  glTexCoord2f(0,0);
  glVertex3f(-1,-1,0);
  glColor4f(1.0,0.0,0.0,1.0);
  glTexCoord2f(1,0);
  glVertex3f( 1,-1,0);
  glColor4f(0.0,0.0,1.0,1.0);
  glTexCoord2f(1,1);
  glVertex3f( 1, 1,0);
  glColor4f(1.0,1.0,1.0,1.0);
  glTexCoord2f(0,1);
  glVertex3f(-1, 1,0);
  glEnd();
  glFlush();
}
