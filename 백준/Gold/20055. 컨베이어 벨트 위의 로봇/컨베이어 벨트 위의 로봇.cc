#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 문제 설명이 불친절하고 이상하다 이거,,

int N;
int K;      // 내구도가 0인 칸의 최대 수
vector<int> belt;
vector<int> robot;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> K;
    belt.assign(2*N, 0);
    robot.assign(2*N, 0);

    for (int i = 0; i < 2*N; i++) {
        cin >> belt[i];
    }

    int result = 0;
    while (1) {
        result++;
        // 1. 벨트 회전
        int temp = belt.back();
        for (int i = 2*N-1; i > 0; i--) {
            belt[i] = belt[i-1];
        }
        belt[0] = temp;

        // 1-2. 로봇 회전
        for (int i = N-2; i > 0; i--) {
            robot[i] = robot[i-1];
        }
        robot[0] = 0;
        robot[N-1] = 0;

        // 2. 로봇 이동
        for (int i = N-2; i >= 0; i--) {
            if (robot[i] == 1 && robot[i+1] == 0 && belt[i+1] >= 1) {
                robot[i+1] = 1;
                robot[i] = 0;
                belt[i+1]--;
            }
        }
        robot[N-1] = 0;

        // 3. 로봇 올리기
        if (belt[0] > 0) {
            robot[0] = 1;
            belt[0]--;
        }

        // 4. 내구도 0인 칸 개수 세기
        int count = 0;
        for (int i = 0; i < 2*N; i++) {
            if (belt[i] == 0) count++;
        }
        if (count >= K) break;
    }

    cout << result << "\n";

    return 0;
}