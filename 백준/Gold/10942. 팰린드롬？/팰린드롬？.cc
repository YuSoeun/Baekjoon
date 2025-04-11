#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
int dp[2001][2001];

int isPalindrome(int start, int end) {
    if (A[start] != A[end])  return 0;
    if (start >= end)  return 1;

    // memorization
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    return dp[start][end] = isPalindrome(start + 1, end - 1);
}

void checkPalindrome()
{
    int start = 0;
    int end = A.size() - 1;
    int temp;
    for (int start = 1; start <= N; start++) {
        for (int end = start; end <= N; end++) {
            temp = isPalindrome(start, end);
            dp[start][end] = temp;
            // cout << "s: " << start << ", end: " << end << " - " << m[s] << "\n";
        }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    A.resize(N+1);
    fill(&dp[0][0], &dp[2000][2001], -1);

    for (int i = 1; i <= N ; i++) {
        cin >> A[i];
    }

    checkPalindrome();

    cin >> M;
    int S, E;
    for (int j = 0; j < M; j++) {
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

    return 0;
}