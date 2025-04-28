#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <vector<int>> dp;
int dirs[3][2] = {{0, -1}, {-1, 0}, {-1, -1}};

int inBound(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}

int main()
{
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> N >> M;
    dp.assign(N, vector<int>(M, 0));

    int result = 0;
    string input;
    for (int r = 0; r < N; r++) {
        cin >> input;
        for (int c = 0; c < M; c++) {
            int minValue = INT_MAX;
            dp[r][c] = input[c] - '0';

            if (dp[r][c] == 1 && r > 0 && c > 0) {
                dp[r][c] = min({ dp[r-1][c], dp[r][c-1], dp[r-1][c-1] }) + 1;
            }
            result = max(result, dp[r][c]);
        }
    }

    cout << result*result << "\n";

    return 0;
}