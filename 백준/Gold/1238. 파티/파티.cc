#include <bits/stdc++.h>
using namespace std;
#define W first
#define E second

int N, M, X;
vector <pair<int, int> > adj[1001];   // start edge: <weight, end edge>
int goHome[1001];   // X에서 각 집으로 가는 최소 비용
int goX[1001];      // 각 집에서 X로 가는 최소 비용

struct Edge {
    int s;
    int e;
    int w;
};

int dijkstra(int s, int e) {
    int dist[N+1];
    fill(dist, dist + N+1, INT_MAX);
    dist[s] = 0;

    priority_queue<pair <int, int>, vector<pair <int, int> >, greater<pair <int, int> > > pq;    // weight, cur edge순
    pq.push({0, s});

    while (!pq.empty()) {
        auto cur = pq.top();  pq.pop();

        // 예외 처리: 중복 제거 - 방문하려는 곳이 방문한 곳보다 작을 때
        if (dist[cur.E] < cur.W)   continue;
        for (auto& next : adj[cur.E]) {
            // 예외 처리: 갱신 안되는 경우
            if (dist[next.E] <= dist[cur.E] + next.W)   continue;
            
            dist[next.E] = dist[cur.E] + next.W;
            pq.push({dist[next.E], next.E});
        }
    }

    return dist[e];
}


int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M >> X;

    int s, e, w;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> w;
        adj[s].push_back({w, e});
    }
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        goHome[i] = dijkstra(X, i);
        goX[i] = dijkstra(i, X);
        result = max(result, goX[i] + goHome[i]);
    }

    cout << result << "\n";

    return 0;
}