#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rate {
  int gamma;
  int epsilon;
} Rate;

Rate calculateRate(int *common_bit, int length) {
  int gamma = 0;
  int epsilon = 0;
  for (int i = 0; i < length; i++) {
    if (common_bit[i] >= 0) {
      gamma = gamma | (1 << length - i - 1);
    } else {
      epsilon = epsilon | (1 << length - i - 1);
    }
  }
  return (Rate) {gamma, epsilon};
}

int powerConsumption(Rate rate) {
  return rate.gamma * rate.epsilon;
}

int main() {
  char *binary = malloc(sizeof(char) * 15);
  int binary_length = 0;
  int *common_bit;

  for (int i = 0; scanf("%s", binary) != EOF; i++) {
    if (!i) {
      binary_length = strlen(binary);
      common_bit = calloc(binary_length, sizeof(int));
    }
    for (int j = 0; j < binary_length; j++) {
      common_bit[j] += (binary[j] == '1') ? 1 : -1;
    }
  }
  Rate rate = calculateRate(common_bit, binary_length);
  printf("%d", powerConsumption(rate));

  return 0;
}
