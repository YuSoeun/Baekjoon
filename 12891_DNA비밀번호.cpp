#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, p, num;
    string temp;
    vector<int> v;
    int acgt_in[4] = {0};
    int acgt_cur[5] = {0};  // acgt_cur[4] -> other

    cin >> s >> p;
    cin >> temp;
    for (int i = 0; i < s; i++) {
        if (temp[i] == 'A') {
            v.push_back(0);
        } else if (temp[i] == 'C') {
            v.push_back(1);
        } else if (temp[i] == 'G') {
            v.push_back(2);
        } else if (temp[i] == 'T') {
            v.push_back(3);
        } else {
            v.push_back(4);
        }
    }

    for (int i = 0; i < 4; i++) {
        cin >> acgt_in[i];
    }

    queue<int> cur;
    int count = 0;
    for (int i = 0; i < s; i++) {
        acgt_cur[v[i]]++;
        cur.push(v[i]);
        
        if (i < p-1)
            continue;

        // 부분문자열이 잘 됐는지 확인
        int flag = 1;
        for (int j = 0; j < 4; j++) {
            if (acgt_cur[j] < acgt_in[j])
                flag = 0;
        }
        if (acgt_cur[4] > 0)
            flag = 0;

        if (flag == 1)
            count++;

        acgt_cur[cur.front()]--;
        cur.pop();
    }

    cout << count << "\n";

    return 0;
}