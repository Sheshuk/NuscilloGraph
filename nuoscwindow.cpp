#include <QDockWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDial>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>

#include "nuoscwindow.h"
#include "gl_scene.h"
#include "matrixwidget.h"
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
  return LimBox;
}

QDockWidget *NuOscWindow::make_osc_box(){
   OscBox=new QDockWidget("Oscillation parameters");
   QGroupBox* grp=new QGroupBox();
   OscBox->setWidget(grp);
   //make controls for osc parameters
   QVBoxLayout* vb=new QVBoxLayout();
   grp->setLayout(vb);

   QDoubleSpinBox* dm21_c=new QDoubleSpinBox();
   dm21_c->setPrefix(tr("\xCE\x94m\xC2\xB2 21= "));
   dm21_c->setSuffix(tr(" eV2"));
   dm21_c->setDecimals(5);
   dm21_c->setMinimum(0);
   dm21_c->setMaximum(1);
   dm21_c->setSingleStep(1e-5);
   vb->addWidget(dm21_c);

   QDoubleSpinBox* dm31_c=new QDoubleSpinBox();
   dm31_c->setPrefix(tr("\xCE\x94m\xC2\xB2 31= "));
   dm31_c->setSuffix(tr(" eV2"));
   dm31_c->setDecimals(5);
   dm31_c->setMinimum(0);
   dm31_c->setMaximum(1);
   dm31_c->setSingleStep(1e-5);
   vb->addWidget(dm31_c);

   QDoubleSpinBox* dm23_c=new QDoubleSpinBox();
   dm23_c->setPrefix(tr("\xCE\x94m\xC2\xB2 23= "));
   dm23_c->setSuffix(tr(" eV2"));
   dm23_c->setEnabled(false);
   dm23_c->setDecimals(5);
   dm23_c->setMinimum(-5);
   dm23_c->setMaximum( 5);

   connect(dm21_c,SIGNAL(valueChanged(double)),Display,SLOT(set_dm21(double)));
   connect(dm31_c,SIGNAL(valueChanged(double)),Display,SLOT(set_dm31(double)));
   connect(Display,SIGNAL(dm23_changed(double)),dm23_c,SLOT(setValue(double)));

   dm21_c->setValue(8e-5);
   dm31_c->setValue(2.3e-3);
   vb->addWidget(dm23_c);

   QGroupBox* thetas=new QGroupBox("Mixing angles");
   {
     QHBoxLayout* hb=new QHBoxLayout();
     thetas->setLayout(hb);
     QDial* th12=new QDial();
     th12->setMaximum(-180);
     th12->setMaximum( 180);
     th12->setWrapping(true);
     hb->addWidget(th12);

     QDial* th13=new QDial();
     th13->setMaximum(-180);
     th13->setMaximum( 180);
     th13->setWrapping(true);
     hb->addWidget(th13);

     QDial* th23=new QDial();
     th23->setMaximum(-180);
     th23->setMaximum( 180);
     th23->setWrapping(true);
     hb->addWidget(th23);

     connect(th12,SIGNAL(valueChanged(int)),Display,SLOT(set_th12(int)));
     connect(th13,SIGNAL(valueChanged(int)),Display,SLOT(set_th13(int)));
     connect(th23,SIGNAL(valueChanged(int)),Display,SLOT(set_th23(int)));

     th12->setValue(12);
     th13->setValue(8);
     th23->setValue(45);
   }

   vb->addWidget(thetas);

   QGroupBox* hierarchy=new QGroupBox;
   {
     QHBoxLayout* hb=new QHBoxLayout();
     hierarchy->setLayout(hb);
     QRadioButton* nh=new QRadioButton("NH");
     hb->addWidget(nh);
     QRadioButton* ih=new QRadioButton("IH");
     hb->addWidget(ih);
     nh->setChecked(true);
     connect(nh,SIGNAL(toggled(bool)),Display,SLOT(set_hierarchy(bool)));
   }
   vb->addWidget(hierarchy);
   QComboBox* nu_alpha=new QComboBox();
   nu_alpha->addItem(tr("\xCE\xBD_e"));
   nu_alpha->addItem(tr("\xCE\xBD_\xCE\xBC"));
   nu_alpha->addItem(tr("\xCE\xBD_\xCF\x84"));
   connect(nu_alpha,SIGNAL(currentIndexChanged(int)),Display,SLOT(set_nu_alpha(int)));
   vb->addWidget(nu_alpha);
   vb->addStretch(1);

   MatrixWidget* matr=new MatrixWidget();
   connect(Display,SIGNAL(V_changed(QMatrix4x4&)),matr,SLOT(set_matrix(QMatrix4x4&)));
   vb->addWidget(matr);
   return OscBox;
}

