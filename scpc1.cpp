/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		
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
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << max_box << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}