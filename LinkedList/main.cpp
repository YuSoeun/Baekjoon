#include <iostream>
using namespace std;

#include "linked_list.hpp"

int main()
{
    LinkedList * my_list = NULL;
    char sentence[100];

    my_list = InitList();

    for (int i = 0; i < 5; i++) {
        cin >> sentence;
        Insert(my_list, sentence);
    }

    Traverse(my_list);
    cout << '\n';

    cout << "Search: ";
    cin >> sentence;
    Search(my_list, sentence);

    Erase(my_list);
    Traverse(my_list);

    Destroy(my_list);
    cout << '\n';
    Traverse(my_list);

    return 0;
}