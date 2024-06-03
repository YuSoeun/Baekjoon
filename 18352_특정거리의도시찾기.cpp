#include <bits/stdc++.h>
using namespace std;

int N;          // 도시의 개수
int M;          // 도로의 개수
int K;          // 거리 정보
int X;          // 출발 도시의 번호
vector<vector<int> > matrix;
vector<int> shortest;       // 다른 노드까지의 거리

// 시간초과는 queue 사용하여 해결!!!! (본거는 다시 for문 안 돌게)
void bfs(int start)
{
    queue <int> q;
    shortest[start] = 0;
    q.push(start);

    while (q.size() > 0) {
        int cur_node = q.front();
        q.pop();

        for (int adjs : matrix[cur_node]) {
            if (shortest[adjs] == -1) {
                shortest[adjs] = shortest[cur_node] + 1;
                q.push(adjs);
            }
        }
    }
}

int main()
{
    int a, b;
    vector <int> v;

    cin >> N >> M >> K >> X;


    matrix.resize(N+1);
    for (int i = 0; i < N+1; i++) {
        shortest.push_back(-1);
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        matrix[a].push_back(b);
    }

    bfs(X);

    int flag = 0;
    for (int i = 1; i < N+1; i++) {
        if (shortest[i] == K) {
            cout << i << "\n";
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << -1 << "\n";
    }

    return 0;
}