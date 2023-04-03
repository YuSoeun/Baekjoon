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
#define x first
#define y second

/* pop queue and 상하좌우 queue에 넣기 */
int insertTDLR(vector<vector<int>>& v, queue<pair<int, int>>& q, int r, int c)
{
    int flag = 0;
    pair<int, int>& p = q.front();
    pair<int, int> temp;
    q.pop();
    int count = v[p.y][p.x] + 1;
    cout << p.x << ", " << p.y << endl;

    if (p.x-1 >= 0) {           // Left
        q.push({p.x-1, p.y});
        v[p.y][p.x-1] = count;
    } else {
        flag = 1;
    }
    if (p.x+1 < c) {            // Right
        q.push({p.x+1, p.y});
        v[p.y][p.x+1] = count;
    } else {
        flag = 1;
    }
    if (p.y-1 >= 0) {           // Down
        q.push({p.x, p.y-1});
        v[p.y-1][p.x] = count;
    } else {
        flag = 1;
    }
    if (p.y+1 >= 0) {           // Up
        q.push({p.x, p.y+1});
        v[p.y+1][p.x] = count;
    } else {
        flag = 1;
    }

    return flag;
}

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    queue<pair<int, int>> jihun, fire;
    vector<vector<int>> v;
    char temp;
    
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        vector<int> v1;
        v.push_back(v1);
        for (int j = 0; j < c; j++) {
            cin >> temp;

            switch (temp) {
            case '#':
                v[i].push_back(-1);
                break;
            case '.':
                v[i].push_back(0);
            case 'J':
                v[i].push_back(1);
                jihun.push(make_pair(j, i));
            case 'F':
                v[i].push_back(-1);
                fire.push(make_pair(j, i));
            default:
                break;
            }
        }
    }
    
    vector<vector<int>> v2 = v;
    // fire 미로에 싹 표시
    while (1) {
        if (fire.empty()) {
            break;
        }

        insertTDLR(v, fire, r, c);
        break;
    }

    // jihun 관련
    // while (1) {
    //     // jihun이 더 이상 이동할 수 없으면 break
    //     if (jihun.empty()) {
    //         break;
    //     }

    //     insertTDLR(v2, jihun, r, c);
    //     // 불이랑 비교 -> 탈출할 때 까지의 시간이 더 적게 걸리냐
    // }

    // // 탈출한 경우를 어떻게 알지 ?

    return 0;
}