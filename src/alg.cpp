// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 0;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    if (num > max)
      max = num;
  }
  return max;
}

unsigned int collatzlen(uint64_t num) {
  int length = 1;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    length++;
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlength,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlength = 0;
  int number = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    if (collatzlen(i) > *maxlength) {
      *maxlength = collatzlen(i);
      number = i;
    }
  }
  return number;
}
