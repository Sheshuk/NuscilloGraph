#include "gl_scene.h"
#include <QErrorMessage>

QGLShaderProgram* MakeProgram(const char* vshade, const char* fshade){
  QGLShaderProgram* prog=new QGLShaderProgram();
  prog->addShaderFromSourceFile(QGLShader::Vertex,   vshade);
  prog->addShaderFromSourceFile(QGLShader::Fragment, fshade);
  printf("Shaders are %s\n",prog->hasOpenGLShaderPrograms()?"ENABLED":"disabled");
  if(prog->link()==false){
      QErrorMessage* msg=new QErrorMessage();
      printf("LOG: %s\n",prog->log().data_ptr());
      msg->showMessage(prog->log()+" end_Log");
      msg->show();
    }
  prog->bind();
  return prog;
}

GL_scene::GL_scene(QWidget *parent) :
    QGLWidget(parent),nu_alpha(0),prog(0)
{
    Elims[0]=0; Elims[1]=100;
    Llims[0]=100; Llims[1]=1000;
}
//setter slots:

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

void GL_scene::set_nu_alpha(int NuAlpha){
  nu_alpha=NuAlpha;
  if(prog==NULL)return;
  prog->setUniformValue("nu_alpha",nu_alpha);
  upd_V();
}

void GL_scene::upd_V(){
  if(prog==NULL)return;
  ReV=Rx23*Ry13*Rz12;
//  ImV= ...;
  QMatrix3x3 w;
    for(int nu_beta=0; nu_beta<3; nu_beta++)
       for(int i=0;i<3; i++)
           w (i,nu_beta)=ReV(nu_alpha,i)*ReV(nu_beta,i);


  prog->setUniformValue("w",w);
  repaint();
  V_changed(ReV);
}

void GL_scene::upd_Llim(){
  if(prog==NULL)return;
  prog->setUniformValue("Llim",Llims[0],Llims[1]);
  printf("l=[%f %f]\n",Llims[0],Llims[1]);
  repaint();
}
void GL_scene::upd_Elim(){
  if(prog==NULL)return;
  prog->setUniformValue("Elim",Elims[0]*1e-3,Elims[1]*1e-3);
  repaint();
}

//----------------------------------------
void GL_scene::initializeGL(){
  glClearColor(0.0, 0.0, 0.2, 0.0);
  glEnable(GL_DEPTH_TEST);
  prog=MakeProgram("shader/nuosc3.v120","shader/nuosc3.f120");
//  prog=MakeProgram("shader/nuosc3.vert","shader/nuosc3.frag");
  upd_dm();
  upd_V();
  upd_Llim();
  upd_Elim();
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
