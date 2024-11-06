#include "readfileinfo.h"

namespace s21 {

ReadFileInfo::ReadFileInfo(QWidget *parent) {
  fileNameLabel = new QLabel("Select file", parent);
  countVertecis = new QLabel("VERTECIS: 0", parent);
  countEdges = new QLabel("EDGES: 0", parent);

  setSettingsLabel(fileNameLabel, 500, 0, 300, 40);
  setSettingsLabel(countVertecis, 1100, 860, 200, 40);
  setSettingsLabel(countEdges, 1300, 860, 200, 40);
}

void ReadFileInfo::setSettingsLabel(QLabel *label, int ax, int ay, int aw,
                                    int ah) {
  QFont labelFont("Helvetica Neue", 12);

  label->setGeometry(ax, ay, aw, ah);
  label->setFont(labelFont);
  label->setStyleSheet(STYLE_LABEL);
}

bool ReadFileInfo::openFile() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open OBJ File"), tr("Object Files (*.obj);;All Files (*)"));
  if (filename.isEmpty()) {
    QMessageBox::warning(this, "Warning", "No file selected. Try again");
    return false;
  }
  try {
    QFileInfo fileInfo(filename);
    fileNameLabel->setText(fileInfo.fileName());
    filePath = filename;

    //        QByteArray file_bytes = filename.toUtf8();
    //        filePath = file_bytes.data();

  } catch (const std::exception &e) {
    QMessageBox::warning(
        this, "Warning",
        "Error loading model: " + QString::fromStdString(e.what()));
  }
  return true;
}

void ReadFileInfo::show_info(const QString &message) {
  QMessageBox::information(this, "Info", message);
}

QString ReadFileInfo::getFilePath() { return filePath; }

void ReadFileInfo::setNewInfo(QString countV, QString countF) {
  countVertecis->setText("VERTICES: " + countV);
  countEdges->setText("EDGES: " + countF);
}

}  // namespace s21
