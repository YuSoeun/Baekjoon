#include <iostream>
#include <vector>
using namespace std;
#define DATA long long

struct Element {
    DATA value;
    int isZero;
};

DATA N, M, K;
vector<DATA> A;
vector<Element> seg;

DATA MOD = 1000000007LL;
DATA update(DATA idx, DATA start, DATA end, DATA target, DATA prev, DATA cur);

void printVector() {
    for (auto e : seg) {
        cout << e.value << " ";
    }
    cout << "\n";
}

void init() {
    seg.assign(N*4, {1, 0});
    A.assign(N+1, 1);

    DATA value;
    for (DATA i = 1; i <= N; i++) {
        cin >> value;
        update(1, 1, N, i, A[i-1], value);
        A[i] = value;
    }
}

DATA update(DATA idx, DATA start, DATA end, DATA target, DATA prev, DATA cur) {
    // 0은 무시
    if (cur == 0)    seg[idx].isZero++;
    if (prev == 0)   seg[idx].isZero--;

    if (start == end) {
        seg[idx].value = cur;
        return seg[idx].value;
    }
    
    DATA result = 1;
    DATA left = -1, right = -1;
    DATA mid = (start + end) / 2;
    if (target <= mid) left = update(idx*2, start, mid, target, prev, cur);
    else               right = update(idx*2 + 1, mid+1, end, target, prev, cur);

    // 왼쪽이면
    if (left > -1)        result = (left * seg[idx*2+1].value) % MOD;
    // 오른쪽이면
    else if (right > -1)  result = (seg[idx*2].value * right) % MOD;
    seg[idx].value = result;

    return result;
}

DATA multifly(DATA idx, DATA start, DATA end, DATA a, DATA b) {
    if (b < start || a > end)   return 1;
    if (seg[idx].isZero > 0)    return 0;
    if (a <= start && end <= b) return seg[idx].value;

    DATA mid = (start + end) / 2;
    return (multifly(idx*2, start, mid, a, b) % MOD) *
           (multifly(idx*2 + 1, mid+1, end, a, b) % MOD) % MOD;
}

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    init();

    DATA command, a, b;
    for (DATA i = 0; i < M+K; i++) {
        cin >> command >> a >> b;
        if (command == 1) {
            update(1, 1, N, a, A[a], b);
            A[a] = b;
        } else {
            cout << multifly(1, 1, N, a, b) << "\n";
        }
    }

    return 0;
}