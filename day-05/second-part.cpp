#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<vector<int>> Grid;
// (X1, Y1, X2, Y2)
typedef tuple<int, int, int, int> Line;

Grid createGrid(int size) {
    return vector<vector<int>>(size, vector<int>(size, 0));
}

void putLineInGrid(Grid *grid, Line line) {
    int x1, x2, y1, y2;
    tie(x1, y1, x2, y2) = line;
    if (x1 == x2) {
        for (int i = min(y1, y2); i <= max(y1, y2); i++) {
            (*grid)[i][x1] ++;
        }
    } else if (y1 == y2) {
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            (*grid)[y1][i] ++;
        }
    } else {
        for (int i = 0; i <= abs(x1 - x2); i++) {
            int y = y1 + i * ((y1 < y2) ? 1 : -1);
            int x = x1 + i * ((x1 < x2) ? 1 : -1);
            (*grid)[y][x] ++;
        }
    }
}

int countDangerousPoints(Grid *grid) {
    int dangerous_points = 0;
    for (auto row : (*grid)) {
        for (int cell : row) {
            dangerous_points += (cell > 1);
        }
    }
    return dangerous_points;
}

int main() {
    int x1, x2, y1, y2;
    int farthest_point = 0;
    vector<Line> lines;
    while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
        farthest_point = max(farthest_point, max(x1, max(x2, max(y1, y2))));
        lines.push_back({x1, y1, x2, y2});
    }
    Grid grid = createGrid(farthest_point + 1);
    for (Line line : lines) {
        putLineInGrid(&grid, line);
    }
    printf("%d", countDangerousPoints(&grid));
    return 0;
}
