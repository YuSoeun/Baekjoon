#include <iostream>
#include <vector>

using namespace std;

vector <int> Result;

void decode(int& bin, int& n, int& t, int i) {
    int a_max = 0;
    int temp = 0;

    // bin이 1이면.
    if (bin == 1) {
        // i > t 일 때 a(i−t)=1인 ai를 찾는다.
        if (i > t && i-t > 0) {
            a_max = i-t;    // 2
        }
        // i ≤ n−t and a(i+t)=1
        if (i <= n-t && i+t <= n) {
            if (Result[a_max] != 1) {
                a_max = i+t;    // 4
                temp = a_max;
            }
        }
        if (i > t && i-t > 0 && Result[temp] == 1) {
            a_max = i-t;    // 2
        }
  
        Result[a_max] = 1;
    }
    // else if (bin == 0) {
    //     // 아래에 모두 부합하지 않을 때 a 최소 찾으려면 최대한 0 넣기
    //     // i > ti > t 이면 ai−t=1인 ai를 찾는다. (ai = 1+t)
    //     if (i <= n-t && 1-t == 0) {
    //         a = 1;
    //     }
    //     // i ≤ n−ti ≤ n−t 이면 ai+t=1 (ai = 1-t)
    //     if (i > t && 1+t == 1) {
    //         a = 0;
    //     }
    // }
}

int main(int argc, char** argv)
{
	int T, test_case;
    int n, t;
    int a, bin;
    string binary;

	freopen("input2.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		Result.clear();

        cin >> n >> t;
        Result.resize(n+1);
        fill(Result.begin(),Result.end(), 0);

        cin >> binary;
        
        for (int i = 1; i <= n; i++) {
            a = 0;
            bin = binary[i-1] - '0';

            decode(bin, n, t, i);
            cout << i << " ";
            for (int i = 1; i <= n; i++){
                cout << Result[i];
            }
            cout << endl;
        }

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
        
        for (int i = 1; i <= n; i++){
            cout << Result[i];
        }
		cout << endl;
	}

	return 0;
}