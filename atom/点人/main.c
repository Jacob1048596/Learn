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
	printf("欢迎来到随机点名系统\n");
	printf("     1.添加人员    \n");
	printf("     2.随机选人     \n");
	printf("     0. 退出        \n");
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
	printf("请输入姓名:\n");
	scanf("%s", s->name);
	printf("请输入班级:\n");
	scanf("%d", &s->class);
	book->size++;
	printf("添加成功\n");


}
void Xuan(Books* book)
{
	srand((unsigned int)time(NULL));
	int ret = rand() % 5;
	Student* s = &book->students[ret];
	printf("随机抽到的人是：\n");
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
		printf("请输入你的操作:\n");
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
			printf("退出\n");
			break;
		}
		if(input<'0'||input>'2')
		{
			printf("输入有误,重新输入:\n");
			continue;
		}
	} while (input-'0');
	return 0;
}
