#include "quick_sort.hpp"

int main()
{
    int n;
    DATA * a;

    cin >> n;

    a = (DATA *)malloc(sizeof(DATA) * n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    quick_sort(a, 0, 1, n-1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}