#include <iostream>
using namespace std;

int Answer;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		Answer = 0;

		int N, A, B;
		double x0, y0; // 절편
		double x, y;
		int max_box = 0;
		
		cin >> N >> A >> B;
		x0 = N / (double)B; 
		y0 = N / (double)A;

		for (int i = 0; i <= y0; i++) {
		    x = i;
		    y = (N - A*x) / (double)B;
		    
		    if (y - (int)y == 0 && A*x + B*y == N) {
		        if (max_box < x + y) {
		            max_box = x + y;
		        }
		    }
		}
		cout << "Case #" << test_case+1 << endl;
		cout << max_box << endl;
	}

	return 0;
}