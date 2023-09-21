/*

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1, v2;
    int temp;

    for (int i = 0; i < 6; i++) {
        cin >> temp;
        v1.push_back(temp);
    }

    for (int i = 0; i < 6; i++) {
        cin >> temp;
        v2.push_back(temp);
    }

    // 약분 -> 최대 공약수를 구해서 나눈다? 이기는 횟수 / 36
    int win = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (v1[i] > v2[j])    win++;
        }
    }

    int gcd_result = std::gcd(win,  36);
    cout << win / gcd_result << "/" << 36/gcd_result << "\n";

    return 0;
}