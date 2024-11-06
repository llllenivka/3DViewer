#include <gtest/gtest.h>

#include <fstream>
#include <stdexcept>

#include "../Model/model.h"

TEST(ParserTest, ParseVertices) {
  s21::Parser parser;
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  std::ofstream tempFile("temp_test_file.obj");
  tempFile << "v 1.0 2.0 3.0\n";
  tempFile << "v 4.0 5.0 6.0\n";
  tempFile << "v 7.0 8.0 9.0\n";
  tempFile.close();

  parser.parse("temp_test_file.obj", vertices, faces);

  ASSERT_EQ(vertices.size(), 3);
  EXPECT_FLOAT_EQ(vertices[0][0], 1.0f);
  EXPECT_FLOAT_EQ(vertices[0][1], 2.0f);
  EXPECT_FLOAT_EQ(vertices[0][2], 3.0f);
  EXPECT_FLOAT_EQ(vertices[1][0], 4.0f);
  EXPECT_FLOAT_EQ(vertices[1][1], 5.0f);
  EXPECT_FLOAT_EQ(vertices[1][2], 6.0f);
  EXPECT_FLOAT_EQ(vertices[2][0], 7.0f);
  EXPECT_FLOAT_EQ(vertices[2][1], 8.0f);
  EXPECT_FLOAT_EQ(vertices[2][2], 9.0f);
}

TEST(ParserTest, ParseFaces) {
  s21::Parser parser;
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  std::ofstream tempFile("temp_test_file.obj");
  tempFile << "v 1.0 2.0 3.0\n";
  tempFile << "v 4.0 5.0 6.0\n";
  tempFile << "v 7.0 8.0 9.0\n";
  tempFile << "f 1 2 3\n";
  tempFile.close();

  parser.parse("temp_test_file.obj", vertices, faces);

  ASSERT_EQ(faces.size(), 1);
  EXPECT_EQ(faces[0][0], 1);
  EXPECT_EQ(faces[0][1], 2);
  EXPECT_EQ(faces[0][2], 3);
}

TEST(ParserTest, ParseInvalidFile) {
  s21::Parser parser;
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  ASSERT_NO_THROW(parser.parse("non_existent_file.obj", vertices, faces));
  EXPECT_TRUE(vertices.empty());
  EXPECT_TRUE(faces.empty());
}

TEST(ParserTest, ParseVerticesAndFaces) {
  s21::Parser parser;
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  std::ofstream tempFile("temp_test_file.obj");
  tempFile << "v 1.0 2.0 3.0\n";
  tempFile << "v 4.0 5.0 6.0\n";
  tempFile << "f 1 2\n";
  tempFile.close();

  parser.parse("temp_test_file.obj", vertices, faces);

  ASSERT_EQ(vertices.size(), 2);
  ASSERT_EQ(faces.size(), 1);
  EXPECT_EQ(faces[0][0], 1);
  EXPECT_EQ(faces[0][1], 2);
}

TEST(ParserTest, ParseInvalidFormat) {
  s21::Parser parser;
  std::vector<std::vector<float>> vertices;
  std::vector<std::vector<int>> faces;

  std::ofstream tempFile("temp_test_file.obj");
  tempFile << "v 1.0 2.0 3.0\n";
  tempFile << "invalid_line\n";
  tempFile << "f 1 2\n";
  tempFile.close();

  parser.parse("temp_test_file.obj", vertices, faces);

  ASSERT_EQ(vertices.size(), 1);
  ASSERT_EQ(faces.size(), 1);
  EXPECT_EQ(faces[0][0], 1);
  EXPECT_EQ(faces[0][1], 2);
}
