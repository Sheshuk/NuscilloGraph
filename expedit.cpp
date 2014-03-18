#include "expedit.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <cstdio>
#include "mathutf.h"

ExpEdit::ExpEdit(QString Label,QString Suffix,QWidget *parent) :
  QWidget(parent),mantiss(0),exponent(0)
{
  QHBoxLayout* hb=new QHBoxLayout(this);
  QLabel *label=new QLabel(Label,this);
  sbox=new QDoubleSpinBox(this);
  sbox->setMaximum( 10.0);
  sbox->setMinimum(-10.0);
  sbox->setDecimals(4);
  sbox->setSingleStep(1e-3);
  expL=new QLabel("");
  sufL=new QLabel(Suffix);
  hb->addWidget(label);
  hb->addWidget(sbox);
  hb->addWidget(expL);
  hb->addWidget(sufL);
  hb->setAlignment(Qt::AlignLeft);
  setMantiss(0);
  setExponent(-1);
}

void ExpEdit::setMantiss(double mant){
  mantiss=mant;
  sbox->setValue(mantiss);
}

void ExpEdit::setExponent(int expo){
  exponent=expo;
  if(exponent==0){
      expL->setText("_");
      return;
  }
  char txt[3];
  sprintf(txt,"%d",exponent);
  QString s=QChar(utf::math::kTimes)+QString("10");
  s+=utf::Sup(txt);
  expL->setText(s);
}

