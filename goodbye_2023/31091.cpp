#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    int f_default = 0;
    deque<int> pos;
    deque<int> neg;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > 0) {
            pos.push_back(temp);
        } else {
            neg.push_back(temp);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), std::greater<int>());

    vector <int> result;
    int pos_size = pos.size(), neg_size = neg.size();

    // 0명에서 n명
    for (int p = 0; p < n+1; p++) {
        int f = 0;
        // index 돌기
        for (int j = 0; j < pos_size; j++) {
            if (pos[j] == p) {
                pos.pop_front();
                j--; pos_size--;
            } else if (pos[j] > p) {
                break;
            }
        }
        f += pos_size;

        for (int j = 0; j < neg_size; j++) {
            if (abs(neg[j]) < p) {
                f_default++;
                neg.pop_front();
                j--; neg_size--;
            } else if (abs(neg[j]) >= p) {
                break;
            }
        }
        
        f += f_default;
        if (f == p)
            result.push_back(f);

        if (pos_size + neg_size + f_default <= p)
            break;
        // if (pos_size <= 0 && neg_size <= 0)
        //     break;
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}