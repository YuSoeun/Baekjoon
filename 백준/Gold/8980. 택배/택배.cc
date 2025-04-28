#include <bits/stdc++.h>
using namespace std;

// 1시간 고민하고 답 본 문제
// "먼 거리로 가는 박스를 나중에 싣고, 가까운 박스를 우선 실는 것"이 최적
// 구간 적재량을 저장하는 배열을 같이 써야 풀 수 있다 

struct Node {
    int s;
    int e;
    int boxCount;
};

struct boxCompare {
    bool operator()(Node x, Node y) {
        if (x.e == y.e) return x.s > y.s;
        return x.e > y.e;
    }
};

int N, C, M;
priority_queue <Node, vector<Node>, boxCompare> boxes;

int goTruck() {
    int curLoad[2001] = {};
    int result = 0;

    while (!boxes.empty()) {
        auto cur = boxes.top(); boxes.pop();

        // cur.s ~ cur.e-1 사이에서 현재 가장 많이 실려있는 구간 찾기
        int maxLoad = 0;
        for (int i = cur.s; i < cur.e; ++i) {
            maxLoad = max(maxLoad, curLoad[i]);
        }

        int canLoad = min(C - maxLoad, cur.boxCount);
        result += canLoad;

        // cur.s ~ cur.e-1 구간에 적재량 반영
        for (int i = cur.s; i < cur.e; ++i) {
            curLoad[i] += canLoad;
        }
    }

    return result;
}

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> C >> M;

    int start, end, count;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> count;
        boxes.push({start, end, count});
    }

    cout << goTruck() << "\n";

    return 0;
}