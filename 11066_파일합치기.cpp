#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, sum = 0;
    int result = 0;
    priority_queue <int> t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        t.push(temp);
        sum += temp;
    }

    // for (auto e : t) {
    //     cout << e << " ";
    // }
    // cout << endl;

    while (1) {
        
        result += sum;
        
        if (sum <= 0) {
            break
        }
    }

    cout << result << "\n";
}