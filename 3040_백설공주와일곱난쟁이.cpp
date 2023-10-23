/*
    매일 매일 일곱 난쟁이는 광산으로 일을 하러 간다. 난쟁이가 일을 하는 동안 백설공주는 그들을 위해 저녁 식사를 준비한다. 백설공주는 의자 일곱개, 접시 일곱개, 나이프 일곱개를 준비한다.

    어느 날 광산에서 아홉 난쟁이가 돌아왔다. (왜 그리고 어떻게 아홉 난쟁이가 돌아왔는지는 아무도 모른다) 아홉 난쟁이는 각각 자신이 백설공주의 일곱 난쟁이라고 우기고 있다.

    백설공주는 이런 일이 생길 것을 대비해서, 난쟁이가 쓰고 다니는 모자에 100보다 작은 양의 정수를 적어 놓았다. 사실 백설 공주는 공주가 되기 전에 매우 유명한 수학자였다. 따라서, 일곱 난쟁이의 모자에 쓰여 있는 숫자의 합이 100이 되도록 적어 놓았다.

    아홉 난쟁이의 모자에 쓰여 있는 수가 주어졌을 때, 일곱 난쟁이를 찾는 프로그램을 작성하시오. (아홉 개의 수 중 합이 100이 되는 일곱 개의 수를 찾으시오)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int temp;
    int sum = 0;
    int sub;

    for (int i = 0; i < 9; i++) {
        cin >> temp;
        v.push_back(temp);

        sum += temp;
    }
    sub = sum - 100;

    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (i != j && v[i] + v[j] == sub) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << v[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}