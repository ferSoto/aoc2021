#include <stdio.h>
#include <stdlib.h>

#define DOWN "down"
#define FORWARD "forward"

int main() {
  int aim = 0;
  int depth = 0;
  char *direction = malloc(sizeof(char) * 20);
  int n;
  int x = 0;
  
  while (scanf("%s %d", direction, &n) != EOF) {
    if (!strcmp(DOWN, direction)) {
      aim += n;
    } else if (!strcmp(FORWARD, direction)) {
      x += n;
      depth += (n * aim);
    } else {
      aim -= n;
    }
  }
  printf("%d", x * depth);
  
  return 0;
}
