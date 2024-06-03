#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string min = s;

    for (int i = 1; i < s.size()-2; i++) {
        for (int j = 0; j < s.size()-i-2; j++) {
            string temp = s; 
            reverse(temp.begin(), temp.begin() + j+1);
            reverse(temp.begin() + j+1, temp.begin() + j+i+1);
            // reverse(temp.begin() + j+i+1, temp.end());
            
            cout << temp << endl;
            if (min > temp) {
                min = temp;
            }
        }
    }

    cout << min << endl;

    return 0;
}