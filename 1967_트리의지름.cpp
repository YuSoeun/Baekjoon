#include <bits/stdc++.h>
using namespace std;

int N;
int result = 0;
vector<int> depth; 
vector<vector<pair<int, int>>> childs;   // {child, edge}
int result[10001][2];

int l = 0, r = 1;
void dfs(int cur)
{
    auto l_child = childs[cur][0];
    auto r_child = childs[cur][1];
    result[cur][l] = max(result[l_child.first][0], result[r_child.first][0]);
    result[cur][r] = max(result[l_child.first][0], result[r_child.first][0]);
}

int main() {
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> N;
    depth.assign(N+1, 0);
    childs.resize(N+1);
    fill(&result[0][0], &result[10000][2], 0);
    
    int root = 0;
    int parent, child, weight;
    for (int i = 0; i < N; i++) {
        cin >> parent >> child >> weight;
        childs[parent].push_back({child, weight});
    }


    cout << result << "\n";
}