#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>
#include <QMatrix4x4>
#include <QLabel>

class MatrixWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MatrixWidget(QWidget *parent = 0);
  
signals:

public slots:
  void set_matrix(QMatrix4x4& M);
private:
  QLabel* labels[4][4];
};

#endif // MATRIXWIDGET_H
