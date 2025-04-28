#include <iostream>
#include <set>
using namespace std;

int T, K;  // K는 연산의 수
multiset<long long> ms;

int main() {
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> T;

    char command;
    long long x;

    for (int t = 1; t <= T; t++) {
        ms.clear();

        cin >> K;
        for (int k = 1; k <= K; k++) {
            cin >> command >> x;
            if (command == 'I') {
                ms.insert(x);
            } else if (command == 'D') {
                if (!ms.empty()) {
                    if (x == 1) {
                        ms.erase(prev(ms.end()));
                    } else if (x == -1) {
                        ms.erase(ms.begin());
                    }
                }
            }
        }

        // 최댓값과 최솟값 출력
        if (!ms.empty()) {
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        } else {
            cout << "EMPTY\n";
        }
    }

    return 0;
}