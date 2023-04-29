#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int countMaxZero(vector<vector<int> >& matrix, queue<pair<int, int> >& cctv);

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int column, row;

int checkWatchArea(vector<vector<int> > matrix, queue<pair<int, int> > cctv, pair<int, int> cur, int index)
{
    // cctv번호 파악해서 여러 방향으로 체크 가능하게
    int cctv_num = matrix[cur.Y][cur.X];
    for (int i = 0; i < 4; i++) {
        if (i == 1 && cctv_num != 5)  continue;
        if (i == 2 && (cctv_num == 1 || cctv_num == 3))  continue;
        if (i == 3 && (cctv_num == 1 || cctv_num == 2))  continue;
        int dir = (index + i) % 4;       // 체크할 방향

        int temp = 0;
        pair<int, int> watch = cur;
        while (temp != 6) {
            watch = make_pair(watch.X + x[dir], watch.Y + y[dir]);
            if (watch.X < 0 || watch.X >= column) break;
            if (watch.Y < 0 || watch.Y >= row) break;

            temp = matrix[watch.Y][watch.X];
            if (temp != 0)  continue;
            matrix[watch.Y][watch.X] = 7;
        }
    }
    return countMaxZero(matrix, cctv);
}

int min_zero = 64;
int countMaxZero(vector<vector<int> >& matrix, queue<pair<int, int> >& cctv)
{
    if (cctv.empty()) {
        int count_zero = 0;
        for (int i = 0; i < row; i++) {
            count_zero += count(matrix[i].begin(), matrix[i].end(), 0);
        }

        // cout << "count_zero: " << count_zero << "\n";
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < column; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return count_zero;
    } else {
        pair<int, int> cur_cctv = cctv.front(); cctv.pop();

        for (int i = 0; i < 4; i++) {
            int count = checkWatchArea(matrix, cctv, cur_cctv, i);
            if (count < min_zero) min_zero = count;
        }
        return min_zero;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int temp, cctv_num = 0;
    vector<vector<int> > matrix;
    queue<pair<int, int> > cctv;

    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        vector<int> v1; matrix.push_back(v1);

        for (int j = 0; j < column; j++) {
            cin >> temp;
            matrix[i].push_back(temp);

            if (temp >= 1 && temp <= 5) {
                cctv.push(make_pair(j, i));
            }
        }
    }

    int result = countMaxZero(matrix, cctv);
    cout << result << '\n';

    return 0;
}