#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[51][51];
int dirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};

int inBound(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int getMaxWidth(int r, int c) {
    int result = 1;
    int width = 0;
    
    while (1) {
        width++;
        for (int i = 0; i < 3; i++) {
            auto dir = dirs[i];
            int nr = r + dir[0] * width;
            int nc = c + dir[1] * width;

            if (!inBound(nr, nc) || A[r][c] != A[nr][nc]) {
                break;
            }
            if (i == 2)  result = max(result, (width+1)*(width+1));
        }

        if (width + r >= N || width + c >= M) break;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N >> M;
    fill(&A[0][0], &A[50][51], 0);
    for (int r = 0; r < N; r++) {
        string line;
        cin >> line;
        for (int c = 0; c < M; c++) {
            A[r][c] = line[c] - '0';
        }
    }

    int result = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            result = max(getMaxWidth(r, c), result);
        }
    }
    cout << result << "\n";

    return 0;
}