#include <bits/stdc++.h>
using namespace std;

int N;

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> N;

    int num = 0;
    // 예외: N을 6으로 나눴을 때 2또는 3
    if (N % 6 == 2 || N % 6 == 3) {
        for (int i = 0; i < N; i++) {
            if (i < N/2) {
                cout << 2*i + 2 << '\n';
            } else {
                cout << 2*(i-N/2) + 1 << '\n';
            }
        }
    } else {
        if (N % 2 == 0) {
            for (int i = 2; i <= N; i += 2)     cout << i << '\n';
            for (int i = 1; i <= N-1; i += 2)   cout << i << '\n';
        } else {
            for (int i = 2; i <= N-1; i += 2)   cout << i << '\n';
            for (int i = 1; i <= N; i += 2)     cout << i << '\n';
        }
    }

    return 0;
}