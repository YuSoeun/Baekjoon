#include <bits/stdc++.h>
using namespace std;

int N;
int A[301];
int dp[301][3];

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    fill(&dp[0][0], &dp[300][3], 0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    dp[0][1] = A[0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + A[i];
        dp[i][2] = dp[i-1][1] + A[i];
    }

    // 마지막 계단 밟았을 경우만
    cout << max(dp[N-1][1], dp[N-1][2]) << '\n';

    return 0;
}