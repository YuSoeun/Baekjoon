#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
vector<pair<int, int> > udlr = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void print_matrix(vector<vector<int> >& mat) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/* bfs using queue */
void bfs(vector<vector<int> >& mat, queue<pair<int, int> > q) {
    pair<int, int> p = q.front();
    q.pop();

    for (pair<int, int> e : udlr) {
        int x = p.X + e.X;
        int y = p.Y + e.Y;
        if (x >= 0 && x < M && y >= 0 && y < N) {
            if (mat[y][x] == 0) {
                mat[y][x] = 2;
                q.push(make_pair(x, y));
            }
        }
    }
    
    if (!q.empty())
        bfs(mat, q);
}

/* 바이러스 위치 찾아 queue에 넣기 */
int search2(vector<vector<int> > mat)
{
    queue<pair<int, int> > q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 2)
                q.push(make_pair(j, i));
        }
    }
    bfs(mat, q);

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0)
                count++;
        }
    }

    return count;
}

/* 재귀로 벽 3개 세우기 */
int makeWall(int wall_cnt, int I, int J, vector<vector<int> > matrix)
{
    int safe_zone = 0;
    int max_safe = 0;
    
    if (wall_cnt >= 1)
        matrix[I][J] = 1;

    if (wall_cnt >= 3) {
        safe_zone = search2(matrix);
        return safe_zone;
    }

    int j = J;
    for (int i = I; i < N; i++) {
        if (i > I)
            j = 0;
        for (; j < M; j++) {
            if (matrix[i][j] == 0) {
                safe_zone = makeWall(wall_cnt + 1, i, j, matrix);
                if (safe_zone > max_safe)
                    max_safe = safe_zone;
            }

        }
    }

    return max_safe;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int temp;
    vector<vector<int> > matrix;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        vector<int> v;
        matrix.push_back(v);
        for (int j = 0; j < M; j++) {
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }

    cout << makeWall(0, 0, 0, matrix) << "\n";

    return 0;
}