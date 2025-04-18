#include <bits/stdc++.h>
using namespace std;

int N, M;
string input, target;
vector<char> result;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> input >> target;

    N = input.size();
    M = target.size();

    for (int i = 0; i < N; i++) {
        result.push_back(input[i]);

            int isExplode = true;
        if (result.size() >= M) {
            for (int j = 0; j < M; j++) {
                int cur = result.size() - (M - j);
                if (result[cur] != target[j]) {
                    isExplode = false;
                    break;
                }
            }
            if (isExplode) {
                for (auto e : target)  result.pop_back();
            }
        }
    }
    
    if (result.empty()) cout << "FRULA\n";
    else {
        for (char e : result) cout << e;
        cout << "\n";
    }
    
    return 0;
}