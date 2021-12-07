#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

long findMinimum(vector<long> *array) {
    long current_min = (*array)[0];
    for (long n : (*array)) {
        current_min = min(current_min, n);
    }
    return current_min;
}

long calculateMinFuelToAlignV2(vector<long> *crabs, int farthest_position) {
    vector<long> fuel_spent(farthest_position, 0);
    for (long crab : (*crabs)) {
        for (long i = 0; i < farthest_position; i++) {
            long distance = abs(crab - i);
            fuel_spent[i] += (distance * (distance + 1) / 2);
        }
    }
    return findMinimum(&fuel_spent);
}

long calculateMinFuelToAlign(vector<long> *crabs, int farthest_position) {
    vector<long> fuel_spent(farthest_position, 0);
    for (long crab : (*crabs)) {
        for (long i = 0; i < farthest_position; i++) {
            fuel_spent[i] += abs(crab - i);
        }
    }
    return findMinimum(&fuel_spent);
}

int main() {
    vector<long> crabs;
    int farthest_position = -1;
    int n;
    while (scanf("%d%*c", &n) != EOF) {
        crabs.push_back(n);
        farthest_position = max(farthest_position, n);
    }
    printf("%d\n", calculateMinFuelToAlign(&crabs, farthest_position));
    printf("%d\n", calculateMinFuelToAlignV2(&crabs, farthest_position));
    return 0;
}
