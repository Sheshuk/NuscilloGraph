#include "matrixwidget.h"

#include <QGridLayout>
MatrixWidget::MatrixWidget(QWidget *parent) :
  QWidget(parent)
{
  QGridLayout* lay=new QGridLayout();
  for(int nx=0;nx<4;++nx){
    lay->setColumnMinimumWidth(nx,20);
    lay->setColumnStretch(nx,1.5);
    for(int ny=0;ny<4;++ny){
        labels[nx][ny]=new QLabel(".");
        lay->addWidget(labels[nx][ny],nx,ny);
      }
    }
  setLayout(lay);
}

 void MatrixWidget::set_matrix(QMatrix4x4& M){
   char num[6];
   for(int nx=0;nx<4;++nx)
     for(int ny=0;ny<4;++ny){
         sprintf(num,"%5.3f",M(nx,ny));
         labels[nx][ny]->setText(num);
       }
 }
