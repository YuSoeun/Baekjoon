#include <bits/stdc++.h>
using namespace std;
// 인접리스트 + pq 사용하기

vector<pair<int, int>> matrix[20001];
vector<int> min_route;
struct
{
    bool operator()(const pair<int, int> l, pair<int, int> r) const
    { return l.second > r.second; }
} customLess;
priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(customLess)> pq(customLess);

void bfs()
{
    // 자신을 vector에 넣은 후 queue에 넣기, 한번 간 간선은 -1로 표시
    pair<int, int> temp = pq.top(); pq.pop();

    if (temp.second == min_route[temp.first]) {
        // pq에서 제일 w가 작은 것 빼고, 인접 node를 vector에서 업데이트 후 pq에 넣기
        for (auto e: matrix[temp.first]) {
            int new_weight = e.second+min_route[temp.first];
            if (e.second > 0 && new_weight < min_route[e.first]) {
                min_route[e.first] = new_weight;
                pq.push(make_pair(e.first, new_weight));
            }
        }
    }
    
    if (pq.size() > 0) {
        bfs();
    }
}

int main()
{
    int V, E, K;
    int u, v, w;
    
    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        matrix[u].push_back({v, w});
    }

    min_route.push_back(INT_MAX);   // 0번째엔 dummy
    for (int i = 0; i < V; i++) {
        min_route.push_back(INT_MAX);
    }

    min_route[K] = 0;
    pq.push(make_pair(K, 0));

    bfs();

    for (int i = 1; i <= V; i++) {
        if (min_route[i] == INT_MAX)    cout << "INF" << "\n";
        else    cout << min_route[i] << "\n";
    }

    return 0;
}