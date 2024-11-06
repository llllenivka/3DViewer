#ifndef READFILEINFO_H
#define READFILEINFO_H

#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>

namespace s21 {

#define STYLE_LABEL                       \
  "QLabel {"                              \
  "   background-color: rgb(32,32,32);"   \
  "   border: 1px solid rgb(90, 90, 90);" \
  "   color: rgb(90, 90, 90)"             \
  "}"

class ReadFileInfo : public QWidget {
 public:
  ReadFileInfo(QWidget *parent = nullptr);
  bool openFile();
  void setNewInfo(QString countV, QString countF);

  QString getFilePath();

 private:
  QLabel *fileNameLabel;
  QLabel *countVertecis;
  QLabel *countEdges;
  QString filePath;

  void setSettingsLabel(QLabel *label, int ax, int ay, int aw, int ah);

 private slots:
  void show_info(const QString &message);
};

}  // namespace s21

#endif  // READFILEINFO_H
