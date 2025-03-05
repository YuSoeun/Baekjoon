#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, R;

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N >> R;
    int cur;
    for (int i = 0; i < N-1; i++) {
        cin >> cur;
        int common = __gcd(cur, R);

        cout << R/common <<  "/" << cur/common << "\n";
    }
    
    return 0;
}