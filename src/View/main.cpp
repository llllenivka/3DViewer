#include <QApplication>

#include "viewwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ViewWindow w;
  w.setWindowTitle("3DViewer v2.0");
  w.show();
  return a.exec();
}
