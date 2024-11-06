#ifndef SLIDERSETTINGS_H
#define SLIDERSETTINGS_H

#include <QLabel>
#include <QSlider>
#include <iostream>

namespace s21 {

#define SLIDER_STYLE                       \
  "QSlider{"                               \
  "    border-right: 0px;"                 \
  "}"                                      \
  "QSlider::groove:horizontal {"           \
  "    border: 1px solid rgb(90, 90, 90);" \
  "    border-radius: 4px;"                \
  "    background: rgb(32,32,32);"         \
  "}"                                      \
  "QSlider::handle:horizontal {"           \
  "    background: rgb(90, 90, 90);"       \
  "    width: 20px;"                       \
  "    border-radius: 3px;"                \
  "}"                                      \
  "QSlider::handle:horizontal:pressed {"   \
  "    background: rgb(150, 150, 150);"    \
  "}"

class SliderSettings {
 public:
  SliderSettings(QWidget *parent = nullptr);
  ~SliderSettings();

  void addLabels(int ax, int ay, int aw, int ah, int space);

  void setStyleSlider(const QString style);
  void setSettingsLabel(QLabel *label, int ax, int ay, int aw, int ah);
  void setGeometry(int ax, int ay, int aw, int ah, int space);
  void setRangeMove(int min, int max);
  void setRangeRotate(int min, int max);
  void setRangeScale(int min, int max);
  void setStartValue(const int valueMove, const int valueRotate,
                     const int valueScale);

  // private:

  QWidget *parent_;

  /* -------- SLIDERS -------- */

  QSlider *xMoveSlider;
  QSlider *yMoveSlider;
  QSlider *zMoveSlider;

  QSlider *xRotationSlider;
  QSlider *yRotationSlider;
  QSlider *zRotationSlider;

  QSlider *Scale;

  /* -------- LABELS -------- */

  QLabel *labelRotation;
  QLabel *labelMovement;

  QLabel *labelRotationX;
  QLabel *labelRotationY;
  QLabel *labelRotationZ;

  QLabel *labelMovementX;
  QLabel *labelMovementY;
  QLabel *labelMovementZ;

  QLabel *labelScale;
};

}  // namespace s21

#endif  // SLIDERSETTINGS_H
