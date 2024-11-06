#ifndef GLSCENE_H
#define GLSCENE_H

#define GL_SILENCE_DEPRECATION

#include <OpenGl/gl.h>

#include <QColorDialog>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class glScene : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  glScene(QWidget *parent = nullptr);

  enum class ProjectionType { Parallel, Central };
  enum class VertexDisplayMethod { None, Circle, Square };

  ProjectionType projectionType = ProjectionType::Parallel;
  VertexDisplayMethod displayMethod = VertexDisplayMethod::None;

  QColor background_color;
  QColor edge_color{Qt::green};
  QColor vertex_color{Qt::green};

  float rB, gB, bB;
  float edgeThickness;
  float vertex_size;
  bool dashedLinesEnabled = false;

  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  void drawGrid();
  void drawEdges();
  void drawVertex();

  void change_background_color(const QColor &color);
  void update_background_color();

  void set_edge_color(const QColor &color);
  void set_edge_widthness(float thickness);
  void setDashedLinesEnabled(bool enabled);

  void set_vertex_color(const QColor &color);
  void set_vertex_size(GLfloat size);

  void draw_circle(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
  void draw_square(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
};

#endif  // GLSCENE_H
