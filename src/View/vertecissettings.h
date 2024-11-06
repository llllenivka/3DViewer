#ifndef VERTECISSETTINGS_H
#define VERTECISSETTINGS_H

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

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

class VertecisSettings {
 public:
  VertecisSettings(QWidget *parent = nullptr);
  void setGeometry(float ax, float ay, float aw, float ah, float space);

  QLabel *label;
  QSlider *size;
  QPushButton *color;
  QComboBox *displayMethod;

  void setStyle();
};

}  // namespace s21

#endif  // VERTECISSETTINGS_H
