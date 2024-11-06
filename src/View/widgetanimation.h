#ifndef WIDGETANIMATION_H
#define WIDGETANIMATION_H

#include <QByteArray>
#include <QPropertyAnimation>
#include <QRect>

class WidgetAnimation : public QPropertyAnimation {
 public:
  WidgetAnimation(QObject *target, QByteArray propertyName,
                  const QRect ObjectGeometry, QObject *parent = nullptr);
  void addAnimation(QRect newGeometry);

 private:
  QRect ObjectGeometry_;
  QPropertyAnimation *animation_;
  QObject *target_;
  QByteArray propertyName_;
  QObject *parent_;
};

#endif  // WIDGETANIMATION_H
