#include <bits/stdc++.h>
using namespace std;

int N = 9;
int SUM = 45;
vector<pair<int, int> > emptys;
int sudoku[9][9];
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int inBound(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < N;
}

int inSemiBound(int r, int c, int R, int C) {
    return r >= R*3 && c >= C*3
            && r < (R+1)*3 && c < (C+1)*3;
}

int isValid(pair<int, int>& p, int num) {
    int r = p.first;
    int c = p.second;

    // 가로 세로 체크
    for (int i = 0; i < 4; i++) {
        auto dir = dirs[i];
        int nr = r, nc = c;
        while (1) {
            nr += dir[0];
            nc += dir[1];
            if (!inBound(nr, nc))
                break;
            if (num == sudoku[nr][nc]) {
                return 0;
            }
        }
    }

    queue<pair<int, int> > q;
    int visited[9][9];
    for (int i = 0; i < 9; i++) {
        fill(visited[i], visited[i] + 9, 0);
    }
    q.push({r, c});
    visited[r][c] = 1;
    
    // 작은 네모 체크
    int R = r/3;
    int C = c/3;
    
    while (!q.empty()) {
        auto cur = q.front();   q.pop();
        for (auto dir : dirs) {
            int nr = cur.first + dir[0];
            int nc = cur.second + dir[1];
            if (!inSemiBound(nr, nc, R, C) || visited[nr][nc])
                continue;
            q.push({nr, nc});
            visited[nr][nc] = 1;
            if (num == sudoku[nr][nc]) {
                return 0;
            }
        }
    }
    return 1;
}

void getSudoku(int cnt) {
    if (cnt >= emptys.size()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sudoku[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    auto cur = emptys[cnt];
    for (int i = 1; i <= 9; i++) {
        if (isValid(cur, i)) {
            sudoku[cur.first][cur.second] = i;
            getSudoku(cnt+1);
            sudoku[cur.first][cur.second] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);
    for (int i = 0; i < N; i++) {
        fill(sudoku[i], sudoku[i] + N, 0);
    }

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;        
        for (int j = 0; j < N; j++) {
            sudoku[i][j] = line[j] - '0';
            if (sudoku[i][j] == 0) {
                emptys.push_back({i, j});
            }
        }
    }

    getSudoku(0);
    return 0;
}