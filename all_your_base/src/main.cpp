#include <vector>
#include <cmath>
#include <stdexcept>

#include <assert.h>

#include <iostream>

using std::vector;

namespace all_your_base {
  std::vector<unsigned int> convert(unsigned int in_base,
    std::vector<unsigned int> in_digits, unsigned int out_base)
  {
    if (in_base < 2 || out_base < 2)
      throw std::invalid_argument("");

    unsigned int denary_val = 0;

    for (unsigned int i = 0; i < (unsigned int)in_digits.size(); i++) {
      if (in_digits[i] >= in_base)
        throw std::invalid_argument("");
        
      denary_val += in_digits[i] * std::pow(in_base, in_digits.size() - 1 - i);
    }

    std::vector<unsigned int> result;
    
    while (denary_val) {
      result.insert(result.begin(), denary_val % out_base);
      denary_val /= out_base;
    }

    return result;
  }
}

#define TEST_CASE(t)
#define REQUIRE(c) assert(c)

int main() {
  // std::vector<unsigned int> out_digits = convert(10, {1, 2, 3}, 2);

  // for (const auto& digit : out_digits)
  //   std::cout << digit;

  // std::cout << std::endl;

TEST_CASE("single_bit_one_to_decimal") {
    vector<unsigned int> in_digits{1};
    vector<unsigned int> expected{1};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);
    REQUIRE(expected == out_digits);
}

TEST_CASE("binary_to_single_decimal") {
    vector<unsigned int> in_digits{1, 0, 1};
    vector<unsigned int> expected{5};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);
    REQUIRE(expected == out_digits);
}

TEST_CASE("single_decimal_to_binary") {
    vector<unsigned int> in_digits{5};
    vector<unsigned int> expected{1, 0, 1};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);
    REQUIRE(expected == out_digits);
}

TEST_CASE("binary_to_multiple_decimal") {
    vector<unsigned int> in_digits{1, 0, 1, 0, 1, 0};
    vector<unsigned int> expected{4, 2};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);
    REQUIRE(expected == out_digits);
}

TEST_CASE("decimal_to_binary") {
    vector<unsigned int> in_digits{4, 2};
    vector<unsigned int> expected{1, 0, 1, 0, 1, 0};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);
    REQUIRE(expected == out_digits);
}
TEST_CASE("trinary_to_hexadecimal") {
    vector<unsigned int> in_digits{1, 1, 2, 0};
    vector<unsigned int> expected{2, 10};
    vector<unsigned int> out_digits = all_your_base::convert(3, in_digits, 16);
    REQUIRE(expected == out_digits);
}
TEST_CASE("hexadecimal_to_trinary") {
    vector<unsigned int> in_digits{2, 10};
    vector<unsigned int> expected{1, 1, 2, 0};
    vector<unsigned int> out_digits = all_your_base::convert(16, in_digits, 3);
    REQUIRE(expected == out_digits);
}
TEST_CASE("fifteen_bit_integer") {
    vector<unsigned int> in_digits{3, 46, 60};
    vector<unsigned int> expected{6, 10, 45};
    vector<unsigned int> out_digits = all_your_base::convert(97, in_digits, 73);
    REQUIRE(expected == out_digits);
}
TEST_CASE("empty_list") {
    vector<unsigned int> in_digits{};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);
    REQUIRE(expected == out_digits);
}
TEST_CASE("single_zero") {
    vector<unsigned int> in_digits{0};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);
    REQUIRE(expected == out_digits);
}
TEST_CASE("multiple_zeros") {
    vector<unsigned int> in_digits{0, 0, 0};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);
    REQUIRE(expected == out_digits);
}
TEST_CASE("leading_zeros") {
    vector<unsigned int> in_digits{0, 6, 0};
    vector<unsigned int> expected{4, 2};
    vector<unsigned int> out_digits = all_your_base::convert(7, in_digits, 10);
    REQUIRE(expected == out_digits);
}

  return 0;
}