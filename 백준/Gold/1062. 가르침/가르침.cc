#include <bits/stdc++.h>
using namespace std;

int N, K;
int words[50];
int visited[26];
int max_cnt;
int max_read = 0;

void calculateMax(int combi, int cnt, int start) {

    if (cnt == max_cnt) {
        int read = 0;
        for (int i = 0; i < N; i++) {
            if ((combi & words[i]) == words[i]) {
                read++;
            }
        }
        max_read = max(read, max_read);

        return;
    }
    

    for (int i = start; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            calculateMax(combi | (1 << i), cnt+1, i + 1);
            visited[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    string word;
    cin >> N >> K;
    
    memset(visited, 0, sizeof(visited));

    int default_num = 0;
    default_num += (1 << ('a' - 'a'));  visited[('a' - 'a')] = 1;
    default_num += (1 << ('c' - 'a'));  visited[('c' - 'a')] = 1;
    default_num += (1 << ('n' - 'a'));  visited[('n' - 'a')] = 1;
    default_num += (1 << ('t' - 'a'));  visited[('t' - 'a')] = 1;
    default_num += (1 << ('i' - 'a'));  visited[('i' - 'a')] = 1;

    max_cnt = K - 5;
    for (int i = 0; i < N; i++) {
        words[i] = default_num;
    }
    

    for (int i = 0; i < N; i++) {
        cin >> word;
        for (char e : word) {
            words[i] |= (1 << (e - 'a'));
        }
        // cout << "word(" << i << "): " << bitset<sizeof(words[i]) * 8>(words[i]) << endl;
    }

    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }

    calculateMax(default_num, 0, 0);
    cout << max_read << "\n";

    return 0;
}

// 1  6
// antarctica