#ifndef GETSCREENSHOT_H
#define GETSCREENSHOT_H

#include <QApplication>
#include <QPixmap>
#include <QScreen>
#include <QWidget>

namespace s21 {

class GetScreenShot : public QWidget {
 public:
  GetScreenShot(QWidget* parent = nullptr) : QWidget(parent) {
    setFixedSize(900, 900);
  }
  void takeScreenshot();
};

}  // namespace s21

#endif  // GETSCREENSHOT_H
