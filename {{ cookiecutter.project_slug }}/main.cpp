#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
};
class MainTest : public ::testing::TestWithParam<tuple<>> {};

TEST_P(MainTest, Solution){};

INSTANTIATE_TEST_SUITE_P(MainTest, MainTest, ::testing::Values());

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
