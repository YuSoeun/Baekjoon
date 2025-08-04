#include <bits/stdc++.h>
using namespace std;

int N, M;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int matrix[1001][1001];
int visited[1001][1001];
int cate_visited[1000001];

unordered_map <int, int> m;

int inBound(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}

int cnt = 0;
void dfs(int r, int c, int category) {
    cnt++;
    for (auto dir : dirs) {
        int nextR = r + dir[0];
        int nextC = c + dir[1];
        if (inBound(nextR, nextC) && !visited[nextR][nextC] && matrix[nextR][nextC]) {
            visited[nextR][nextC] = 1;
            matrix[nextR][nextC] = category;
            dfs(nextR, nextC, category);
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int result = 0;
    cin >> N >> M;
    
    fill(&matrix[0][0], &matrix[1000][1001], 0);
    fill(&visited[0][0], &visited[1000][1001], 0);
    fill(&cate_visited[0], &cate_visited[1000001], 0);

    vector<pair<int, int>> is_one;
    vector<pair<int, int>> is_zero;


    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> matrix[r][c];
            if (matrix[r][c] == 1) {
                is_one.push_back({r, c});
            } else {
                is_zero.push_back({r, c});
            }
        }
    }

    int category = 2;
    for (auto p : is_one) {
        int r = p.first;
        int c = p.second;
        if (!visited[r][c] && matrix[r][c]) {
            visited[r][c] = 1;
            cnt = 0;
            matrix[r][c] = category;
            dfs(r, c, category);
            m[category] = cnt;
            category++;
        }
    }

    for (auto p : is_zero) {
        int r = p.first;
        int c = p.second;
        int sum = 1;
        if (matrix[r][c] == 0) {
            for (auto dir : dirs) {
                int nextR = r + dir[0];
                int nextC = c + dir[1];
                if (inBound(nextR, nextC) && !cate_visited[matrix[nextR][nextC]]) {
                    cate_visited[matrix[nextR][nextC]] = 1;
                    sum += m[matrix[nextR][nextC]];
                }
            }
        }
        result = max(sum, result);
        for (auto dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            cate_visited[matrix[nextR][nextC]] = 0;
        }
    }
    cout << result << "\n";

    return 0;
}