/*
    지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

    미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

    지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.

    불은 각 지점에서 네 방향으로 확산된다.

    지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.

    지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int row, column;
    char temp;
    queue<pair<int, int> > jihun, fire;
    vector<vector<int> > maze;
    
    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        vector<int> v1;
        maze.push_back(v1);
        for (int j = 0; j < column; j++) {
            cin >> temp;

            switch (temp) {
            case '#':
                maze[i].push_back(-1);
                break;
            case '.':
                maze[i].push_back(0);
                break;
            case 'J':
                maze[i].push_back(0);
                jihun.push(make_pair(j, i));
                break;
            case 'F':
                maze[i].push_back(-2);
                fire.push(make_pair(j, i));
                break;
            default:
                maze[i].push_back(-1);
                break;
            }
        }
    }

    int nx, ny;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int> > maze2 = maze;

    // fire 미로에 싹 표시
    while (!fire.empty()) {
        auto cur = fire.front(); fire.pop();
        if (maze[cur.Y][cur.X] == -2)  maze[cur.Y][cur.X] = 1;

        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];

            if (nx < 0 || nx >= column || ny < 0 || ny >= row)  continue;
            if (maze[ny][nx] == -1 || maze[ny][nx] == -2 || maze[ny][nx] > 0)  continue;
            fire.push(make_pair(nx, ny));
            maze[ny][nx] = maze[cur.Y][cur.X] + 1;
        }
    }

    // cout << "fire" << endl;
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < column; j++) {
    //         cout << maze[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    // jihun 관련
    while (!jihun.empty()) {
        auto cur = jihun.front(); jihun.pop();
        if (maze2[cur.Y][cur.X] == 0)  maze2[cur.Y][cur.X] = 1;

        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];

            if (nx < 0 || nx >= column || ny < 0 || ny >= row) {
                cout << maze2[cur.Y][cur.X] << endl;

                return 0;
            };
            if (maze2[ny][nx] == -1 || maze2[ny][nx] > 0)   continue;
            if (maze[ny][nx] != 0 && maze[ny][nx] <= maze2[cur.Y][cur.X] + 1)   continue;
            
            jihun.push(make_pair(nx, ny));
            maze2[ny][nx] = maze2[cur.Y][cur.X] + 1;
        }
    }

    // cout << "jihun" << endl;
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < column; j++) {
    //         cout << maze2[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}