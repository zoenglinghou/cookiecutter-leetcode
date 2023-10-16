#include <gtest/gtest.h>


using namespace std;

class Solution {
public:
  {{cookiecutter.output_class}} {{ cookiecutter.method_name }} (
  {%- for _, details in cookiecutter.inputs | dictsort -%}
    {%- if details.class is not None -%}
      {{ details.class }} {{ detilas.identifier }},
    {%- endif -%}
  {%- endfor -%}
) {
 
  }
};

class MainTest :
  public ::testing::TestWithParam<tuple<
  {%- for _, details in cookiecutter.inputs | dictsort -%}
    {%- if details.class is not None -%}
      {{ details.class }},
    {%- endif -%}
  {%- endfor -%}
  {{- cookiecutter.output_class -}}>> {};

TEST_P(MainTest, romanToInt) {
  Solution solution;
  {% for _, details in cookiecutter.inputs | dictsort -%}
    {%- if details.class is not None -%}
      {{ details.class }} {{ detilas.identifier }};
    {%- endif -%}
  {%- endfor %}
  {{ cookiecutter.output_class }} expected;
  tie(
    {%- for _, details in cookiecutter.inputs | dictsort -%}
      {%- if details.class is not None -%}
        {{ detilas.identifier }},
      {%- endif -%}
    {%- endfor -%}
  expected) = GetParam();
  ASSERT_EQ(expected, solution.{{ cookiecutter.method_name }}(
    {%- for _, details in cookiecutter.inputs | dictsort -%}
      {%- if details.class is not None -%}
        {{ detilas.identifier }},
      {%- endif -%}
    {%- endfor -%}
  ));
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
