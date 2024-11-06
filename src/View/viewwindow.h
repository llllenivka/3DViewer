#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QMainWindow>

#include "settingswidgets.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewWindow;
}
QT_END_NAMESPACE

namespace s21 {

class ViewWindow : public QMainWindow {
  Q_OBJECT

 public:
  ViewWindow(QWidget *parent = nullptr);
  ~ViewWindow();

 private:
  Ui::ViewWindow *ui;
  QGridLayout *widgetLayout;
};

}  // namespace s21

#endif  // VIEWWINDOW_H
