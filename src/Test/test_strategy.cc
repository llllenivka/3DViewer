#include <gtest/gtest.h>

#include "../Model/model.h"

using namespace s21;

/*--------X--------*/

TEST(EQTest, EqTest_1) {
  RotationX rotaX;
  std::vector<std::vector<float>> vert_test = {{1.0f, 2.0f, 3.0f}};
  RotationX::Data data;
  data.angle = 10.0;
  rotaX.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(1.0, x);
  EXPECT_EQ(2.0, y);
  EXPECT_EQ(3.0, z);
}

TEST(EQTest, EqTest_2) {
  RotationX rotaX;
  std::vector<std::vector<float>> vert_test = {{0.0f, 0.0f, 0.0f}};
  RotationX::Data data;
  data.x = 10;
  rotaX.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(0.0, x);
  EXPECT_EQ(0.0, y);
  EXPECT_EQ(0.0, z);
}

TEST(EQTest, EqTest_3) {
  RotationX rotaX;

  std::vector<std::vector<float>> vert_test = {{120.0f, 140.0f, 140.0f}};
  RotationX::Data data;
  data.x = -20;
  rotaX.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];
  EXPECT_EQ(120.0, x);
  EXPECT_EQ(140.0, y);
  EXPECT_EQ(140.0, z);
}

// /*--------Y--------*/

TEST(EQTest, EqTest_5) {
  RotationY rotaY;

  std::vector<std::vector<float>> vert_test = {{1.0f, 2.0f, 3.0f}};
  RotationY::Data data;
  data.y = 32;
  rotaY.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(1.0, x);
  EXPECT_EQ(2.0, y);
  EXPECT_EQ(3.0, z);
}

TEST(EQTest, EqTest_6) {
  RotationY rotaY;

  std::vector<std::vector<float>> vert_test = {{0.0f, 0.0f, 0.0f}};
  RotationY::Data data;
  data.y = 32;
  rotaY.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(0.0, x);
  EXPECT_EQ(0.0, y);
  EXPECT_EQ(0.0, z);
}

TEST(EQTest, EqTest_7) {
  RotationY rotaY;
  RotationY::Data data;
  std::vector<std::vector<float>> vert_test = {{50.0f, 50.0f, 50.0f}};
  data.y = 45;
  rotaY.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(50.0, x);
  EXPECT_EQ(50.0, y);
  EXPECT_EQ(50.0, z);
}

// /*--------Z--------*/
TEST(EQTest, EqTest_9) {
  RotationZ rotaZ;
  RotationZ::Data data;
  data.z = 56;
  std::vector<std::vector<float>> vert_test = {{140.0f, 12.5f, 24.7f}};

  rotaZ.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(140.0, x, 0.00001);
  EXPECT_NEAR(12.5, y, 0.00001);
  EXPECT_NEAR(24.7, z, 0.00001);
}

TEST(EQTest, EqTest_10) {
  RotationZ rotaZ;
  RotationZ::Data data;
  data.z = 56;
  std::vector<std::vector<float>> vert_test = {{0.0f, 0.0f, 0.0f}};

  rotaZ.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(0.0, x);
  EXPECT_EQ(0.0, y);
  EXPECT_EQ(0.0, z);
}

TEST(EQTest, EqTest_11) {
  RotationZ rotaZ;
  RotationZ::Data data;
  data.z = 56;
  std::vector<std::vector<float>> vert_test = {{-41.2f, -27.9f, -76.0f}};

  rotaZ.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(-41.2, x, 0.001);
  EXPECT_NEAR(-27.9, y, 0.001);
  EXPECT_NEAR(-76.0, z, 0.001);
}

// /*--------MOVE--------*/
TEST(EQTest, EqTest_13) {
  Moving move;
  Moving::Data data;
  data.x = -30.0;
  data.y = -30.0;
  data.z = -30.0;

  std::vector<std::vector<float>> vert_test = {{1.0f, 1.0f, 1.0f}};

  move.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(-29.0, x, 0.01);
  EXPECT_NEAR(-29.0, y, 0.01);
  EXPECT_NEAR(-29.0, z, 0.01);
}

TEST(EQTest, EqTest_14) {
  Moving move;
  Moving::Data data;
  data.x = 16.07;
  data.y = 23.56;
  data.z = 23.0;
  std::vector<std::vector<float>> vert_test = {{24.0f, 36.0f, 121.0f}};
  move.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(40.07, x, 0.01);
  EXPECT_NEAR(59.56, y, 0.01);
  EXPECT_NEAR(144.0, z, 0.01);
}

/*--------SCALE--------*/
TEST(EQTest, EqTest_16) {
  Scale scale;
  Scale::Data data;
  data.x = 20.0;
  data.y = 20.0;
  data.z = 20.0;
  std::vector<std::vector<float>> vert_test = {{1.0f, 2.0f, 3.0f}};

  scale.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_EQ(20.0, x);
  EXPECT_EQ(40.0, y);
  EXPECT_EQ(60.0, z);
}

TEST(EQTest, EqTest_17) {
  Scale scale;
  std::vector<std::vector<float>> vert_test = {{-65.29f, -100.0f, -62.3f}};

  Scale::Data data;
  data.x = 4.2;
  data.y = 4.2;
  data.z = 4.2;

  scale.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(-274.218, x, 0.001);
  EXPECT_NEAR(-420.0, y, 0.001);
  EXPECT_NEAR(-261.66, z, 0.001);
}

TEST(EQTest, EqTest_18) {
  Scale scale;
  std::vector<std::vector<float>> vert_test = {{0.26f, 12.4f, 6.8f}};
  Scale::Data data;
  data.x = -4;
  data.y = -4;
  data.z = -4;

  scale.changing(vert_test, data);
  float x = vert_test[0][0];
  float y = vert_test[0][1];
  float z = vert_test[0][2];

  EXPECT_NEAR(-1.04, x, 0.001);
  EXPECT_NEAR(-49.6, y, 0.001);
  EXPECT_NEAR(-27.2, z, 0.001);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
