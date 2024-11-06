#include "settingswidgets.h"

#include "gif.h"

namespace s21 {

settingsWidgets::settingsWidgets(QWidget *parent) : QWidget(parent) {
  this->setGeometry(parent->geometry());
  this->memAlloc();
  loadSettings();

  /* --------------------- открытие файла --------------------  */
  connect(selectFileButton, &QPushButton::clicked, this,
          &settingsWidgets::selectFileButton_clicked);

  /* ------------------ перемещение по полю ------------------  */
  connect(movingObjectSetting->xMoveSlider, &QSlider::valueChanged, this,
          &settingsWidgets::moveObject);
  connect(movingObjectSetting->yMoveSlider, &QSlider::valueChanged, this,
          &settingsWidgets::moveObject);
  connect(movingObjectSetting->zMoveSlider, &QSlider::valueChanged, this,
          &settingsWidgets::moveObject);
  connect(movingObjectSetting->xRotationSlider, &QSlider::valueChanged, this,
          &settingsWidgets::xRotateObject);
  connect(movingObjectSetting->yRotationSlider, &QSlider::valueChanged, this,
          &settingsWidgets::yRotateObject);
  connect(movingObjectSetting->zRotationSlider, &QSlider::valueChanged, this,
          &settingsWidgets::zRotateObject);
  connect(movingObjectSetting->Scale, &QSlider::valueChanged, this,
          &settingsWidgets::scaleObject);

  /* -------------------- изменения ребер --------------------  */
  connect(edges->color, &QPushButton::clicked, this,
          &settingsWidgets::change_edge_color);
  connect(edges->type, &QCheckBox::stateChanged, this,
          &settingsWidgets::dashed_lines_change);
  connect(edges->thickness, &QSlider::valueChanged, this,
          &settingsWidgets::change_edge_width);

  /* -------------------- изменения вершин -------------------  */
  connect(vert->color, &QPushButton::clicked, this,
          &settingsWidgets::change_vertex_color);
  connect(vert->displayMethod,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &settingsWidgets::displayMethodChanged);
  connect(vert->size, &QSlider::valueChanged, this,
          &settingsWidgets::change_vertex_size);

  /* ----------------- изменение изображения -----------------  */
  connect(typeProjection, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &settingsWidgets::projection_type);
  connect(colorBackground, &QPushButton::clicked, this,
          &settingsWidgets::colorBackground_clicked);

  /* -----------------       сохранение      -----------------  */
  connect(saveScreen, &QPushButton::clicked, this,
          &settingsWidgets::GetScreenshot);
  connect(saveGif, &QPushButton::clicked, this,
          &settingsWidgets::GetGif_clicked);
}

settingsWidgets::~settingsWidgets() { saveSettings(); }

void settingsWidgets::memAlloc() {
  settings = new QWidget(this);
  glWindow = new glScene(this);
  fileInfo = new ReadFileInfo(this);
  selectFileButton = new QPushButton("SELECT", this);

  movingObjectSetting = new SliderSettings(settings);
  edges = new EdgesSettings(settings);
  vert = new VertecisSettings(settings);
  colorBackground = new QPushButton("background-color", settings);
  typeProjection = new QComboBox(settings);
  saveGif = new QPushButton("SAVE GIF", settings);
  saveScreen = new QPushButton("SAVE IMAGE", settings);
}

void settingsWidgets::addWidgetsSettings() {
  settings->setFixedSize(SETTINGS_WIDGET_WIDTH, SETTINGS_WIDGET_HEIGHT);
  settings->setStyleSheet(SETTINGS_WIDGET_STYLE);

  movingObjectSetting->setStyleSlider(SLIDER_STYLE);
  movingObjectSetting->setGeometry(MOVE_SLIDER_AX, MOVE_SLIDER_AY,
                                   MOVE_SLIDER_WIDTH, MOVE_SLIDER_HEIGHT,
                                   SPACE_BTW_SLIDERS);
  movingObjectSetting->setRangeMove(RANGE_MOVE_MIN, RANGE_MOVE_MAX);
  movingObjectSetting->setRangeRotate(RANGE_ROTATE_MIN, RANGE_ROTATE_MAX);
  movingObjectSetting->setRangeScale(1000, 20000);
  movingObjectSetting->setStartValue(0, 360, 1000);

  glWindow->setGeometry(SETTINGS_WIDGET_WIDTH, 0, 1100, 900);

  selectFileButton->setGeometry(400, 0, 100, 40);
  edges->setGeometry(40, 400, 150, 20, 35);
  vert->setGeometry(210, 400, 150, 20, 35);

  typeProjection->setGeometry(40, 600, 320, 25);
  colorBackground->setGeometry(40, 635, 320, 25);
  typeProjection->addItem("                   parallel");
  typeProjection->addItem("                   central");
  QFont textFont("Helvetica Neue", 14);
  typeProjection->setFont(textFont);
  colorBackground->setFont(textFont);

  typeProjection->setStyleSheet(
      "QComboBox { background-color: rgb(90, 90, 90); "
      "  border-radius: 5px;"
      "}"
      "QComboBox::drop-down { border: none; }"
      "QComboBox QAbstractItemView { background-color: rgb(90, 90, 90);; }");
  colorBackground->setStyleSheet(BUTTON_STYLE);

  saveGif->setStyleSheet(BUTTON_STYLE);
  saveScreen->setStyleSheet(BUTTON_STYLE);
  saveGif->setGeometry(40, 800, 150, 40);
  saveScreen->setGeometry(210, 800, 150, 40);
  saveGif->setFont(textFont);
  saveScreen->setFont(textFont);
}

/* --------------------------------------------------------- */
/* --------------------- открытие файла -------------------- */
/* --------------------------------------------------------- */

void settingsWidgets::selectFileButton_clicked() {
  if (fileInfo->openFile() == false) return;
  QString filename = fileInfo->getFilePath();
  QByteArray file_bytes = filename.toUtf8();
  char *filePath = file_bytes.data();

  if (filePath) {
    glWindow->vertices.clear();
    glWindow->faces.clear();
    movingObjectSetting->setStartValue(0, 360, 1000);
    this->parse(filePath, glWindow->vertices, glWindow->faces);
  } else
    return;

  if (glWindow->vertices.empty() || glWindow->faces.empty()) {
    throw std::runtime_error("Parsed model has no vertices or faces.");
  }

  fileInfo->setNewInfo(QString::number(glWindow->vertices.size()),
                       QString::number(glWindow->faces.size()));
  glWindow->update();
}

/* --------------------------------------------------------- */
/* ------------------ перемещение по полю ------------------ */
/* --------------------------------------------------------- */

void settingsWidgets::moveObject() {
  static float xOldMoveIndex;
  static float yOldMoveIndex;
  static float zOldMoveIndex;

  float x = xOldMoveIndex - movingObjectSetting->xMoveSlider->value();
  float y = yOldMoveIndex - movingObjectSetting->yMoveSlider->value();
  float z = zOldMoveIndex - movingObjectSetting->zMoveSlider->value();

  doMove(glWindow->vertices, x, y, z);

  glWindow->update();

  xOldMoveIndex = movingObjectSetting->xMoveSlider->value();
  yOldMoveIndex = movingObjectSetting->yMoveSlider->value();
  zOldMoveIndex = movingObjectSetting->zMoveSlider->value();
}

void settingsWidgets::scaleObject() {
  static float OldScaleIndex = 1000.0f;
  float newScale = ((movingObjectSetting->Scale->value() / 1000.0f) /
                    (OldScaleIndex / 1000.0f));
  doScale(glWindow->vertices, newScale);
  glWindow->update();

  OldScaleIndex = movingObjectSetting->Scale->value();
}

void settingsWidgets::xRotateObject() {
  static float xOldRotateIndex;
  float angle = movingObjectSetting->xRotationSlider->value() - xOldRotateIndex;
  doRotateX(glWindow->vertices, angle);
  glWindow->update();
  xOldRotateIndex = movingObjectSetting->xRotationSlider->value();
}

void settingsWidgets::yRotateObject() {
  static float yOldRotateIndex;
  float angle = movingObjectSetting->yRotationSlider->value() - yOldRotateIndex;
  doRotateY(glWindow->vertices, angle);
  glWindow->update();
  yOldRotateIndex = movingObjectSetting->yRotationSlider->value();
}

void settingsWidgets::zRotateObject() {
  static float zOldRotateIndex;
  float angle = movingObjectSetting->zRotationSlider->value() - zOldRotateIndex;
  doRotateZ(glWindow->vertices, angle);
  glWindow->update();
  zOldRotateIndex = movingObjectSetting->zRotationSlider->value();
}

/* --------------------------------------------------------- */
/* -------------------- изменения ребер -------------------- */
/* --------------------------------------------------------- */

void settingsWidgets::change_edge_color() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose Edge Color");
  if (color.isValid()) {
    glWindow->set_edge_color(color);
  }
}

void settingsWidgets::dashed_lines_change() {
  if (edges->type->isChecked() == true) {
    glWindow->setDashedLinesEnabled(true);
  } else
    glWindow->setDashedLinesEnabled(false);
  glWindow->update();
}

void settingsWidgets::change_edge_width(float thickness) {
  glWindow->setDashedLinesEnabled(edges->type->isChecked());
  glWindow->set_edge_widthness(thickness);
}

/* --------------------------------------------------------- */
/* -------------------- изменения вершин ------------------- */
/* --------------------------------------------------------- */

void settingsWidgets::change_vertex_color() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose Vertex Color");
  if (color.isValid()) {
    glWindow->set_vertex_color(color);
  }
}

void settingsWidgets::displayMethodChanged(int index) {
  glWindow->set_vertex_size(0.1);
  glWindow->set_vertex_color(Qt::green);

  switch (index) {
    case 0:
      glWindow->displayMethod = glScene::VertexDisplayMethod::None;
      break;
    case 1:
      glWindow->displayMethod = glScene::VertexDisplayMethod::Circle;
      break;
    case 2:
      glWindow->displayMethod = glScene::VertexDisplayMethod::Square;
      break;
  }
  glWindow->set_vertex_size(0.1);
  glWindow->update();
}

void settingsWidgets::change_vertex_size(float size) {
  glWindow->set_vertex_size(size);
}

/* --------------------------------------------------------- */
/* ----------------- изменения бэка        ----------------- */
/* --------------------------------------------------------- */

void settingsWidgets::colorBackground_clicked() {
  QColor color =
      QColorDialog::getColor(Qt::green, this, "Choose background color");
  if (color.isValid()) {
    qDebug() << color;
    glWindow->change_background_color(color);
  }
}

void settingsWidgets::projection_type(int index) {
  if (index) {
    glWindow->projectionType = glScene::ProjectionType::Central;
  } else {
    glWindow->projectionType = glScene::ProjectionType::Parallel;
  }
  glWindow->update();
}

/* --------------------------------------------------------- */
/* -----------------      сохранение       ----------------- */
/* --------------------------------------------------------- */

void settingsWidgets::GetScreenshot() {
  QPixmap screenshot = glWindow->grab();
  QString file_path = QFileDialog::getSaveFileName(this, "Save Screenshot", "",
                                                   "Images (*.png *.jpg)");
  if (!file_path.isEmpty()) {
    screenshot.save(file_path);
  }
}

void settingsWidgets::GetGif_clicked() {
  QString file_name = QFileDialog::getSaveFileName(
      this, tr("Save GIF"), QCoreApplication::applicationDirPath() + "/images",
      tr("GIF (*.gif)"));

  if (file_name.isEmpty()) {
    throw std::invalid_argument("Invalid input!");
    return;
  }

  create_gif(file_name);
}

void settingsWidgets::create_gif(const QString &fileName) {
  QImage img(glWindow->size(), QImage::Format_RGB32);
  QPainter painter(&img);
  QTime die_time;
  GifWriter gif;
  GifBegin(&gif, fileName.toLocal8Bit().data(), 640, 480, 10);

  for (int i = 0; i < 50; ++i) {
    saveGif->setText(QString::number(i / 10.0, 'f', 1) + "s");
    glWindow->render(&painter);
    QImage img640_480 = img.scaled(QSize(640, 480));
    GifWriteFrame(&gif, img640_480.bits(), 640, 480, 10);
    die_time = QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() <= die_time)
      QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
  }
  saveGif->setText("SAVE GIF");
  GifEnd(&gif);
}

void settingsWidgets::saveSettings() {
  QSettings settings("3DViewer", "3DViewer");
  settings.setValue("vertex_color", glWindow->vertex_color);
  settings.setValue("edge_color", glWindow->edge_color);
  settings.setValue("background_color", glWindow->background_color);
  settings.setValue("vertex_size", glWindow->vertex_size);
  settings.setValue("edge_thickness", glWindow->edgeThickness);
  settings.setValue("projectionType",
                    static_cast<int>(glWindow->projectionType));
  settings.setValue("displayMethod", static_cast<int>(glWindow->displayMethod));

  bool dashedEnabled = edges->type->isChecked();
  glWindow->setDashedLinesEnabled(dashedEnabled);

  settings.setValue("dashedLinesEnabled", dashedEnabled);
}

void settingsWidgets::loadSettings() {
  QSettings settings("3DViewer", "3DViewer");

  if (settings.contains("vertex_color")) {
    glWindow->set_vertex_color(settings.value("vertex_color").value<QColor>());
  }
  if (settings.contains("edge_color")) {
    glWindow->set_edge_color(settings.value("edge_color").value<QColor>());
  }
  if (settings.contains("background_color")) {
    glWindow->change_background_color(
        settings.value("background_color").value<QColor>());
  }
  if (settings.contains("vertex_size")) {
    glWindow->set_vertex_size(settings.value("vertex_size").toFloat());
  }
  if (settings.contains("edge_thickness")) {
    glWindow->edgeThickness = settings.value("edge_thickness").toFloat();
  }
  if (settings.contains("projectionType")) {
    glWindow->projectionType = static_cast<glScene::ProjectionType>(
        settings.value("projectionType").toInt());
  }
  if (settings.contains("displayMethod")) {
    glWindow->displayMethod = static_cast<glScene::VertexDisplayMethod>(
        settings.value("displayMethod").toInt());
  }

  if (settings.contains("dashedLinesEnabled")) {
    bool dashedEnabled = settings.value("dashedLinesEnabled").toBool();
    glWindow->setDashedLinesEnabled(dashedEnabled);
    edges->type->setChecked(dashedEnabled);  // Установим состояние чекбокса
  }
}

}  // namespace s21
