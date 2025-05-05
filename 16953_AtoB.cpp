#include <bits/stdc++.h>
using namespace std;

int A, B;

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);
    int result = 1;

    cin >> A >> B;
    while (B > A) {
        result++;
        // 10으로 나눈 나머지가 1이면, 10 나누기
        if (B % 10 == 1) {
            B /= 10;
            continue;
        }
        // 2로 나눈 나머지가 0이면, 2 나누기
        if (B % 2 == 0) {
            B /= 2;
            continue;
        }
        break;
    }

    if (A != B) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}