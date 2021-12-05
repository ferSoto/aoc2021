#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> Board;

void printBoard(Board *board) {
  for (auto row : (*board)) {
    for (int i : row) {
       printf("%2d ", i);
    }
    cout << endl;
  }
}

void printBoards(vector<Board> *boards) {
  for (Board b : (*boards)) {
    printBoard(&b);
    cout << endl;
  }
}

/**
* Boards are 5x5 but I need to keep track of the numbers of marked spaces.
* Add an extra row and and extra column to the board to count marked positions.
*/
Board newBoard() {
  return vector<vector<int>>(6, vector<int>(6, 0));
}

vector<int> parseInput(string *input) {
  size_t pos = 0;
  vector<int> parsed_input;
  while ((pos = input->find(",")) != string::npos) {
    parsed_input.push_back(stoi(input->substr(0, pos), nullptr));
    input->erase(0, pos + 1);
  }
  parsed_input.push_back(stoi((*input), nullptr));
  return parsed_input;
}

void updateCompletedBoards(set<int> *s, vector<int> *v) {
  for (int n : (*v)) {
    s->insert(n);
  }
}

vector<int> markBoards(vector<Board> *boards, int n, set<int> completed_boards) {
  vector<int> completed;
  for (int i = 0; i < boards->size(); i++) {
    if (completed_boards.count(i)) {
      continue;
    }
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (boards->at(i)[j][k] == n) {
          boards->at(i)[j][k] = -1;
          if ((++ boards->at(i)[5][k]) == 5 || (++ boards->at(i)[j][5]) == 5) {
            completed.push_back(i);
          }
        }
      }
    }
  }
  return completed;;
}

int calculateScore(Board *b, int n) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if ((*b)[i][j] != -1) {
        sum += (*b)[i][j];
      }
    }
  }
  return sum * n;
}

int main() {
  string bingo_string;
  getline(cin, bingo_string);
  auto bingo_numbers = parseInput(&bingo_string);
  vector<Board> boards;
  int cell;
  for (int i = 0; cin >> cell; i++) {
    if (!(i % 25)) {
      boards.push_back(newBoard());
    }
    boards[i / 25][i / 5 % 5][i % 5] = cell;
  }
  int last_completed_board;
  int last_number_played;
  set<int> completed_boards;
  for (int i = 0; i < bingo_numbers.size(); i++) {
    auto new_completed = markBoards(&boards, bingo_numbers[i], completed_boards);
    if (!new_completed.empty()) {
      updateCompletedBoards(&completed_boards, &new_completed);
      last_number_played = bingo_numbers[i];
      last_completed_board = new_completed.back();
    }
  }
  cout << calculateScore(&boards[last_completed_board], last_number_played);
  return 0;
}
