#include <iostream>
using namespace std;

int matrix[200][200];

int main()
{
    int R, C, N;
    char temp;

    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == '.') {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = 1;
            }
        }
    }

    // 1초 동안 아무것도 하지 않기 때문에 N에서 1 빼기
    for (int k = 0; k < N-1; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == -1) {
                    // 폭탄 설치
                    if (k % 2 == 0)
                        matrix[i][j] = 0;
                } else {
                    matrix[i][j]++;
                }
                
                if (matrix[i][j] == 3) {
                    // 폭파
                    matrix[i][j] = -1;
                    if (i-1 >= 0)   matrix[i-1][j] = -1;
                    if (j-1 >= 0)   matrix[i][j-1] = -1;
                    if (i+1 < R && matrix[i+1][j] != 2)    matrix[i+1][j] = -1;
                    if (j+1 < C && matrix[i][j+1] != 2)    matrix[i][j+1] = -1;
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == -1) {
                cout << ".";
            } else {
                cout << "O";
            }
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}