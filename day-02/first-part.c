#include <stdio.h>
#include <stdlib.h>

#define DOWN "down"
#define FORWARD "forward"

int main() {
  char *direction = malloc(sizeof(char) * 20);
  int n;
  int x = 0;
  int y = 0;

  while (scanf("%s %d", direction, &n) != EOF) {
    if (!strcmp(DOWN, direction)) {
      y += n;
    } else if (!strcmp(FORWARD, direction)) {
      x += n;  
    } else {
      y -= n;
    }
  }
  printf("%d", x * y);
  
  return 0;
}
