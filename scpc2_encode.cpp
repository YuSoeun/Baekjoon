#include <iostream>
#include <vector>

using namespace std;

int encode(int a, int& n, int& t, int i) {
    int b = 0;

    // i > t and a(i−t)=1
    if (i > t && a == 1+t) {
        b = 1;
    }
    // i ≤ n−ti ≤ n−t and ai+t=1 (ai = 1-t)
    if (i+t <= n && a == 1-t) {
        b = 1;
    }
    
    return b;
}

int main()
{
    string a;
    int n, t, b, alpha;
    vector <int> Result;

    cin >> n >> t;
        
    b = 0;
    cin >> a;

    for (int i; i < n; i++) {
        alpha = a[i] - '0';

        b = encode(alpha, n, t, i+1);

        Result.push_back(b);
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i];
    }
    cout << endl;

    return 0;
}