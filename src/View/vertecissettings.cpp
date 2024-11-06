#include "vertecissettings.h"

namespace s21 {

VertecisSettings::VertecisSettings(QWidget *parent) {
  label = new QLabel("VERTICES", parent);
  size = new QSlider(Qt::Horizontal, parent);
  color = new QPushButton("color", parent);
  displayMethod = new QComboBox(parent);

  size->setRange(1, 50);
  size->setValue(1);

  displayMethod->addItem("        none");
  displayMethod->addItem("       circle");
  displayMethod->addItem("       square");

  this->setStyle();
}

void VertecisSettings::setStyle() {
  QFont textFont("Helvetica Neue", 14);
  label->setFont(textFont);
  label->setAlignment(Qt::AlignCenter);
  label->setStyleSheet(
      "color: rgb(166, 160, 163);"
      "border-right: 0px;");

  size->setStyleSheet(SLIDER_STYLE);

  displayMethod->setFont(textFont);
  displayMethod->setStyleSheet(
      "QComboBox { background-color: rgb(90, 90, 90); "
      "  border-radius: 5px;"
      "}"
      "QComboBox::drop-down { border: none; }"
      "QComboBox QAbstractItemView { background-color: rgb(90, 90, 90);; }");

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

void VertecisSettings::setGeometry(float ax, float ay, float aw, float ah,
                                   float space) {
  label->setGeometry(ax, ay, aw, ah);
  ay += space;
  size->setGeometry(ax, ay, aw, 10);
  ay += 0.75 * space;
  displayMethod->setGeometry(ax, ay, aw, ah);
  ay += space;
  color->setGeometry(ax, ay, aw, ah);
}

}  // namespace s21
