#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector <int> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());

    int result = 0;
    for (int i = N-1; i >= 0; i--) {
        // 마지막꺼부터 가장 큰거 선택
        int j = i;
        int k = 0;
        while (j > k) {
            if (S[i] < S[j] + S[k]) {
                j--;
            } else {
                result += j-k;
                k++;
            }
        }
    }

    cout << result << endl;

    return 0;
}