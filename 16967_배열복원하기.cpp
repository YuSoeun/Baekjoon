#include <iostream>
using namespace std;

int A[300][300] = {0, };
int B[600][600] = {0, };

int main()
{
    int H, W, X, Y;

    cin >> H >> W >> X >> Y;
    for (int i = 0; i < H+X; i++) {
        for (int j = 0; j < W+Y; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < X) {
                A[i][j] = B[i][j];
            } else if (j < Y) {
                A[i][j] = B[i][j];
            }
            // else if (i < X && j < Y) {
            //     A[i][j] = B[i][j] - B[i+X][j+Y];
            // }
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}