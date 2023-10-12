#include <gtest/gtest.h>


using namespace std;

class Solution {
public:
  {{cookiecutter.cpp.output_class}} {{ cookiecutter.cpp.method_name }} ({{cookiecutter.cpp.input_class}} s) {
 
  }
};

class MainTest :
  public ::testing::TestWithParam<tuple<{{ cookiecutter.cpp.input_class }}, {{ cookiecutter.cpp.output_class }}>> {};

TEST_P(MainTest, romanToInt) {
  Solution solution;
  {{ cookiecutter.cpp.input_class }} input;
  {{ cookiecutter.cpp.output_class }} expected;
  tie(input, expected) = GetParam();
  ASSERT_EQ(expected, solution.{{ cookiecutter.cpp.method_name }}(input));
};

INSTANTIATE_TEST_SUITE_P(
  MainTest, MainTest,
  ::testing::Values(
  )
);

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
