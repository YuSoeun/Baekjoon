#include <iostream>
#include <vector>
using namespace std;

// 테스트케이스가 있기 때문에 nodeCount 초기화를 해줘야 한다.
// 기존 단어의 접두어 == 추가된 단어인 경우도 고려

const int MX = 10000 * 10 + 5;
const int NUM_MAX = 10;
const int ROOT = 1;

int T, N;
int nodeCount;
int nxt[MX][NUM_MAX];
int isLast[MX];

int getIndex(char c) {
    return c - '0';
}

int insert(string s) {
    int cur = ROOT;
    for (int i = 0; i < s.size(); i++) {
        int nextIndex = getIndex(s[i]);
        if (nxt[cur][nextIndex] == -1) {
            nxt[cur][nextIndex] = nodeCount++;
        }
        // 기존 단어의 접두어 == 추가된 단어
        else if (i == s.size() - 1) {
            return 0;
        }
        cur = nxt[cur][nextIndex];
        // 기존 단어 == 추가된 단어의 접두어
        if (isLast[cur] > 0) {
            return 0;
        }
    }
    isLast[cur] = 1;
    return 1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int isConsistent = 1;
        nodeCount = 2;          // 이거 초기화 안해서 틀렸었다.
        fill(&nxt[0][0], &nxt[0][0] + MX * NUM_MAX, -1);
        fill(&isLast[0], &isLast[0] + MX, 0);

        cin >> N;
        for (int i = 0; i < N; i++) {
            string phone;
            cin >> phone;
            if (!insert(phone)) {
                isConsistent = 0;
            }
        }

        if (isConsistent) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}