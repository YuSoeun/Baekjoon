#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> isLeaf;     // 0: false, 1: true
vector<int> isCutLine;
vector<int> adj_cnt;

void init()
{
    isLeaf.assign(N+1, 0);
    isCutLine.assign(N, 0);
    adj_cnt.assign(N+1, 0);

    int a, b;
    for (int i = 1; i <= N-1; i++) {
        cin >> a >> b;
        adj_cnt[a]++;
        adj_cnt[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (adj_cnt[i] == 1) {
            isLeaf[i] = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    init();

    cin >> Q;
    int t, k;
    for (int i = 0; i < Q; i++) {
        cin >> t >> k;
        if (t == 1) {
            cout << (isLeaf[k] ? "no" : "yes") << "\n";
        } else if (t == 2) {
            cout << "yes\n";
        }
    }

    return 0;
}