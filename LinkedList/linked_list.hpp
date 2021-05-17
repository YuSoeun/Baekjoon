/*
	linked-list.h: declarations for linked-list-related functions
*/

typedef struct Node
{
    char * data;
    struct Node * next;     // next는 다음 노드(data와 next 둘다 있는)를 가리킴
} Node;

typedef struct
{
    Node * head;
    int size;
} LinkedList;

LinkedList * InitList();                        // 리스트 초기화
Node * InitNode();    // 노드 초기화
void Destroy(LinkedList * list);                // 리스트 삭제, 메모리 할당 해제

void Traverse(LinkedList * list);                // 연결리스트 모든 원소 출력
void Insert(LinkedList * list, char * str);      // 원소 추가
void Search(LinkedList * list, char * str);      // 원소 탐색
void Erase(LinkedList * list);                   // 원소 제거