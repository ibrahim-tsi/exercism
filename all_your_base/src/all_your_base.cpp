#include "all_your_base.hpp"

#include <vector>
#include <cmath>
#include <stdexcept>

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

}  // namespace all_your_base