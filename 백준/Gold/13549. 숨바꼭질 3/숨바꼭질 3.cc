#include <bits/stdc++.h>
using namespace std;
#define COST first
#define X second

int N, K;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int excution[3][3] = {{2, 0, 0}, {1, 1, 1}, {1, -1, 1}};   // 곱할 숫자, 더할 숫자 순서
int visited[100001];

int inBound(int x) {
    return x >= 0 && x <= 100000;
}

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);

    cin >> N >> K;
    fill(&visited[0], &visited[100001], 0);
    pq.push({0, N});
    visited[N] = 1;

    pair <int, int> cur;
    int diff = abs(K - N);
    while (!pq.empty()) {
        cur = pq.top(); pq.pop();
        if (cur.X == K)  break;

        for (auto e : excution) {
            int nextX = cur.X * e[0] + e[1];
            int nextCost = cur.COST + e[2];

            if (nextX == cur.X)  continue;  // cur.X가 0인 경우
            if (!inBound(nextX) || visited[nextX])  continue;
            visited[nextX] = 1;
            pq.push({nextCost, nextX});
        }
    }

    cout << cur.COST << "\n";

    return 0;
}