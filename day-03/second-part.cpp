#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef function<bool(int, int)> Comparator;

tuple<vector<int>, vector<int>> splitByMsb(vector<int> *readings, int msb) {
  vector<int> ones;
  vector<int> zeros; 
  for (int reading : (*readings)) {
    if (reading & (1 << msb)) {
      ones.push_back(reading);
    } else {
      zeros.push_back(reading);
    }
  }
  return {ones, zeros};
}

int calculateRating(vector<int> *readings, int msb, Comparator compare) {
  vector<int> ones;
  vector<int> zeros;
  if (readings->size() == 1) {
    if (msb) {
      return (readings->at(0) & (1 << msb)) | calculateRating(readings, msb - 1, compare);
    }
    return readings->at(0) & 1;
  } 
  tie(ones, zeros) = splitByMsb(readings, msb);
  if (compare(ones.size(), zeros.size())) {
    if (!msb) {
      return 0;
    } 
    return calculateRating(&zeros, msb - 1, compare);
  } else {
    if (!msb) {
      return 1;
    } 
    return (1 << msb) | calculateRating(&ones, msb - 1, compare);
  }
}

int main() {
  string binary;
  vector<int> readings;

  for (int i = 0; getline(cin, binary); i++) {
    readings.push_back(stoi(binary, nullptr, 2));
  }
  int most_significan_bit = binary.size() - 1;
  int co2_rating = calculateRating(
      &readings, 
      most_significan_bit, 
      [](int ones_size, int zeros_size) { return ones_size < zeros_size; });
  int o2_rating = calculateRating(
      &readings, 
      most_significan_bit, 
      [](int ones_size, int zeros_size) { return ones_size >= zeros_size; });
  cout << co2_rating * o2_rating;

  return 0;
}
