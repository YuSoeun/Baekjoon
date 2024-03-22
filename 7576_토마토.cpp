#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
vector <pair<int, int> > udlr = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int matrix[1001][1001];
int m, n;

int spread(int i, int j)
{
    int changed = 0;

    if (i+1 < n && matrix[i+udlr[0].X][j+udlr[0].Y] != -1)
        matrix[i+udlr[0].X][j+udlr[0].Y] = 1;  changed = 1;
    if (i-1 >= 0 && matrix[i+udlr[1].X][j+udlr[1].Y] != -1)
        matrix[i+udlr[1].X][j+udlr[1].Y] = 1;  changed = 1;
    if (j+1 < m && matrix[i+udlr[2].X][j+udlr[2].Y] != -1)
        matrix[i+udlr[2].X][j+udlr[2].Y] = 1;  changed = 1;
    if (j-1 >= 0 && matrix[i+udlr[0].X][j+udlr[0].Y] != -1)
        matrix[i+udlr[3].X][j+udlr[3].Y] = 1;  changed = 1;
    return changed;
}

int bfs(int &time)
{
    int flag = 0;
    // 기준점 1 찾고, 0인 상하좌우에 퍼뜨리기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int rtn = spread(i, j);
                if (rtn == 1)
                    flag = 1;
            }
        }
    }

    if (flag == 0) {
        return time;
    } else {
        time++;
        // bfs(time);
    }
    return time;
}

int main()
{
    int temp, time = 0;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
    }

    bfs(time);

    // int flag = 0;
    // if (time == 0) {
    //     // 다 -1인지 보기
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == -1) {
    //                 flag = 1;
    //                 cout << -1;
    //                 break;
    //             }
    //         }
    //     }
    //     if (flag == 0) {
    //         cout << time;
    //     }
    // } else {
        cout << time;
    // }

    return 0;
}