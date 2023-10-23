#include <iostream>
using namespace std;
#include <stack>
#include <string>

int main()
{
    int flag;
    char temp;
    string sentence;

    while(1) {
        getline(cin, sentence);
        if (sentence == ".") {
            break;
        }

        stack<char> array;
        flag = 0;
        for (char e : sentence) {
            if (e == '(' || e == '[') {
                array.push(e);
            } else if (e == ')') {
                if (array.size() > 0 && array.top() == '(') {
                    array.pop();
                } else {
                    flag = 1;
                }
            } else if (e == ']') {
                if (array.size() > 0 && array.top() == '[') {
                    array.pop();
                } else {
                    flag = 1;
                }
            }
        }
        if (array.size() == 0 && flag == 0) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}