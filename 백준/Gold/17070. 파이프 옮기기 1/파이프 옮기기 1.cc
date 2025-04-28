#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> matrix;
int dp[20][20][3];      // dp[r][c][state]

int dirs[3][2] = {{0, 1}, {1, 0}, {1, 1}}; // 가로, 세로, 대각선

int inBound(int r, int c) {
    return r >= 1 && c >= 1 && r <= N && c <= N;
}

// state 0: 가로, 1: 세로, 2: 대각선
int dfs(int r, int c, int state) {
    if (r == N && c == N) return 1;
    if (dp[r][c][state] != -1) return dp[r][c][state];

    dp[r][c][state] = 0;
    for (int i = 0; i < 3; i++) {
        if (state == 0 && i == 1) continue;
        if (state == 1 && i == 0) continue;

        int nextR = r + dirs[i][0];
        int nextC = c + dirs[i][1];

        if (!inBound(nextR, nextC)) continue;

        if (i == 2) {
            if (!inBound(r + 1, c + 1)) continue;
            if (matrix[r+1][c] || matrix[r][c+1] || matrix[r+1][c+1]) continue;
        } else {
            if (matrix[nextR][nextC]) continue;
        }

        dp[r][c][state] += dfs(nextR, nextC, i);
    }

    return dp[r][c][state];
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    matrix.assign(N+1, vector<int>(N+1, 0));
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> matrix[i][j];

    cout << dfs(1, 2, 0) << "\n";
    return 0;
}