#include <bits/stdc++.h>
using namespace std;

int L, C;
vector <char> alpha, vowel;

void make_password(int index, int vowel_cnt, vector<char> passwd)
{
    if (passwd.size() == L) {
        if (vowel_cnt >= 1 && vowel_cnt <= L-2) {
            for (auto e : passwd)
                cout << e;
            cout << "\n";
        }
        return;
    }
    if (index >= C)
        return;

    int flag = 0;
    if (find(vowel.begin(), vowel.end(), alpha[index]) != end(vowel))
        flag = 1;
    
    vector <char> new_passwd = passwd;
    new_passwd.push_back(alpha[index]);

    index += 1;
    make_password(index, vowel_cnt+flag, new_passwd);
    make_password(index, vowel_cnt, passwd);

    return;
}

int main()
{
    char temp;
    vector <char> password;
    vowel.push_back('a'); vowel.push_back('e'); vowel.push_back('i'); vowel.push_back('o'); vowel.push_back('u'); 

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> temp;
        alpha.push_back(temp);
    }
    sort(alpha.begin(), alpha.end());

    make_password(0, 0, password);

    return 0;
}