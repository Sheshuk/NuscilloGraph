#ifndef EXPEDIT_H
#define EXPEDIT_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>

class ExpEdit : public QWidget
{
  Q_OBJECT
public:
  explicit ExpEdit(QString Label="",QString Suffix="", QWidget *parent = 0);
signals:

public slots:
  void setMantiss(double mant);
  void setExponent(int exp);
private:
  QString MakeSuffix();
private:
    double mantiss;
    int exponent;

    QDoubleSpinBox *sbox;
    QLabel *expL;
    QLabel *sufL;
};

#endif // EXPEDIT_H
