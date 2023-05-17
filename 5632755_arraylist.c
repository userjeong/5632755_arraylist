#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; //배열 정의
	int size; //현재 리스트에 저장된 항목들의 개수
}ArrayListType;

void error(char* message);
void init(ArrayListType* L);
int is_empty(ArrayListType* L);
int is_full(ArrayListType* L);
element get_entry(ArrayListType* L, int pos);
void print_list(ArrayListType* L);
void insert_last(ArrayListType* L, element item);
void insert(ArrayListType* L, int pos, element item);
element delete(ArrayListType* L, int pos);

//배열 리스트
int main(void)
{

	int menu_num = 0;
	ArrayListType* arylist;
	int element, pos;
	init(&arylist);
	while (1)
	{
		printf("\nMenu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf("%d", &menu_num);

		if (menu_num == 1)
		{
			printf("Enter the number and position: ");
			scanf("%d %d", &element, &pos);
			if (is_full(&arylist))
			{
				printf("List is full.\n");
			}
			else {

				if ((arylist->size == 0) && (pos > 0))
				{
					printf("List size is zero. please enter again(number position): ");
				}

				else
				{
					insert(&arylist, pos, element);
				}

			}
		}
		else if (menu_num == 2)
		{
			if (is_empty(&arylist))
			{
				printf("List is empty.\n");
			}
			else
			{
				printf("Enter the position: ");
				scanf("%d", &pos);
				delete(&arylist, pos);
			}

		}
		else if (menu_num == 3)
		{
			print_list(&arylist);
		}
		else if (menu_num == 0)
		{
			break;
		}
		else
		{
			printf("Invalid Menu. Please select again..\n");
		}
	}
}

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//리스트 초기화 함수
void init(ArrayListType* L) {
	L->size = 0; //L이 가리키는 것의 size값을 0
}

//리스트가 비어 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

//리스트가 가득 차 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)//pos(위치)가 0보다 작거나 현재 리스트의
		//사이즈보다 위치값이 크다면
		error("위치 오류");
	return L->array[pos]; //L의 array의 pos값
}

void print_list(ArrayListType* L)
{
	for (int i = 0; i < L->size; i++)
	{
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{

	//full이 아니거나, pos가 0보다 같거나 크고, pos가 size보다 작거나 같을 경우
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		//배열 요소의 인덱스값을 하나씩 증가하는 것을 반복
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];

		}
		L->array[pos] = item;
		L->size++;
	}
}

//항목 삭제 연산
element delete(ArrayListType* L, int pos)
{
	element item;

	//위치오류
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos]; //임시변수 item에 pos의 값을 대입
	//값을 빼놨으니 왼쪽으로 값들 이동하기 (ex.pos가 2일경우)
	for (int i = pos; i < (L->size - 1); i++)
	{
		//i = 2일때, array[i](2)에 array[i+1](3)의 값을 대입
		L->array[i] = L->array[i + 1];
		L->size--;
		return item;
	}
}