#include <iostream>
#include <string>
using namespace std;

const int ROOT = 1;
const int MX = 10 * 100000 + 5;
const int ALPHA_MAX = 26;

int N;
int trie[MX][ALPHA_MAX];
int isLast[MX];
int nodeCount = 2;

int char2Index(char c) {
    return c - 'a';
}

int insert(string nickname, int& prefixLength) {
    int cur = ROOT;

    for (int i = 0; i < nickname.size(); i++) {
        int nextIndex = char2Index(nickname.at(i));

        if (trie[cur][nextIndex] == -1) {
            trie[cur][nextIndex] = nodeCount++;
            if (prefixLength == -1) {
                prefixLength = i + 1;
            }
        }
        cur = trie[cur][nextIndex];
    }
    isLast[cur]++;
    
    return isLast[cur];
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;

    fill(&trie[0][0], &trie[0][0] + MX * ALPHA_MAX, -1);
    fill(&isLast[0], &isLast[0] + MX, 0);

    for (int i = 0; i < N; i++) {
        string nickname;
        cin >> nickname;

        int prefixLength = -1;
        int duplicateCount = insert(nickname, prefixLength);
        if (prefixLength == -1)  prefixLength = nickname.size();
        
        cout << nickname.substr(0, prefixLength);
        if (duplicateCount > 1)  cout << duplicateCount;
        cout << "\n";
    }

    return 0;
}