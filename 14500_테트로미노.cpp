#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, max_sum = 0;
vector<pair<int, int>> udlr = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void printMatrix(vector<vector <int> > matrix)
{
    for (vector<int> line : matrix) {
        for (int e : line) {
            cout << e << " ";
        }
        cout << "\n";
    }
        cout << "max: " << max_sum << "\n";
        cout << "\n";
}

void shape4MaxSum(vector<vector <int> >& mat, int cnt, pair<int, int> cur, int sum) {
    int original = mat[cur.Y][cur.X];
    mat[cur.Y][cur.X] = -1;

    if (cnt >= 4) {
        max_sum = max(max_sum, sum);
        mat[cur.Y][cur.X] = original;

        return;
    }

    for (pair<int, int>& p : udlr) {
        int x = cur.X + p.X;
        int y = cur.Y + p.Y;

        if (x >= 0 && x < m && y >= 0 && y < n) {
            if (mat[y][x] != -1) {
                int value = mat[y][x];
                pair<int, int> new_p = make_pair(x, y);
                shape4MaxSum(mat, cnt+1, new_p, sum + value);
            }
        }
    }
    mat[cur.Y][cur.X] = original;

}

// ㅜ는 예외!
void shape4Exception(vector<vector <int> >& mat, pair<int, int> cur) {
    int min_value = INT_MAX;
    int cnt = 0;            // 상하좌우 중 범위내 개수
    int sum = mat[cur.Y][cur.X];

    for (pair<int, int>& p : udlr) {
        int x = cur.X + p.X;
        int y = cur.Y + p.Y;

        if (x >= 0 && x < m && y >= 0 && y < n) {
            min_value = min(min_value, mat[y][x]);

            sum += mat[y][x];
            cnt++;
        }
    }

    if (cnt == 4) {
        sum -= min_value;
    } else if (cnt < 3) {
        sum = -1;
    }

    max_sum = max(sum, max_sum);
}


int main()
{
    cin.tie(0);  ios::sync_with_stdio(0);
    vector<vector <int> > matrix;
    int temp;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        matrix.push_back(v);
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {        // y
        for (int j = 0; j < m; j++) {    // x
            pair<int, int> cur = {j, i};
            shape4MaxSum(matrix, 1, cur, matrix[i][j]);
            shape4Exception(matrix, cur);
        }
    }

    cout << max_sum << "\n";

    return 0;
}