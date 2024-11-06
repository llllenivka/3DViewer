#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/model.h"

namespace s21 {

class Controller : public Parser {
 public:
  std::vector<std::vector<float>> getVertices();
  std::vector<std::vector<int>> getFaces();

  void doMove(std::vector<std::vector<float>> &vertices, float x, float y,
              float z);
  void doRotateX(std::vector<std::vector<float>> &vertices, float angle);
  void doRotateY(std::vector<std::vector<float>> &vertices, float angle);
  void doRotateZ(std::vector<std::vector<float>> &vertices, float angle);
  void doScale(std::vector<std::vector<float>> &vertices, float scale);

 private:
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;
};

}  // namespace s21

#endif
