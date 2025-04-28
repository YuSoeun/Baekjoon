#include <bits/stdc++.h>
using namespace std;

#define R first
#define C second

int N;
int udlr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int checkBoundary(int x, int y) {
    if (x < 0 || x >= N)  return 0;
    if (y < 0 || y >= N)  return 0;

    // in boundary
    return 1;
}

vector<vector<int> > markWire(vector<vector<int> > v, pair<int, int> cur, int dir[2], int& len) {
    pair<int, int> next = make_pair(cur.R+dir[0], cur.C+dir[1]);

    // check before put wire
    while (checkBoundary(next.R, next.C)) {
        if (v[next.R][next.C] != 0) {
            len = -1;
            return v;
        }

        next.R += dir[0];
        next.C += dir[1];
    }

    next = make_pair(cur.R+dir[0], cur.C+dir[1]);
    while (checkBoundary(next.R, next.C)) {
        cout << "see: (" << next.R << ", " << next.C << ")" << endl;
        v[next.R][next.C] = -1;

        next.R += dir[0];
        next.C += dir[1];
        len++;
    }   

    return v;
}

int min_size = INT_MAX;

int findWay(int len, vector<vector<int> > v, queue <pair<int, int> > p)
{
    if (p.size() <= 0) {
        if (len != -1 && len < min_size) {
            min_size = len;
        }
        return len;
    }
    pair<int, int> cur = p.front();  p.pop();
    int now_len = INT_MAX;

    cout << "행: " << cur.R << ", 열: " << cur.C << ", len: " << len << endl;
    for (auto dir : udlr) {
        // cout << "행 방향: " << dir[0] << ", 열 방향: " << dir[1] << endl;
        int new_len = 0;
        auto next = make_pair(cur.R + dir[0], cur.C + dir[1]);

        if (checkBoundary(next.R, next.C) == 0) {
            continue;
        }
        auto new_v = markWire(v, cur, dir, new_len);

        // 전선이 막힌 상황
        if (new_len < 0) {
            continue;
        }

        new_len = findWay(new_len, new_v, p);

        if (new_len < now_len && new_len != -1) {
            now_len = new_len;
        }

        cout << "new_len: " << new_len << ", now_len: " << now_len << endl;
    }

    if (now_len != INT_MAX) {
        return len + now_len;
    }

    return -1;
}

int main()
{
    int T, temp;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        vector <vector<int> > v(N);
        queue <pair<int, int> > core_point;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> temp;
                v[j].push_back(temp);
                if (temp == 1) {
                    core_point.push(make_pair(j, k)); 
                }
            }
        }

        cout << findWay(0, v, core_point) << endl;
    }
    return 0;
}