#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    vector<int> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        s.push_back(temp);
    }
    sort(s.begin(), s.end());

    int count = 0;
    
    for (int k = 0; k < n; k++) {
        int i = 0, j = n-1;
        // cout << "s[k]: " << s[k] << "\n";
        while (i < j) {
            if (i == k) {
                i++; continue;
            } else if (j == k) {
                j--; continue;
            }
            if (s[i] + s[j] == s[k]) {
                count++;
                break;
                // i++;
            } else if (s[i] + s[j] < s[k]) {
                i++;
            } else {
                j--;
            }
        }
        
    }

    cout << count << "\n";

    return 0;
}