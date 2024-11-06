#include "glscene.h"

#include <iostream>

glScene::glScene(QWidget *parent)
    : QOpenGLWidget(parent), rB(0.2f), gB(0.2f), bB(0.2f) {
  edgeThickness = 1.0f;
}

void glScene::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glClearColor(32.0f / 255.0f, 32.0f / 255.0f, 32.0f / 255.0f, 1.0f);

  glMatrixMode(GL_PROJECTION);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLineWidth(edgeThickness);
}

void glScene::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
}

void glScene::paintGL() {
  glLoadIdentity();
  glRotatef(25.0f, 1.0f, 1.0f, 0.0f);
  glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
  glClearColor(background_color.redF(), background_color.greenF(),
               background_color.blueF(), 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (projectionType == ProjectionType::Central) {
    glFrustum(-1, 1, -1, 1, 1, 100);
  } else if (projectionType == ProjectionType::Parallel) {
    glOrtho(-60, 60, -60, 60, -100, 100);
    drawGrid();
  }

  drawEdges();
  drawVertex();

  glFlush();
}

void glScene::drawGrid() {
  float step = 5.0f;
  float range = 50.0f;

  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
  for (float z = -range; z <= range; z += step) {
    glVertex3f(-range, 0.0f, z);
    glVertex3f(range, 0.0f, z);
  }
  glEnd();

  glBegin(GL_LINES);
  for (float x = -range; x <= range; x += step) {
    glVertex3f(x, 0.0f, -range);
    glVertex3f(x, 0.0f, range);
  }
  glEnd();
}

void glScene::drawEdges() {
  glColor3f(edge_color.redF(), edge_color.greenF(), edge_color.blueF());

  glLineWidth(edgeThickness);

  if (dashedLinesEnabled == true) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  } else
    glDisable(GL_LINE_STIPPLE);

  for (size_t i = 0; i < faces.size(); ++i) {
    glBegin(GL_LINES);

    for (size_t index = 0; index < faces[i].size(); ++index) {
      int value = faces[i][index] - 1;
      glVertex3f(vertices[value][0], vertices[value][1], vertices[value][2]);
    }
    glEnd();
  }
  if (dashedLinesEnabled == true) glDisable(GL_LINE_STIPPLE);
  glLineWidth(1);
}

void glScene::drawVertex() {
  for (size_t i = 0; i < vertices.size(); ++i) {
    GLfloat x = vertices[i][0];
    GLfloat y = vertices[i][1];
    GLfloat z = vertices[i][2];
    glColor3f(vertex_color.redF(), vertex_color.greenF(), vertex_color.blueF());

    switch (displayMethod) {
      case VertexDisplayMethod::Circle:
        draw_circle(x, y, z, vertex_size);
        break;

      case VertexDisplayMethod::Square:
        draw_square(x, y, z, vertex_size);
        break;

      case VertexDisplayMethod::None:
      default:
        break;
    }
  }
}

void glScene::draw_circle(GLfloat x, GLfloat y, GLfloat z, GLfloat size) {
  int num_segments = 30;
  GLfloat angle_step = 2.0f * M_PI / num_segments;
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= num_segments; ++i) {
    GLfloat angle = i * angle_step;
    glVertex3f(x + (size / 10) * cos(angle), y + (size / 10) * sin(angle), z);
  }
  glEnd();
}

void glScene::draw_square(GLfloat x, GLfloat y, GLfloat z, GLfloat size) {
  GLfloat half_size = size / 15.0f;
  glBegin(GL_QUADS);
  glVertex3f(x - half_size, y - half_size, z);
  glVertex3f(x + half_size, y - half_size, z);
  glVertex3f(x + half_size, y + half_size, z);
  glVertex3f(x - half_size, y + half_size, z);

  glEnd();
}

/* --- edges --- */

void glScene::setDashedLinesEnabled(bool enabled) {
  dashedLinesEnabled = enabled;
  update();
}

void glScene::set_edge_color(const QColor &color) {
  edge_color = color;
  update();
}

void glScene::set_edge_widthness(float thickness) {
  edgeThickness = thickness;
  update();
}

/* --- vertex --- */

void glScene::set_vertex_color(const QColor &color) {
  vertex_color = color;
  update();
}

void glScene::set_vertex_size(float size) {
  vertex_size = size;
  update();
}

void glScene::change_background_color(const QColor &color) {
  background_color = color;
  update();
}

void glScene::update_background_color() {
  QOpenGLContext *context = QOpenGLContext::currentContext();
  if (context) {
    QOpenGLFunctions *func = context->functions();
    GLfloat r = background_color.redF();
    GLfloat g = background_color.greenF();
    GLfloat b = background_color.blueF();
    GLfloat a = background_color.alphaF();

    func->glClearColor(r, g, b, a);
    update();
  } else {
    qDebug() << "Error: No OpenGL context available.";
  }
}
