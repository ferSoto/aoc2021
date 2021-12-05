#include <cstdio>
#include <iostream>
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
* Boards are 5x5 but I need to keep count of the numbers of marked spaces.
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

int markBoards(vector<Board> *boards, int n) {
  for (int i = 0; i < boards->size(); i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (boards->at(i)[j][k] == n) {
          boards->at(i)[j][k] = -1;
          if ((++ boards->at(i)[5][k]) == 5 || (++ boards->at(i)[j][5]) == 5) {
            return i;
          }
        }
      }
    }
  }
  return -1;
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
  for (int number : bingo_numbers) {
    int completed = markBoards(&boards, number);
    if (completed >= 0) {
      cout << calculateScore(&boards[completed], number);
      break;   
    }
  }
  return 0;
}
