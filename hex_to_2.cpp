#include <iostream>
using namespace std;

int a[18] = {49h, 60h, 67h, 74h, 63h, 67h, 42h, 66h, 80h, 78h, 69h, 69h, 7Bh, 99h, 6Dh, 88h, 68h, 94h, 9Fh, 8Dh, 4Dh, 0A5h, 9Dh};

int main()
{
    for (int i = 0; i < 0x18; ++i) {
        printf("%c", a[i] - (2*i xor i));
    }

    return 0;
}