#include <iostream>
#include <vector>
using namespace std;

vector <int> a;
vector <int> q;
int getXfromFuction(int l, int r, int j);

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;           // length of the array a
    int q;           // the number of queries

    cin >> n >> q;
    int temp = 0;
    a.push_back(temp);      // dummy

    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    int l, r, x, y;
    for (int line = 0; line < q; line++) {
        int result = 0;
        cin >> l >> r >> x >> y;

        for (int j = x ; j <= y; j++) {
            result += getXfromFuction(l, r, j);
        }  
        cout << result << "\n";
    }

    return 0;
}

int getXfromFuction(int l, int r, int j)
{
    vector <int> element;
    int result = 0;
    int index = j;

    // 뒤에서부터 안 겹치는 거 찾기
    for (int x = j ; x >= l; x--) {
        if (x > j)  return 0;
        // cout << "a" << x << ": " << a[x] << endl;
        if (find(element.begin(), element.end(), a[x]) == element.end()) {
            // 안 겹치는 거
            index = x;
            // cout << "index: " << index << "\n";
        }
        if (x <= r) {
            result += index;
        }
        element.push_back(a[x]);
        // cout << "j: " << j << ", i: " << x << ", index: " << index << endl;
    }

    return result;
}