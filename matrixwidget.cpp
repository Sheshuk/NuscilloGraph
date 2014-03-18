#include "matrixwidget.h"
#include <QFont>
#include <QGridLayout>
#include <qmath.h>

MatrixWidget::MatrixWidget(QString Title, QFrame *parent) :
  QFrame(parent)
{
  setFrameShape(QFrame::StyledPanel);
  setFrameShadow(QFrame::Raised);

  QGridLayout* lay=new QGridLayout(this);
    title_label=new QLabel(Title);
    title_label->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    title_label->setFrameStyle(frameStyle());
    lay->addWidget(title_label,0,0,1,4,Qt::AlignCenter);
    for(int nx=0;nx<4;++nx){
  //    lay->setColumnMinimumWidth(nx,20);
  //    lay->setColumnStretch(nx,1.5);
    for(int ny=0;ny<4;++ny){
        labels[nx][ny]=new QLabel(TextFmt(0.0));
        labels[nx][ny]->setScaledContents(true);
        labels[nx][ny]->setFrameStyle(QFrame::StyledPanel|QFrame::Sunken);
        labels[nx][ny]->setBackgroundRole(QPalette::Base);
        lay->addWidget(labels[nx][ny],ny+1,nx,Qt::AlignJustify);
      }
    }
  setLayout(lay);
}

QString MatrixWidget::TextFmt(double re, double im){
//  if(val==0)return QString("0");
  char num[9];
  QString res;
  sprintf(num,"% 4.2f",re);
  if(!(re==0 && im!=0))res+=num;
  if(im!=0){
    sprintf(num,"%4.2f",qFabs(im));
    res+=(im>0)?"+":"-";
    res+="i";
    res+=num;
  }
  return res;

}
 void MatrixWidget::set_matrix(QMatrix4x4& Re, QMatrix4x4 &Im){
   for(int nx=0;nx<4;++nx)
     for(int ny=0;ny<4;++ny){
         labels[nx][ny]->setText(TextFmt(Re(nx,ny),Im(nx,ny)));
         int wght=abs(Re(nx,ny)*99)+1;
         QFont fnt(font()); fnt.setWeight(wght);
         labels[nx][ny]->setFont(fnt);
       }
 }

 void MatrixWidget::set_matrix(QMatrix4x4& Re){
   for(int nx=0;nx<4;++nx)
     for(int ny=0;ny<4;++ny){
         labels[nx][ny]->setText(TextFmt(Re(nx,ny)));
         int wght=abs(Re(nx,ny)*99)+1;
         QFont fnt(font()); fnt.setWeight(wght);
         labels[nx][ny]->setFont(fnt);
       }
}

