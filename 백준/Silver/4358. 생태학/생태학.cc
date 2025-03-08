#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map <string, int> m;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string input;
    
    int cnt = 0;
    while (getline(cin, input)) {
        m[input]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);
    
    for (auto e : m) {
        cout << e.first << " " << (double)e.second/cnt*100 << "\n";
    }

    return 0;
}