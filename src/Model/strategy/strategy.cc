#ifndef STRATEGY_CC
#define STRATEGY_CC

// gcc -Wall -Werror -Wextra -lstdc++ strategy.cc -o my

#include "strategy.h"

namespace s21 {

void TransformStrategy::centorid(std::vector<std::vector<float>> &vertices,
                                 Data *data) {
  for (const auto &vertex : vertices) {
    data->centerX += vertex[0];
    data->centerY += vertex[1];
    data->centerZ += vertex[2];
  }
  size_t numVertices = vertices.size();
  data->centerX /= numVertices;
  data->centerY /= numVertices;
  data->centerZ /= numVertices;
}

void RotationX::changing(std::vector<std::vector<float>> &vertices, Data data) {
  centorid(vertices, &data);
  float rad = data.angle * M_PI / 180.0f;
  float cos_x = cos(rad);
  float sin_x = sin(rad);

  for (size_t i = 0; i < vertices.size(); ++i) {
    float translatedY = vertices[i][1] - data.centerY;
    float translatedZ = vertices[i][2] - data.centerZ;

    float new_y = translatedY * cos_x - translatedZ * sin_x;
    float new_z = translatedY * sin_x + translatedZ * cos_x;

    vertices[i][1] = new_y + data.centerY;
    vertices[i][2] = new_z + data.centerZ;
  }
}

void RotationY::changing(std::vector<std::vector<float>> &vertices, Data data) {
  centorid(vertices, &data);
  float rad = data.angle * M_PI / 180.0f;
  float cos_y = cos(rad);
  float sin_y = sin(rad);

  for (size_t i = 0; i < vertices.size(); ++i) {
    float translatedX = vertices[i][0] - data.centerX;
    float translatedZ = vertices[i][2] - data.centerZ;

    float new_x = translatedX * cos_y - translatedZ * sin_y;
    float new_z = translatedX * sin_y + translatedZ * cos_y;

    vertices[i][0] = new_x + data.centerX;
    vertices[i][2] = new_z + data.centerZ;
  }
}

void RotationZ::changing(std::vector<std::vector<float>> &vertices, Data data) {
  centorid(vertices, &data);
  float rad = data.angle * M_PI / 180.f;
  float cos_z = cos(rad);
  float sin_z = sin(rad);

  for (size_t i = 0; i < vertices.size(); ++i) {
    float translatedX = vertices[i][0] - data.centerX;
    float translatedY = vertices[i][1] - data.centerY;

    float new_x = translatedX * cos_z - translatedY * sin_z;
    float new_y = translatedX * sin_z + translatedY * cos_z;

    vertices[i][0] = new_x + data.centerX;
    vertices[i][1] = new_y + data.centerY;
  }
}

void Moving::changing(std::vector<std::vector<float>> &vertices, Data data) {
  for (size_t i = 0; i < vertices.size(); i++) {
    std::vector<float> &vertex = vertices[i];
    vertex[0] += data.x;
    vertex[1] += data.y;
    vertex[2] += data.z;
  }
}

void Scale::changing(std::vector<std::vector<float>> &vertices, Data data) {
  for (size_t i = 0; i < vertices.size(); i++) {
    std::vector<float> &vertex = vertices[i];
    vertex[0] *= data.x;
    vertex[1] *= data.y;
    vertex[2] *= data.z;
  }
}

}  // namespace s21
#endif
