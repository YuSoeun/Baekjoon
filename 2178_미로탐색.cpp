/*
    N×M크기의 배열로 표현되는 미로가 있다.

    1	0	1	1	1	1
    1	0	1	0	1	0
    1	0	1	0	1	1
    1	1	1	0	1	1
    미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
    이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를
    구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

    위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int column, row;
    char temp;
    vector<vector<int> > maze;

    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        vector<int> v;
        maze.push_back(v);
        for (int j = 0; j < column; j++) {
            cin >> temp;
            if (temp == '0') {
                maze[i].push_back(-1);
            } else if (temp == '1') {
                maze[i].push_back(0);
            }
        }
    }

    int nx, ny;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int> > move;
    move.push(make_pair(0, 0));
    maze[0][0] = 1;

    while (!move.empty()) {
        auto cur = move.front();
        move.pop();

        // for문 돌면서 상하좌우 표시
        for (int i = 0; i < 4; i++) {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];

            if (nx < 0 || nx >= column || ny < 0 || ny >= row)  continue;
            if (maze[ny][nx] == -1 || maze[ny][nx] > 0)  continue;

            move.push(make_pair(nx, ny));
            maze[ny][nx] = maze[cur.second][cur.first] + 1;
        }
    }

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < column; j++) {
    //         cout << maze[i][j] << "   ";
    //     }
    //     cout << "\n";
    // }

    cout << maze[row-1][column-1];

    return 0;
}