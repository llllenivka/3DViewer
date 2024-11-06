#include "controller.h"

namespace s21 {

std::vector<std::vector<float>> Controller::getVertices() { return vertices; }

std::vector<std::vector<int>> Controller::getFaces() { return faces; }

void Controller::doMove(std::vector<std::vector<float>> &vertices, float x,
                        float y, float z) {
  Moving::Data date;
  date.x = x;
  date.y = y;
  date.z = z;
  Moving move;
  move.changing(vertices, date);
}

void Controller::doRotateX(std::vector<std::vector<float>> &vertices,
                           float angle) {
  RotationX::Data data;
  data.angle = angle;
  RotationX rotate;
  rotate.changing(vertices, data);
}

void Controller::doRotateY(std::vector<std::vector<float>> &vertices,
                           float angle) {
  RotationY::Data data;
  data.angle = angle;
  RotationY rotate;
  rotate.changing(vertices, data);
}

void Controller::doRotateZ(std::vector<std::vector<float>> &vertices,
                           float angle) {
  RotationZ::Data data;
  data.angle = angle;
  RotationZ rotate;
  rotate.changing(vertices, data);
}

void Controller::doScale(std::vector<std::vector<float>> &vertices,
                         float scale) {
  Scale::Data data;
  data.x = scale;
  data.y = scale;
  data.z = scale;
  Scale do_scale;
  do_scale.changing(vertices, data);
}

}  // namespace s21
