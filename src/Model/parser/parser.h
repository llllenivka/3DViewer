#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

namespace s21 {

class Parser {
 public:
  void parse(const std::string &filename,
             std::vector<std::vector<float>> &vertices,
             std::vector<std::vector<int>> &faces);

  static Parser &getInstanse() {
    static Parser instanse;
    return instanse;
  };
};
}  // namespace s21

#endif  // PARSER_H
