/*
    한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다.
    예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
    N > 1인 경우, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

    입력
    첫째 줄에 정수 N, r, c가 주어진다.

    출력
    r행 c열을 몇 번째로 방문했는지 출력한다.

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void makeVector(vector<vector<int> > &v, int n, int count);

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    vector<vector<int> > v;

    cin >> n >> r >> c;

    // 2^1인 경우는 만들기
    for (int i = 0; i < pow(2, n); i++) {
        vector<int> v1;
        v.push_back(v1);
    }
    v[0].push_back(0);
    v[0].push_back(1);
    v[1].push_back(0);
    v[1].push_back(1);

    makeVector(v, n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
        }
    }

    cout << v[r][c];

    return 0;
}

void makeVector(vector<vector<int> > &v, int n, int count) {
    if (n <= count) {
        return;
    }
    
    // 오, 아래, 위에 붙여넣기
    for (int i = 0; i < 3; i++) {
        int size = (count+1) * 2;
        // 오른쪽 - 각 행 size 만큼 복붙
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                v[j].push_back(v[j][k] + pow(2, j+1));
            }
        } 
    }

    // makeVector(v, n, count++);
}