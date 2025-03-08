#include <iostream>
#include <set>
using namespace std;

int N, M;
set<string> sets;
string input;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        sets.insert(input);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (sets.find(input) != sets.end()) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}