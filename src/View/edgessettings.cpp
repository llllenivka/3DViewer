#include "edgessettings.h"

namespace s21 {
EdgesSettings::EdgesSettings(QWidget *parent) {
  label = new QLabel("EDGES", parent);
  thickness = new QSlider(Qt::Horizontal, parent);
  color = new QPushButton("color", parent);
  type = new QCheckBox("   dashed", parent);

  thickness->setRange(1, 50);
  thickness->setValue(1);

  this->setStyle();
}

void EdgesSettings::setStyle() {
  QFont textFont("Helvetica Neue", 14);
  label->setFont(textFont);
  label->setAlignment(Qt::AlignCenter);
  label->setStyleSheet(
      "color: rgb(166, 160, 163);"
      "border-right: 0px;");

  thickness->setStyleSheet(SLIDER_STYLE);

  type->setFont(textFont);
  type->setStyleSheet(
      "color: rgb(32,32,32);"
      "background-color: rgb(90, 90, 90);"
      "border-radius: 5px;");

  color->setFont(textFont);
  color->setStyleSheet(
      "QPushButton {"
      "  color: rgb(32,32,32);"
      "  background-color: rgb(90, 90, 90);"
      "  border-radius: 5px;"
      "}"
      "QPushButton::pressed {"
      "  background: rgb(150, 150, 150);"
      "}");
}

void EdgesSettings::setGeometry(float ax, float ay, float aw, float ah,
                                float space) {
  label->setGeometry(ax, ay, aw, ah);
  ay += space;
  thickness->setGeometry(ax, ay, aw, 10);
  ay += 0.75 * space;
  type->setGeometry(ax, ay, aw, ah);
  ay += space;
  color->setGeometry(ax, ay, aw, ah);
}

}  // namespace s21
