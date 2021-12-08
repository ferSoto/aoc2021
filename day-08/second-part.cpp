#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

#define SEPARATOR_POS = 10;

using namespace std;

vector<string> parseInput(string *input) {
  size_t pos = 0;
  vector<string> segments;
  while ((pos = input->find(" ")) != string::npos) {
    segments.push_back(input->substr(0, pos), nullptr));
    input->erase(0, pos + 1);
  }
  segments.push_back(stoi((*input), nullptr));
  return segments;
}

map<int, int> valueToDigit() {
    map<int, int> value_to_digit;
    value_to_digit[stoi("1110111", nullptr, 2)] = 0;
    value_to_digit[stoi("0010010", nullptr, 2)] = 1;
    value_to_digit[stoi("1011101", nullptr, 2)] = 2;
    value_to_digit[stoi("1011011", nullptr, 2)] = 3;
    value_to_digit[stoi("0111010", nullptr, 2)] = 4;
    value_to_digit[stoi("1101011", nullptr, 2)] = 5;
    value_to_digit[stoi("1101111", nullptr, 2)] = 6;
    value_to_digit[stoi("1010010", nullptr, 2)] = 7;
    value_to_digit[stoi("1111111", nullptr, 2)] = 8;
    value_to_digit[stoi("1111011", nullptr, 2)] = 9;
    return value_to_digit;
}

map<char, int> signalToPosition(vector<string> *segments) {
    string eight_segment;
    for (string segment : (*segments)) {
        if (segment.size() == 8) {
            eight_segment = segment; 
        }
    }
    map<char, int> signal_to_position;
    for (int i = 0; i < 8; i++) {
        signal_to_position[eight_segment[i]] = (1 << i);
    }
    return signal_to_position;
}

int segmentsToOutput(vector<string> *segments, map<char, int> *signal_to_position, map<int, int> *value_to_digit) {
    int output = 0;
    for (int i = SEPARATOR_POS + 1; i < (*segments).size(); i++) {
        int signal_value = 0;
        cout << (*segments)[i] << " -> ";
        for (char c : (*segments)[i]) {
            signal_to_value += (*signal_to_position)[c];
        }
        output += ((*value_to_digit)[signal_to_value] * pow(10, (*segments).size() - i));
        cout << (*value_to_digit)[signal_to_value];
    }
    cout << endl;
    return output;
}


int main() {
    string line;
    int output_sum = 0;
    auto value_to_digit = value_to_digit()
    while (getline(cin, line)) {
        auto segments = parseInput(&line);
        auto signal_to_value = signalMap(&segments);
        cout << endl;
        output_sum += segmentsToOutput(&segments, &signal_to_value, &value_to_digit);
    }
    cout << unique_segments_count;

    return 0;
}
