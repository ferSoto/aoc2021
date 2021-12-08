#include <iostream>
#include <vector>

using namespace std;

vector<string> parseInput(string *input) {
  size_t pos = 0;
  vector<string> segments;
  while ((pos = input->find(" ")) != string::npos) {
    segments.push_back(input->substr(0, pos));
    input->erase(0, pos + 1);
  }
  segments.push_back((*input));
  return segments;
}

int main() {
    string line;
    int unique_segments_count = 0;
    while (getline(cin, line)) {
        auto segments = parseInput(&line);
        for (int i = 11; i < segments.size(); i++) {
            unique_segments_count += (segments[i].size() < 5 || segments[i].size() > 6);
        }
    }
    cout << unique_segments_count;

    return 0;
}
