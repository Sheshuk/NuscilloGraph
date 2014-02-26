#include <QDockWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDial>
#include <QDoubleSpinBox>
#include "nuoscwindow.h"
#include "gl_scene.h"

const char* _delta_="\xCE\x94";
const char* _theta_="\xCE\xB8";
const char* _sqr_="\xC2\xB2";
NuOscWindow::NuOscWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setWindowTitle(tr("NUScilloScope"));
  Display=new GL_scene();
  setCentralWidget(Display);
  setMinimumSize(400,400);
  addDockWidget(Qt::LeftDockWidgetArea,make_osc_box());
  addDockWidget(Qt::RightDockWidgetArea,make_lim_box());
}

NuOscWindow::~NuOscWindow()
{
  
}

QDockWidget *NuOscWindow::make_lim_box(){
  LimBox=new QDockWidget("Limits");
  QVBoxLayout* vb=new QVBoxLayout();
  //make controls for osc parameters
  LimBox->setLayout(vb);
  return LimBox;
}

QDockWidget *NuOscWindow::make_osc_box(){
   OscBox=new QDockWidget("Oscillation parameters");
   QGroupBox* grp=new QGroupBox();
   OscBox->setWidget(grp);
   //make controls for osc parameters
   QVBoxLayout* vb=new QVBoxLayout();
   grp->setLayout(vb);

   QDoubleSpinBox* dm2_c=new QDoubleSpinBox();
   dm2_c->setPrefix(tr("\xCE\x94m\xC2\xB2 = "));
   dm2_c->setSuffix(tr(" eV2"));
   dm2_c->setDecimals(5);
   dm2_c->setMinimum(0);
   dm2_c->setMaximum(1);
   dm2_c->setSingleStep(1e-4);
   dm2_c->setValue(3.2e-3);
   connect(dm2_c,SIGNAL(valueChanged(double)),Display,SLOT(set_dm2(double)));
   vb->addWidget(dm2_c);


   QDoubleSpinBox* sin2th_c=new QDoubleSpinBox();
   sin2th_c->setPrefix(tr("sin(2\xCE\xB8)\xC2\xB2="));
   sin2th_c->setSuffix("");
   sin2th_c->setDecimals(3);
   sin2th_c->setMinimum(0);
   sin2th_c->setMaximum(1);
   sin2th_c->setSingleStep(1e-2);
   sin2th_c->setValue(1.0);
   connect(sin2th_c,SIGNAL(valueChanged(double)),Display,SLOT(set_sin2th(double)));
   vb->addWidget(sin2th_c);

   vb->addStretch(1);
   return OscBox;
}

