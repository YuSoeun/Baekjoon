#include <bits/stdc++.h>
using namespace std;
#define C first
#define V second

struct Wolf {
    int cost;
    int vertex;
    int isfast; // 들어올 때 isFast였는지
};

struct myCompare {
    bool operator()(Wolf x, Wolf y) {
        if (x.cost == y.cost) return x.vertex > y.vertex;
        return x.cost > y.cost;
    }
};

priority_queue<Wolf, vector<Wolf>, myCompare> wolfWay;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > foxWay;                 // 비용, 정점

int N, M;

int wolfCost[4001][2];   // j: isFast상태로 도착했는지
int foxCost[4001];
vector<pair<int, int>> adj[4001];   // cost, vertex

void dijkstraWolf(int start) {
    wolfWay.push({0, start, 0});
    wolfCost[start][0] = 0;

    while (!wolfWay.empty()) {
        auto cur = wolfWay.top(); wolfWay.pop();
        if (cur.cost > wolfCost[cur.vertex][cur.isfast])   continue;

        for (auto nxt : adj[cur.vertex]) {
            int nxtCost = cur.isfast ? nxt.C*2 : nxt.C/2;

            if (wolfCost[nxt.V][!cur.isfast] > cur.cost + nxtCost) {
                wolfCost[nxt.V][!cur.isfast] = cur.cost + nxtCost;
                wolfWay.push({wolfCost[nxt.V][!cur.isfast], nxt.V, !cur.isfast});
            }
        }
    }
}

void dijkstraFox(int start) {
    foxWay.push({0, start});
    foxCost[start] = 0;

    while (!foxWay.empty()) {
        auto cur = foxWay.top(); foxWay.pop();
        if (cur.C > foxCost[cur.V])    continue;

        for (auto nxt : adj[cur.V]) {
            if (foxCost[nxt.V] > cur.C + nxt.C) {
                foxCost[nxt.V] = cur.C + nxt.C;
                foxWay.push({foxCost[nxt.V], nxt.V});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    fill(&wolfCost[0][0], &wolfCost[4000][2], INT_MAX);
    fill(&foxCost[0], &foxCost[4001], INT_MAX);

    int a, b;
    int d;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        // 부동소수점 오류 해결하려 2 곱하여 저장
        adj[a].push_back({d*2, b});
        adj[b].push_back({d*2, a});
    }

    dijkstraWolf(1);
    dijkstraFox(1);

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (foxCost[i] < wolfCost[i][0] && foxCost[i] < wolfCost[i][1]) result++;
    }
    cout << result << "\n";
}