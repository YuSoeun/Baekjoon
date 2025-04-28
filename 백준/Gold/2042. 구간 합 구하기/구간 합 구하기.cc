#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define DATA long long
int N, M, K;
vector<DATA> A, BITS;

void init() {
    A.assign(N+1, 0);
    BITS.assign(N+1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        DATA x = i;                  // 마지막 1이 나타내는 값
        while (x <= N) {
            BITS[x] += A[i];
            x += (x & -x);
        }
    }
}

// a번째 수를 b로
void update(DATA x, DATA value) {
    DATA diff = value - A[x];
    A[x] = value;

    while (x <= N) {
        BITS[x] += diff;
        x += (x & -x);          // 마지막 1 더하기
    }
}

// 1번째 수부터 x번째 수까지의 합 출력
DATA sum(DATA x) {
    DATA result = 0;

    while (x > 0) {
        result += BITS[x];
        x -= (x & -x);    // 마지막 1 빼기
    }

    return result;
}

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    init();

    int method;
    DATA a, b;
    for (int i = 0; i < M+K; i++) {
        cin >> method >> a >> b;
        if (method == 1) {
            update(a, b);
        } else {
            cout << sum(b) - sum(a-1) << "\n";
        }
    }
    
    return 0;
}