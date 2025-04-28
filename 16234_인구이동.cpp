#include <bits/stdc++.h>
using namespace std;
// 1시간 20분
#define X first
#define Y second

int N, L, R;
vector<vector<int>> matrix;
vector<pair<int, int> > udlr = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<vector<int> > visited;

void printMatrix()
{
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/* return result value, r행 c열 */
int bfs(int r, int c, int sum)
{
    queue <pair<int, int> > q;
    vector <pair<int, int> > past;
    q.push(make_pair(c, r));
    sum += matrix[r][c];
    visited[r][c] = -1;
    
    while (q.size() > 0) {
        pair<int, int> cur = q.front();  q.pop();
        past.push_back(cur);

        for (pair<int, int> e : udlr) {
            int x = e.X + cur.X;
            int y = e.Y + cur.Y;
            if (x < 0 || y < 0 || x >= N || y >= N)
                continue;
            if (visited[y][x] == -1)
                continue;
            int diff = abs(matrix[y][x] - matrix[cur.Y][cur.X]);
            if (diff >= L && diff <= R) {
                sum += matrix[y][x];
                q.push(make_pair(x, y));
                visited[y][x] = -1;
            }
        }
        // printMatrix();
    }

    int size = past.size();

    if (size > 1) {
        int result = sum/size;
        for (pair<int, int>cur : past) {
            matrix[cur.Y][cur.X] = result;
        }
    }

    return size-1;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int result = 0;

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        vector <int> v(N), t(N, 0);
        matrix.push_back(v);
        visited.push_back(t);

        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int flag = 1;
    int cnt = -1;
    while (flag == 1) {
        flag = 0;
        cnt++;
        for (int i = 0; i < N; i++) {
            fill(visited[i].begin(), visited[i].end(), 0);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == -1)
                    continue;
                if (bfs(i, j, 0) > 0)
                    flag = 1;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}