#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define LL long long

int N, M, K;
vector<LL> segtree;
vector<LL> lazy;
int tree_size, tree_offset;

// 세그먼트 트리 초기화
void init() {
    cin >> N >> M >> K;
    
    // 트리 크기 설정
    tree_size = 1 << (int)ceil(log2(N)); // 가장 가까운 2의 제곱수
    tree_offset = tree_size - 1;
    segtree.assign(tree_size * 2, 0);
    lazy.assign(tree_size * 2, 0);

    // 리프 노드 초기화
    for (int i = 0; i < N; i++) {
        cin >> segtree[tree_offset + i + 1];
    }

    // 내부 노드 초기화
    for (int i = tree_offset; i > 0; i--) {
        segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
    }
}

// lazy propagation 수행
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        segtree[node] += (end - start + 1) * lazy[node];
        if (start != end) { // 리프 노드가 아닐 경우
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// 구간 업데이트
void update(int node, int start, int end, int left, int right, LL value) {
    propagate(node, start, end);
    if (start > right || end < left) return;                    // 범위 밖
    if (start >= left && end <= right) {                        // 완전 포함
        lazy[node] += value;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

// 구간 합 구하기
LL query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if (start > right || end < left) return 0;                      // 범위 밖
    if (start >= left && end <= right) return segtree[node];  // 완전 포함
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // 세그먼트 트리 초기화
    init();

    // 사용자 입력 처리
    for (int i = 0; i < M + K; i++) {
        int command, start, end;
        cin >> command >> start >> end;
        if (command == 1) {
            // 구간 업데이트
            LL adder;
            cin >> adder;
            update(1, 1, tree_size, start, end, adder);
        } else {
            // 구간 합 구하기
            cout << query(1, 1, tree_size, start, end) << "\n";
        }
    }

    return 0;
}