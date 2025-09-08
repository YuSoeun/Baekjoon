typedef struct
{
    int * array;
    int len;

    int head;
    int tail;
} List;

void push(List * list, int num);  // 정수 X 스택에 넣기
void pop(List * list);            // 스택 가장 앞에 있는 정수 빼고 출력, 없으면 -1
void size(List * list);           // 정수 개수 출력
void empty(List * list);          // 스택이 비어있으면 1, 아니면 0을 출력
void front(List * list);          // 스택 가장 앞에 있는 정수 출력, 없으면 -1
void back(List * list);           // 스택 가장 뒤에 있는 정수 출력, 없으면 -1