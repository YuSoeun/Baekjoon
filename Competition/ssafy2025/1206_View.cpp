#include <bits/stdc++.h>
using namespace std;

int calculateJomang(vector<int>& l, vector<int>& r, int mid)
{
    int result;
    int l_max = *max_element(l.begin(), l.end());
    int r_max = *max_element(r.begin(), r.end());

    // cout << l_max << " : " << mid << " : " << r_max << endl;

    int max = (l_max > r_max) ? l_max : r_max;
    result = mid - max;

    if (result > 0) {
        return result;
    } else {
        return 0;
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int temp, T = 10;
    for (int i = 0; i < T; i++) {
        int result = 0;
        int mid = -1, N;
        vector<int> left, right; // size=2

        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (right.size() < 2) {
                right.push_back(temp);
            } else {
                if (left.size() >= 2) {
                    // calculate jomang
                    result += calculateJomang(left, right, mid);
                    // cout << "result: " << result << endl;
                    left.erase(left.begin());
                }
                if (mid != -1) {
                    left.push_back(mid);
                }
                mid  = right.front();
                right.erase(right.begin());
                right.push_back(temp);
            }
        }
        result += calculateJomang(left, right, mid);
        // cout << "result: " << result << endl;

        cout << "#" << i+1 << " " <<  result << endl;
    }

    return 0;
}