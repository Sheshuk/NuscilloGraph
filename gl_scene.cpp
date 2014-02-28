#include "gl_scene.h"
#include <QErrorMessage>
GL_scene::GL_scene(QWidget *parent) :
  QGLWidget(parent),prog(0)
{
}
//setter slots:
void GL_scene::set_Llims(double L0, double L1){
  if(prog==NULL)return;
  prog->setUniformValue("Llims",float(L0),float(L1));
  repaint();
}
void GL_scene::set_Elims(double E0, double E1){
  if(prog==NULL)return;
  prog->setUniformValue("Elims",float(E0),float(E1));
  repaint();
}

void GL_scene::set_th12(double val){
  Rz12.setToIdentity();
  Rz12.rotate(val,0,0,1);
  upd_V();
}

void GL_scene::set_th23(double val){
  Rx23.setToIdentity();
  Rx23.rotate(val,1,0,0);
  upd_V();
}

void GL_scene::set_th13(double val){
  Ry13.setToIdentity();
  Ry13.rotate(val,0,1,0);
  upd_V();
}

void GL_scene::upd_dm(){
  if(prog==NULL)return;
  prog->setUniformValue("dm2",dm2[0],dm2[1],dm2[2]);
  repaint();
}

void GL_scene::set_nu_alpha(int nu_alpha){
  if(prog==NULL)return;
  prog->setUniformValue("nu_alpha",nu_alpha);
  repaint();
}

void GL_scene::upd_V(){
  if(prog==NULL)return;
  V=Rx23*Ry13*Rz12;
  prog->setUniformValue("V",V);
  repaint();
  emit V_changed(V);
}

//----------------------------------------
void GL_scene::initializeGL(){
  glClearColor(0.0, 0.0, 0.2, 0.0);
  glEnable(GL_DEPTH_TEST);
  prog=new QGLShaderProgram();
  prog->addShaderFromSourceFile(QGLShader::Vertex,  "shader/nuosc3.vert");
  prog->addShaderFromSourceFile(QGLShader::Fragment,"shader/nuosc3.frag");
  printf("Shaders are %s\n",prog->hasOpenGLShaderPrograms()?"ENABLED":"disabled");
  if(prog->link()==false){
      QErrorMessage* msg=new QErrorMessage();
      printf("LOG: %s\n",prog->log().data_ptr());
      msg->showMessage(prog->log()+" end_Log");
      msg->show();
    }
  prog->bind();
  upd_dm();
  upd_V();
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
