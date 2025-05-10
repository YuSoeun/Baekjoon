#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;
vector<int> result;
vector<vector<int>> answer;  // 결과 저장용

void combi(int cnt, int cur) {
    if (cnt == M) {
        answer.push_back(result);
        return;
    }

    for (int i = cur; i < A.size(); i++) {
        result[cnt] = A[i];
        combi(cnt + 1, i);  // 중복 조합
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());  // 중복 제거

    result.assign(M, 0);
    combi(0, 0);

    sort(answer.begin(), answer.end());  // 최종 결과 정렬

    for (const auto& seq : answer) {
        for (auto e : seq) cout << e << " ";
        cout << "\n";
    }

    return 0;
}