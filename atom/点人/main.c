#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX_SIZE 200
void menu()
{
	printf("==================\n");
	printf("��ӭ�����������ϵͳ\n");
	printf("     1.�����Ա    \n");
	printf("     2.���ѡ��     \n");
	printf("     0. �˳�        \n");
}
typedef struct
{
	char name[100];
	int class;
}Student;
typedef struct Books
{
	Student students[MAX_SIZE];
	int size;
}Books;
void Init(Books* book)
{
	book->size = 0;
	for (int i = 0; i < book->size; i++)
	{
		book->students[i].class = 0;
		strcpy(book->students[i].name, "");

	}

}
void add(Books* book)
{
	Student* s = &book->students[book->size];
	printf("����������:\n");
	scanf("%s", s->name);
	printf("������༶:\n");
	scanf("%d", &s->class);
	book->size++;
	printf("��ӳɹ�\n");


}
void Xuan(Books* book)
{
	srand((unsigned int)time(NULL));
	int ret = rand() % 5;
	Student* s = &book->students[ret];
	printf("����鵽�����ǣ�\n");
	printf("%d  %s  %d\n", book->size,s->name, s->class);
}
int main()
{

	char input=0;
	Books book;
	Init(&book);
	do
	{
		menu();
		printf("��������Ĳ���:\n");
		scanf("%d", &input);
		if (input-'0' == 1)
		{
			add(&book);
		}
	   if (input-'0' == 2)
		{
			Xuan(&book);
		}
		 if (input-'0' == 0)
		{
			printf("�˳�\n");
			break;
		}
		if(input<'0'||input>'2')
		{
			printf("��������,��������:\n");
			continue;
		}
	} while (input-'0');
	return 0;
}
