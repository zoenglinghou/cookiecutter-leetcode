#include <gtest/gtest.h>


using namespace std;

class Solution {
public:
  {{cookiecutter.output_class}} {{ cookiecutter.method_name }} ({{cookiecutter.input_class}} s) {
 
  }
};

class MainTest :
  public ::testing::TestWithParam<tuple<{{ cookiecutter.input_class }}, {{ cookiecutter.output_class }}>> {};

TEST_P(MainTest, romanToInt) {
  Solution solution;
  {{ cookiecutter.input_class }} input;
  {{ cookiecutter.output_class }} expected;
  tie(input, expected) = GetParam();
  ASSERT_EQ(expected, solution.{{ cookiecutter.method_name }}(input));
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
