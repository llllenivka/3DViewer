#include "viewwindow.h"

#include "ui_viewwindow.h"

namespace s21 {

ViewWindow::ViewWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ViewWindow) {
  setFixedSize(1500, 900);
  this->setStyleSheet("background-color:  rgb(32,32,32);");
  ui->setupUi(this);

  settingsWidgets *settings_ = new settingsWidgets(this);
  settings_->addWidgetsSettings();
}

ViewWindow::~ViewWindow() { delete ui; }

}  // namespace s21
