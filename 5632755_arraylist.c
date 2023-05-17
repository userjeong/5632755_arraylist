#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; //�迭 ����
	int size; //���� ����Ʈ�� ����� �׸���� ����
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

//�迭 ����Ʈ
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

//���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L) {
	L->size = 0; //L�� ����Ű�� ���� size���� 0
}

//����Ʈ�� ��� ������ 1�� ��ȯ
//�׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

//����Ʈ�� ���� �� ������ 1�� ��ȯ
//�׷��� ������ 0�� ��ȯ
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)//pos(��ġ)�� 0���� �۰ų� ���� ����Ʈ��
		//������� ��ġ���� ũ�ٸ�
		error("��ġ ����");
	return L->array[pos]; //L�� array�� pos��
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
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{

	//full�� �ƴϰų�, pos�� 0���� ���ų� ũ��, pos�� size���� �۰ų� ���� ���
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		//�迭 ����� �ε������� �ϳ��� �����ϴ� ���� �ݺ�
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];

		}
		L->array[pos] = item;
		L->size++;
	}
}

//�׸� ���� ����
element delete(ArrayListType* L, int pos)
{
	element item;

	//��ġ����
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos]; //�ӽú��� item�� pos�� ���� ����
	//���� �������� �������� ���� �̵��ϱ� (ex.pos�� 2�ϰ��)
	for (int i = pos; i < (L->size - 1); i++)
	{
		//i = 2�϶�, array[i](2)�� array[i+1](3)�� ���� ����
		L->array[i] = L->array[i + 1];
		L->size--;
		return item;
	}
}