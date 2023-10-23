#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // 뒤에 2개 빼고 제일 작은거 앞에 오도록
    // for (int i = 0; i < s.size() - 2; i++) {
    //     int index = i;
    //     int min = 51;

    //     for (int j = i; j < s.size(); j++) {
    //         // 제일 작은 거 인덱스 구하기
    //         if (s[i] < min) {
    //             index = j;
    //             min = s[i];
    //         }
    //         reverse(s.begin(), s.begin() + index);
    //         reverse(s.begin() + index+1, s.size()-1);
    //         reverse(s.begin()+s.size()-1, s.begin()+s.size());
    //     }
    // }

    string min = s;

    for (int i = 0; i < s.size()-2; i++) {
        for (int j = i+1; j < s.size()-1; j++) {
            for (int k = j+1; k < s.size(); k++) {
                reverse(s.begin(), s.begin() + i);
                reverse(s.begin() + i+1, s.begin() + j);
                reverse(s.begin() + j+1, s.begin() + s.size());
                
                cout << min << endl;
                if (min > s) {
                    min = s;
                }
            }
        }
    }

    cout << min << endl;

    return 0;
}