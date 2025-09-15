#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
 **************************************
 * DO NOT MODIFY ANYTHING IN THIS FILE!
 **************************************
 * 
 * You're welcome to read what's here, but
 * please do not change anything!
 */

void mastermind(int8_t[4]);

/*
 * Create the secret code from digits 0..9,
 * but no repeats.
 */

static bool contained(int8_t code[4], int8_t value) {
  for (uint8_t i = 0; i < 4; i++) {
    if (code[i] == value) {
      return true;
    }
  }
  return false;
}

static void createCode(int8_t code[4]) {
  uint8_t idx = 0;
  while (idx < 4) {
    int8_t value = (int8_t)(random() % 10);
    if (!contained(code, value)) {
      code[idx] = value;
      idx++;
    }   
  }
}


int main(int argc, char **argv) {
  int8_t secret_code[4] = {-1, -1, -1, -1};
  if (argc == 2) {
    for (int8_t i = 0; i < 4; i++) {
      secret_code[i] = argv[1][i] - '0';
    }
  } else {
    srandom(time(NULL));
    createCode(secret_code);
  }
  mastermind(secret_code);
  return 0;
}

