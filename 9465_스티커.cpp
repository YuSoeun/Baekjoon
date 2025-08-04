#include <bits/stdc++.h>
using namespace std;

// 1시간: A가 2 미만일 때 처리를 미리 해주어 인덱싱 관련 오류가 없게 하기

int T, N;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> T;

    while (T--) {
        cin >> N;
        vector<vector<int>> A(2, vector<int>(N));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        vector<vector<int>> dp(2, vector<int>(N, 0));
        dp[0][0] = A[0][0];
        dp[1][0] = A[1][0];

        if (N >= 2) {
            dp[0][1] = dp[1][0] + A[0][1];
            dp[1][1] = dp[0][0] + A[1][1];
        }

        for (int j = 2; j < N; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + A[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + A[1][j];
        }

        cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
    }
}