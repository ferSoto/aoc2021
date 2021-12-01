#include <stdio.h>

#define SAMPLE_SIZE 3

int sumReadings(int readings[]) {
    return readings[0] + readings[1] + readings[2];
}

int sumNewReading(int old_readings[], int oldest_reading_position, int new_reading) {
    return new_reading
        + old_readings[(oldest_reading_position + 1) % SAMPLE_SIZE]
        + old_readings[(oldest_reading_position + 2) % SAMPLE_SIZE];
}

int main() {
    int bigger_than_previous_count = 0;
    int n;
    int readings[3];
    
    for (int i = 0; scanf("%d", &n) != EOF; i++) {
        if (i < 3) {
            readings[i % SAMPLE_SIZE] = n;
            continue;
        }
        bigger_than_previous_count += (sumReadings(readings) < sumNewReading(readings, i, n));
        readings[i % SAMPLE_SIZE] = n;
    }
    printf("%d", bigger_than_previous_count);
    
    return 0;
}
