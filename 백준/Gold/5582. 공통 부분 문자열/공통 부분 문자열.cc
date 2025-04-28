#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;

int main()
{
    cin.tie(0);  ios::sync_with_stdio(0);
    string s1, s2;

    cin >> s1 >> s2;
    N = s1.length();
    M = s2.length();
    vector <vector<int> > dp(N);
    for (int i = 0; i < N; i++) {
        dp[i].assign(M, 0);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (s1[i] == s2[j]) {
                if ((i != 0 && j != 0) && s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
                result = max(dp[i][j], result);
            }
        }
    }

    cout << result << "\n";

    return 0;
}