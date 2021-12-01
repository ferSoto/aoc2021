#include <stdio.h>

int main() {
    int bigger_than_previous_count = 0;
    int n;
    int previous_reading = -1;
    
    while(scanf("%d", &n) != EOF) {
        if (previous_reading < 0) {
            previous_reading = n;
            continue;
        }
        bigger_than_previous_count += (n > previous_reading);
        previous_reading = n;
    }
    printf("%d", bigger_than_previous_count);
    
    return 0;
}
