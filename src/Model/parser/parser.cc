#include "parser.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace s21 {

void Parser::parse(const std::string &filename,
                   std::vector<std::vector<float>> &vertices,
                   std::vector<std::vector<int>> &faces) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Could not open file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.rfind("v ", 0) == 0) {
      std::vector<float> vertex(3);
      std::istringstream iss(line.substr(2));
      iss >> vertex[0] >> vertex[1] >> vertex[2];
      vertices.push_back(vertex);
    } else if (line.rfind("f ", 0) == 0) {
      std::vector<int> face;
      std::istringstream iss(line.substr(2));
      std::string token;
      while (iss >> token) {
        int vertexIndex = std::stoi(token.substr(0, token.find('/')));
        face.push_back(vertexIndex);
      }
      faces.push_back(face);
    }
  }
}

}  // namespace s21
