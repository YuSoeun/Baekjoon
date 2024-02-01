#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    int f_default = 0;
    vector<int> cond;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        cond.push_back(temp);
    }

    vector <int> result;

    // 0명에서 n명
    for (int p = 0; p < n+1; p++) {
        int f = 0;
        // index 돌기
        for (int j = 0; j < cond.size(); j++) {
            int num = cond[j];
            // 앞으로도 항상 true인 애 삭제
            if (num > 0) {
                if (num == p) {
                    cond.erase(cond.begin() + j);
                    j--;
                } else if (num > p) {
                    f++;
                }
            } else if (num <= 0) {
                if (abs(num) < p) {
                    f_default++;
                    cond.erase(cond.begin() + j);
                    j--;
                }
            }
        }
        f += f_default;
        if (f == p)
            result.push_back(f);
        if (cond.size() <= f_default)
            break;
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}