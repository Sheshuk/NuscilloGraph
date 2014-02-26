#include <QApplication>
#include <QTextCodec>
#include "nuoscwindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QTextCodec *utfCodec = QTextCodec::codecForName("UTF-8"); //creating new utf-8 codec
  QTextCodec::setCodecForTr(utfCodec);
  NuOscWindow w;
  w.show();
  
  return a.exec();
}
