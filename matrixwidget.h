#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QFrame>
#include <QMatrix4x4>
#include <QLabel>

class MatrixWidget : public QFrame
{
  Q_OBJECT
public:
  explicit MatrixWidget(QString Title,QFrame *parent = 0);
private:
  QString TextFmt(double re, double im=0);

signals:

public slots:
  void set_matrix(QMatrix4x4& Re);
  void set_matrix(QMatrix4x4& Re,QMatrix4x4& Im);
  void set_colored(bool val){colored=val;}
  void set_title(QString Title){title_label->setText(Title);}
private:
  QLabel* labels[4][4];
  QLabel* title_label;
  //flags:
  bool colored;
};

#endif // MATRIXWIDGET_H
