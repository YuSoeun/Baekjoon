#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

// 모국 제외 인접한 나라끼리 dfs 후 합산 반환
int in_dfs(vector<vector<int> > &g, vector<int> &lan, int my_lan, int learned, int cur) {
    int temp = 0;
    visited[cur] = 1;

    for (int e : g[cur]) {
        if (visited[e] == 0) {
            if (my_lan == learned) {
                temp += in_dfs(g, lan, my_lan, lan[e], e);
            } else if (lan[e] == my_lan || lan[e] == learned){
                temp += in_dfs(g, lan, my_lan, learned, e);
            }
        }
    }
    return 1 + temp;
}

// 모국과 인접한 나라들 선택 후 비교 후 큰 것 반환
int dfs(vector<vector<int> > &g, vector<int> &lan, int my_lan, int learned, int cur) {
    int result = 0;
    int temp = 0;
    visited[cur] = 1;

    for (int e : g[cur]) {
        if (visited[e] == 0) {
            if (my_lan == learned) {
                // 모국어와 같은 언어를 사용하는 나라가 인접할 때 예외 처리
                if (my_lan == lan[e]) {
                    temp = dfs(g, lan, my_lan, lan[e], e);
                }
                temp = in_dfs(g, lan, my_lan, lan[e], e);
            } else if (lan[e] == my_lan || lan[e] == learned){
                temp = in_dfs(g, lan, my_lan, learned, e);
            }
        }
        if (temp > result) {
            result = temp;
        }
    }
    return 1 + result;
}


int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    int N, M;
    int p, q;
    int my_lan = -1;        // 모국어
    int language = 0;

    cin >> N >> M;
    vector<int> lan_g(N+1);
    vector<vector<int> > adj_g(N+1);

    visited.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> language;
        if (my_lan == -1)
            my_lan = language;

        lan_g[i+1]= language;
        visited.push_back(0);
    }

    for (int i = 0; i < M; i++) {
        cin >> p >> q;
        adj_g[p].push_back(q);
        adj_g[q].push_back(p);
    }

    cout << dfs(adj_g, lan_g, my_lan, my_lan, 1) << endl;

    return 0;
}