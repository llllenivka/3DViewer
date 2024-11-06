#include "getscreenshot.h"

namespace s21 {

void takeScreenshot() {
  //    Этот метод возвращает первый попавшийся монитор, помеченный протоколом
  //    XRandr как первичный.
  QScreen* scr = QGuiApplication::primaryScreen();
  if (scr) {
    QPixmap screensh = scr->grabWindow(0);
    screensh.save("screensh.jpg");
  }
}

}  // namespace s21
