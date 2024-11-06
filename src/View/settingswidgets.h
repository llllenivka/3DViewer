#ifndef SETTINGSWIDGETS_H
#define SETTINGSWIDGETS_H

#include <QCoreApplication>
#include <QEventLoop>
#include <QLayout>
#include <QPainter>
#include <QSettings>
#include <QWidget>
//#include <QCloseEvent>

#include "../Controller/controller.h"
#include "edgessettings.h"
#include "glscene.h"
#include "readfileinfo.h"
#include "slidersettings.h"
#include "vertecissettings.h"

namespace s21 {

/* --------------- main widget settings --------------- */
#define SETTINGS_WIDGET_HEIGHT 900
#define SETTINGS_WIDGET_WIDTH 400
#define SETTINGS_WIDGET_STYLE                   \
  "QWidget{"                                    \
  "   background-color: rgb(41, 41, 41);"       \
  "   border-right: 1px solid rgb(90, 90, 90);" \
  "}"

#define BUTTON_STYLE                     \
  "QPushButton {"                        \
  "  color: rgb(32,32,32);"              \
  "  background-color: rgb(90, 90, 90);" \
  "  border-radius: 5px;"                \
  "}"                                    \
  "QPushButton::pressed {"               \
  "  background: rgb(150, 150, 150);"    \
  "}"

/* --------------- slider settings --------------- */
#define MOVE_SLIDER_AX 45
#define MOVE_SLIDER_AY 60
#define MOVE_SLIDER_WIDTH (SETTINGS_WIDGET_WIDTH - (2 * MOVE_SLIDER_AX))
#define MOVE_SLIDER_HEIGHT 10
#define SPACE_BTW_SLIDERS 40
#define RANGE_MOVE_MIN -50
#define RANGE_MOVE_MAX 50
#define RANGE_ROTATE_MIN 0
#define RANGE_ROTATE_MAX 720
#define RANGE_SCALE_MIN 500
#define RANGE_SCALE_MAX 5000

class settingsWidgets : public QWidget, public Controller {
 public:
  settingsWidgets(QWidget *parent = nullptr);
  ~settingsWidgets();
  void addWidgetsSettings();

 private:
  QWidget *settings;
  glScene *glWindow;
  ReadFileInfo *fileInfo;
  QPushButton *selectFileButton;

  SliderSettings *movingObjectSetting;

  EdgesSettings *edges;
  VertecisSettings *vert;

  QComboBox *typeProjection;
  QPushButton *colorBackground;

  QPushButton *saveScreen;
  QPushButton *saveGif;

  void memAlloc();
  void create_gif(const QString &fileName);
  void saveSettings();
  void loadSettings();

 private slots:
  void selectFileButton_clicked();

  void moveObject();
  void scaleObject();
  void xRotateObject();
  void yRotateObject();
  void zRotateObject();

  void change_edge_color();
  void dashed_lines_change();
  void change_edge_width(float thickness);

  void change_vertex_color();
  void displayMethodChanged(int index);
  void change_vertex_size(float size);

  void projection_type(int index);
  void colorBackground_clicked();

  void GetScreenshot();
  void GetGif_clicked();
};

}  // namespace s21

#endif  // SETTINGSWIDGETS_H
