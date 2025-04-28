#include <bits/stdc++.h>
using namespace std;

int countChar(vector<char> &v, char c)
{
    int result = 0;

    for (char e : v)
        if (e == c)
            result++;

    return result;
}

int main()
{
    int min_b_cnt = INT_MAX;
    int a_cnt = 0;
    int len;
    string input;
    vector<char> window;

    cin >> input;
    len = input.length();

    for (auto e : input) {
        if (e == 'a')
            a_cnt++;
    }

    if (a_cnt == 0) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < a_cnt; i++) {
        window.push_back(input[i]);
    }
    
    int cur = a_cnt-1;
    for (int i = 0; i < len; i++) {
        int cnt = countChar(window, 'b');

        if (min_b_cnt > cnt)
            min_b_cnt = cnt;

        if (++cur >= len)
            cur -= len;

        window.erase(window.begin());
        window.push_back(input[cur]);
    }

    cout << min_b_cnt << "\n";

    return 0;
}