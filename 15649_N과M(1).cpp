#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void getSequence (vector<int>& v) {
    if (v.size() == m) {
        // cout << "case 1" << endl;
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    } else if (v.size() > m){
        // cout << "case 2" << endl;
        return;
    } else {
        // cout << "case 3" << endl;
        for (int i = 1; i <= n; i++) {
            if (find(v.begin(), v.end(), i) != v.end())  continue;
            v.push_back(i);
            getSequence(v);
            v.pop_back();
        }
        return;
     }
}

int main()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);

    cin >> n >> m;
    vector<int> v;

    getSequence(v);

    return 0;
}