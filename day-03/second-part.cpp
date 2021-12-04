#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculateCo2Rating(vector<int> *readings, int msb) {
  if (readings->size() == 1) {
    return readings->at(0) & 1;
  }
  vector<int> ones;
  vector<int> zeros; 
  for (int reading : (*readings)) {
    if (reading & (1 << msb)) {
      ones.push_back(reading);
    } else {
      zeros.push_back(reading);
    }
  }
  if (zeros.size() <= ones.size()) {
    if (!msb) {
      return 0;
    } 
    return calculateCo2Rating(&zeros, msb - 1);
  } else {
    if (!msb) {
      return 1;
    } 
    return (1 << msb) | calculateCo2Rating(&ones, msb - 1);
  }
}

int calculateO2Rating(vector<int> *readings, int msb) {
  if (readings->size() == 1) {
    return readings->at(0) & 1;
  }
  vector<int> ones;
  vector<int> zeros; 
  for (int reading : (*readings)) {
    if (reading & (1 << msb)) {
      ones.push_back(reading);
    } else {
      zeros.push_back(reading);
    }
  }
  if (zeros.size() > ones.size()) {
    if (!msb) {
      return 0;
    } 
    return calculateO2Rating(&zeros, msb - 1);
  } else {
    if (!msb) {
      return 1;
    } 
    return (1 << msb) | calculateO2Rating(&ones, msb - 1);
  }
}

int lifeSupportRating(vector<int> *readings, int most_significan_bit) {
  int co2_rating;
  int o2_rating;
  vector<int> ones;
  vector<int> zeros; 
  for (int reading : (*readings)) {
    if (reading & (1 << most_significan_bit)) {
      ones.push_back(reading);
    } else {
      zeros.push_back(reading);
    }
  }
  if (ones.size() >= zeros.size()) {
    o2_rating = (1 << most_significan_bit) | calculateO2Rating(&ones, most_significan_bit - 1);
    co2_rating = (0 << most_significan_bit) | calculateCo2Rating(&zeros, most_significan_bit - 1);
  } else {
    o2_rating = (0 << most_significan_bit) | calculateO2Rating(&zeros, most_significan_bit - 1);
    co2_rating = (1 << most_significan_bit) | calculateCo2Rating(&ones, most_significan_bit - 1);
  }
  return o2_rating * co2_rating;
}

int main() {
  string binary;
  vector<int> readings;

  for (int i = 0; getline(cin, binary); i++) {
    readings.push_back(stoi(binary, nullptr, 2));
  }

  printf("%d", lifeSupportRating(&readings, binary.size() - 1));

  return 0;
}
