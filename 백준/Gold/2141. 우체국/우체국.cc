#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL N;
vector<pair<LL,LL>> A;

// 1시간 반 고민하고 답 본 문제, 가중 중앙값(weighted median) 아이디어 사용
// “정렬된 위치에서 누적 인구가 전체 인구의 절반을 넘는 첫 지점”이 우체국을 세울 최적 위치

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (LL i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;  // idx, people
    }

    sort(A.begin(), A.end());

    LL sum = 0;
    for (auto &p : A) sum += p.second;          // 전체 인구
    LL half = (sum + 1) / 2;                    // 절반 이상 기준

    LL acc = 0;
    for (auto &[idx, people] : A) {
        acc += people;
        if (acc >= half) {
            cout << idx << "\n";
            break;
        }
    }
    return 0;
}