#include "widgetanimation.h"

WidgetAnimation::WidgetAnimation(QObject *target, QByteArray propertyName,
                                 const QRect Geometry, QObject *parent) {
  this->animation_ = nullptr;
  this->ObjectGeometry_ = Geometry;
  this->target_ = target;
  this->propertyName_ = propertyName;
  this->parent_ = parent;
}

/************************************************/
/*  Creates an animation of a widget by moving  */
/*  and resizing it at a specified rate.        */
/************************************************/
void WidgetAnimation::addAnimation(QRect newGeometry) {
  if (animation_) {
    animation_->stop();
    delete animation_;
  }
  animation_ = new QPropertyAnimation(target_, propertyName_, parent_);
  animation_->setDuration(300);
  animation_->setStartValue(QRect(this->ObjectGeometry_));
  animation_->setEndValue(newGeometry);
  animation_->start();

  ObjectGeometry_ = newGeometry;
}
