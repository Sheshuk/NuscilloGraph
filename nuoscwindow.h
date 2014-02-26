#ifndef NUOSCWINDOW_H
#define NUOSCWINDOW_H

#include <QMainWindow>
class GL_scene;
class QGroupBox;

class NuOscWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  NuOscWindow(QWidget *parent = 0);
  ~NuOscWindow();
private:
  QDockWidget* make_osc_box();
  QDockWidget* make_lim_box();

  GL_scene* Display;
  QDockWidget* OscBox;
  QDockWidget* LimBox;
};

#endif // NUOSCWINDOW_H
