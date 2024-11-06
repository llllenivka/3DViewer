#include "slidersettings.h"

namespace s21 {

SliderSettings::SliderSettings(QWidget *parent) {
  parent_ = parent;

  xMoveSlider = new QSlider(Qt::Horizontal, parent);
  yMoveSlider = new QSlider(Qt::Horizontal, parent);
  zMoveSlider = new QSlider(Qt::Horizontal, parent);

  xRotationSlider = new QSlider(Qt::Horizontal, parent);
  yRotationSlider = new QSlider(Qt::Horizontal, parent);
  zRotationSlider = new QSlider(Qt::Horizontal, parent);

  Scale = new QSlider(Qt::Horizontal, parent);
}

SliderSettings::~SliderSettings() {
  if (xMoveSlider) delete xMoveSlider;
  if (yMoveSlider) delete yMoveSlider;
  if (zMoveSlider) delete zMoveSlider;

  if (xRotationSlider) delete xRotationSlider;
  if (yRotationSlider) delete yRotationSlider;
  if (zRotationSlider) delete zRotationSlider;

  if (Scale) delete Scale;

  if (labelRotation) delete labelRotation;
  if (labelMovement) delete labelMovement;

  if (labelRotationX) delete labelRotationX;
  if (labelRotationY) delete labelRotationY;
  if (labelRotationZ) delete labelRotationZ;

  if (labelMovementX) delete labelMovementX;
  if (labelMovementY) delete labelMovementY;
  if (labelMovementZ) delete labelMovementZ;

  if (labelScale) delete labelScale;
}

void SliderSettings::addLabels(int ax, int ay, int aw, int ah, int space) {
  labelMovement = new QLabel("SHIFT", parent_);

  labelMovementX = new QLabel("X", parent_);
  labelMovementY = new QLabel("Y", parent_);
  labelMovementZ = new QLabel("Z", parent_);

  labelRotation = new QLabel("ROTATE", parent_);

  labelRotationX = new QLabel("X", parent_);
  labelRotationY = new QLabel("Y", parent_);
  labelRotationZ = new QLabel("Z", parent_);

  labelScale = new QLabel("SCALE", parent_);

  setSettingsLabel(labelMovement, ax, ay - 25, aw, ah + 2);

  setSettingsLabel(labelMovementX, ax - 30, ay - 1, ah + 2, ah + 2);
  ay += space;
  setSettingsLabel(labelMovementY, ax - 30, ay - 1, ah + 2, ah + 2);
  ay += space;
  setSettingsLabel(labelMovementZ, ax - 30, ay - 1, ah + 2, ah + 2);

  ay += 1.5 * space;

  setSettingsLabel(labelRotation, ax, ay - 25, aw, ah + 2);

  setSettingsLabel(labelRotationX, ax - 30, ay - 1, ah + 2, ah + 2);
  ay += space;
  setSettingsLabel(labelRotationY, ax - 30, ay - 1, ah + 2, ah + 2);
  ay += space;
  setSettingsLabel(labelRotationZ, ax - 30, ay - 1, ah + 2, ah + 2);

  ay += 1.5 * space;

  setSettingsLabel(labelScale, ax, ay - 25, aw, ah + 2);
}

void SliderSettings::setStyleSlider(const QString style) {
  xMoveSlider->setStyleSheet(style);
  yMoveSlider->setStyleSheet(style);
  zMoveSlider->setStyleSheet(style);

  xRotationSlider->setStyleSheet(style);
  yRotationSlider->setStyleSheet(style);
  zRotationSlider->setStyleSheet(style);

  Scale->setStyleSheet(style);
}

void SliderSettings::setSettingsLabel(QLabel *label, int ax, int ay, int aw,
                                      int ah) {
  QFont labelFont("Helvetica Neue", 14);

  label->setGeometry(ax, ay - 5, aw, ah + 5);
  label->setFont(labelFont);
  label->setAlignment(Qt::AlignCenter);
  label->setStyleSheet(
      "color: rgb(166, 160, 163);"
      "border-right: 0px;");
}

void SliderSettings::setGeometry(int ax, int ay, int aw, int ah, int space) {
  addLabels(ax, ay, aw, ah, space);
  xMoveSlider->setGeometry(ax, ay, aw, ah);
  ay += space;
  yMoveSlider->setGeometry(ax, ay, aw, ah);
  ay += space;
  zMoveSlider->setGeometry(ax, ay, aw, ah);

  ay += 1.5 * space;

  xRotationSlider->setGeometry(ax, ay, aw, ah);
  ay += space;
  yRotationSlider->setGeometry(ax, ay, aw, ah);
  ay += space;
  zRotationSlider->setGeometry(ax, ay, aw, ah);

  ay += 1.5 * space;

  Scale->setGeometry(ax, ay, aw, ah);
}

void SliderSettings::setRangeMove(int min, int max) {
  xMoveSlider->setRange(min, max);
  yMoveSlider->setRange(min, max);
  zMoveSlider->setRange(min, max);
}

void SliderSettings::setRangeRotate(int min, int max) {
  xRotationSlider->setRange(min, max);
  yRotationSlider->setRange(min, max);
  zRotationSlider->setRange(min, max);
}

void SliderSettings::setRangeScale(int min, int max) {
  Scale->setRange(min, max);
}

void SliderSettings::setStartValue(const int valueMove, const int valueRotate,
                                   const int valueScale) {
  xMoveSlider->setValue(valueMove);
  yMoveSlider->setValue(valueMove);
  zMoveSlider->setValue(valueMove);

  xRotationSlider->setValue(valueRotate);
  yRotationSlider->setValue(valueRotate);
  zRotationSlider->setValue(valueRotate);

  Scale->setValue(valueScale);
}

}  // namespace s21
