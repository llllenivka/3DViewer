#ifndef STRATEGY_H
#define STRATEGY_H
#include <math.h>

#include <iostream>
#include <vector>

namespace s21 {

class TransformStrategy {
 public:
  struct Data {
    float angle = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float centerX = 0.0;
    float centerY = 0.0;
    float centerZ = 0.0;
  };

  TransformStrategy(){};
  virtual ~TransformStrategy() {}
  virtual void changing(std::vector<std::vector<float>> &vertices,
                        Data data) = 0;
  void centorid(std::vector<std::vector<float>> &vertices, Data *data);
};

class RotationX : public TransformStrategy {
 public:
  void changing(std::vector<std::vector<float>> &vertices, Data data);
};

class RotationY : public TransformStrategy {
 public:
  void changing(std::vector<std::vector<float>> &vertices, Data data);
};

class RotationZ : public TransformStrategy {
 public:
  void changing(std::vector<std::vector<float>> &vertices, Data data);
};

class Moving : public TransformStrategy {
 public:
  void changing(std::vector<std::vector<float>> &vertices, Data data);
};

class Scale : public TransformStrategy {
 public:
  void changing(std::vector<std::vector<float>> &vertices, Data data);
};

}  // namespace s21

#endif
