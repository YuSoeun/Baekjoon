#include <bits/stdc++.h>
using namespace std;

// N 받기 전에 N으로 초기화한 바보
// 블록 병합 시 이전 값(prev)을 저장하지 않거나 마지막 남은 값을 처리하지 않았다

int N;
int maxValue = 0;
vector<vector<int>> A;

vector<vector<int>> goDir(vector<vector<int>> board, int dir) {
    vector<vector<int>> result(N, vector<int>(N, 0));

    if (dir == 0) {  // up
        for (int c = 0; c < N; c++) {
            int idx = 0, prev = 0;
            for (int r = 0; r < N; r++) {
                int cur = board[r][c];
                if (cur == 0) continue;
                if (prev == 0) {
                    prev = cur;
                } else if (prev == cur) {
                    result[idx++][c] = prev * 2;
                    prev = 0;
                } else {
                    result[idx++][c] = prev;
                    prev = cur;
                }
            }
            if (prev != 0) result[idx][c] = prev;
        }
    } else if (dir == 1) {  // down
        for (int c = 0; c < N; c++) {
            int idx = N - 1, prev = 0;
            for (int r = N - 1; r >= 0; r--) {
                int cur = board[r][c];
                if (cur == 0) continue;
                if (prev == 0) {
                    prev = cur;
                } else if (prev == cur) {
                    result[idx--][c] = prev * 2;
                    prev = 0;
                } else {
                    result[idx--][c] = prev;
                    prev = cur;
                }
            }
            if (prev != 0) result[idx][c] = prev;
        }
    } else if (dir == 2) {  // left
        for (int r = 0; r < N; r++) {
            int idx = 0, prev = 0;
            for (int c = 0; c < N; c++) {
                int cur = board[r][c];
                if (cur == 0) continue;
                if (prev == 0) {
                    prev = cur;
                } else if (prev == cur) {
                    result[r][idx++] = prev * 2;
                    prev = 0;
                } else {
                    result[r][idx++] = prev;
                    prev = cur;
                }
            }
            if (prev != 0) result[r][idx] = prev;
        }
    } else if (dir == 3) {  // right
        for (int r = 0; r < N; r++) {
            int idx = N - 1, prev = 0;
            for (int c = N - 1; c >= 0; c--) {
                int cur = board[r][c];
                if (cur == 0) continue;
                if (prev == 0) {
                    prev = cur;
                } else if (prev == cur) {
                    result[r][idx--] = prev * 2;
                    prev = 0;
                } else {
                    result[r][idx--] = prev;
                    prev = cur;
                }
            }
            if (prev != 0) result[r][idx] = prev;
        }
    }

    return result;
}

// 최대 5번 이동
void do2048(int depth, vector<vector<int>> board) {
    if (depth == 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                maxValue = max(maxValue, board[i][j]);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> nextBoard = goDir(board, dir);
        if (nextBoard == board) continue;
        do2048(depth + 1, nextBoard);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    A.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            maxValue = max(A[i][j], maxValue);
        }
    }

    do2048(0, A);
    cout << maxValue << "\n";

    return 0;
}