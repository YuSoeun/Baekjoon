#include "quick_sort.hpp"
#define DEBUG

int count_compare = 0;

void quick_sort(DATA * a, int pivot, int low, int high)
{
    DATA temp;
    int n = high - pivot + 1;

    while (low <= high) {
        count_compare++;
        if (a[low] > a[pivot]) {
            count_compare++;
            if (a[high] > a[pivot]) {
                high--;
            } else {
                temp = a[high];
                a[high] = a[low];
                a[low] = temp;
            }
        } else {
            low++;
        }

        count_compare++;
        if (a[high] > a[pivot]) {
            high--;
        }
    }

    temp = a[pivot];
    a[pivot] = a[high];
    a[high] = temp;

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        cout << a[pivot+i] << ' ';
    }
    cout << '\n';
#endif

    ++pivot;

    if (high > pivot) {
        quick_sort(a, pivot, pivot + 1, high - 1);
    }
    if (high + 1 < n - 1) {
        quick_sort(a, high + 1, high + 2, n - 1);
    }

    cout << "count_compare: " << count_compare << endl;
}