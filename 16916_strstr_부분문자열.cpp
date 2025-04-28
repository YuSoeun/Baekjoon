#include <bits/stdc++.h>
using namespace std;

void find_str(char const *str, char const *substr)
{
    int result;
    char *pos = (char *)strstr(str, substr);
    pos ? result = 1
        : result = 0;

    cout << result << "\n";
}

int main(void)
{
    char str[1000001], substr[1000001];

    cin >> str >> substr;
    find_str(str, substr);

    return 0;
}