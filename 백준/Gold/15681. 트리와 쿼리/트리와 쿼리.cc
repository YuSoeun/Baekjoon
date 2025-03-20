#include <bits/stdc++.h>
using namespace std;

int N;      // 정점의 수
int R;      // 루트의 번호
int Q;      // 퀴리의 수
vector<int> visited;            // visited with dp
vector< vector<int> > adj_list;

int setDpUsingDFS(int cur) {
    visited[cur] = 1;
    for (int nxt : adj_list[cur]) {
        if (!visited[nxt]) {
            visited[cur] += setDpUsingDFS(nxt);
        }
    }

    return visited[cur];
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N >> R >> Q;
    adj_list.resize(N+1);
    visited.assign(N+1, 0);

    int U, V;
    for (int i = 0; i < N-1; i++) {
        cin >> U >> V;
        adj_list[U].push_back(V);
        adj_list[V].push_back(U);
    }

    setDpUsingDFS(R);

    for (int j = 0; j < Q; j++) {
        cin >> U;
        cout << visited[U] << "\n";
    }

    return 0;
}