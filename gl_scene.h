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
  void dm23_changed(double);
  void V_changed(QMatrix4x4&);
public slots:
  void set_Emin(double val){Elims[0]=float(val); upd_Elim();}
  void set_Emax(double val){Elims[1]=float(val); upd_Elim();}
  void set_Lmin(double val){Llims[0]=float(val); upd_Llim();}
  void set_Lmax(double val){Llims[1]=float(val); upd_Llim();}
  void set_Llims(double v0, double v1){Elims[0]=v0; Elims[1]=v1; upd_Elim();}
  void set_Elims(double v0, double v1){Llims[0]=v0; Llims[1]=v1; upd_Llim();}

  void set_dm21  (double val){dm2[0]=float(val); calc_dm23();}
  void set_dm31  (double val){dm2[1]=float(val); calc_dm23();}
  void calc_dm23(){dm2[2]=NH?(dm2[0]-dm2[1]):(dm2[0]+dm2[1]); upd_dm(); emit dm23_changed(dm2[2]);}

  void set_hierarchy(bool nh){NH=nh; calc_dm23();}
  void set_th12(int val){set_th12(double(val));}
  void set_th23(int val){set_th23(double(val));}
  void set_th13(int val){set_th13(double(val));}
  void set_th12(double val);
  void set_th23(double val);
  void set_th13(double val);
  void set_nu_alpha(int NuAlpha);

private:
  void upd_dm();
  void upd_V();
  void upd_Elim();
  void upd_Llim();

private:
  int nu_alpha; //initial neutrino type
  float Elims[2];
  float Llims[2];
  QGLShaderProgram *prog;
  QMatrix4x4 V; //PMNS
  //MComplex Gd, Gm;
  QMatrix4x4 Rx23,Ry13,Rz12;
  bool NH; //normal hierarchy;
  float dm2[3];
};

#endif // GL_SCENE_H
