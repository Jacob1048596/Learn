#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX_SIZE 1000
typedef struct PersonInfo
{
	char name[200];
	int sex;
	int age;
	char phone[200];
	char homedress[200];

}PersonInfo;

typedef struct AddressBook
{
	// PersonInfo persons[MAX_SIZE];
	//利用动态数组开辟内存空间
	PersonInfo* persons;
	int capacity;//容量大小
	 int size;
}AddressBook;

//初始化操作
void Init(AddressBook* addr)
{
	addr->size = 0;
	//修改二
	addr->capacity = 20;
	addr->persons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));
	for (int i = 0; i < addr->capacity; i++)
	{
		strcpy(addr->persons[i].name, " ");
		//strcpy(addr->persons[i].sex," ");
    addr->persons[i].sex=0;
		addr->persons[i].age = 0;
		strcpy(addr->persons[i].homedress, " ");
		strcpy(addr->persons[i].phone,  "");
	}
}

int Menu()
{
	printf("--==========================-\n");
	printf("||      通讯录管理系统      ||\n");
	printf("-===========================-\n");
	printf("||       1.添加联系人       ||\n");
	printf("||       2.删除联系人       ||\n");
	printf("||       3.修改联系人       ||\n");
	printf("||       4.查找联系人       ||\n");
	printf("||       5.打印所有联系人   ||\n");
	printf("||       6.删除所有联系人   ||\n");
	printf("||       7.以名字排序       ||  \n");
	printf("||       0.退出             || \n");
	printf("==============================\n");
	printf("请输入你要进行的操作序号: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void ReallocPerson(AddressBook* addr_book)
{
	//1.直接使用realloc
    // addr_book->capacity += 20;
	//addr_book->persons = (PersonInfo*)realloc(addr_book->persons, sizeof(PersonInfo) * addr_book->capacity);
	//2.通过malloc手动申请
	addr_book->capacity += 20;
	PersonInfo* newperson = (PersonInfo*)malloc(sizeof(PersonInfo) * addr_book->capacity);
	//将旧的内存上的数据拷贝过来
	memcpy(newperson, addr_book->persons, addr_book->size*sizeof(PersonInfo));
	//释放旧的内存
	free(addr_book->persons);
	//新内存上位
	addr_book->persons= newperson;
}
void AddPersonInfo(AddressBook* addr_book)
{

	printf("添加联系人:\n");
	//if (addr_book->size >= MAX_SIZE)
	//{
	//	printf("联系人已经存满! 添加失败!\n");
	//	return;
	//}
	//修改三,内存不够进行扩容
	PersonInfo* info = &addr_book->persons[addr_book->capacity];
	if (addr_book->size >= addr_book->capacity)
	{
		ReallocPerson(addr_book);
	}
	printf("请输入您要添加联系人的姓名:\n");
	scanf("%s", info->name);
	printf("请输入性别(男:1  女:2):\n");

	while(1)
	{
		int sexs = 0;

		scanf("%d", &sexs);
		if (sexs == 1 || sexs == 2)
		{
			addr_book->persons[addr_book->size].sex = sexs;
			break;
		}
		else
		{
			printf("输入有误，重新输入\n");
		}
	}
	printf("请输入年龄:\n");
	scanf("%d", &info->age);
	printf("请输入电话:\n");
	scanf("%s", info->phone);
	printf("请输入家庭住址:\n");
	scanf("%s", info->homedress);
	addr_book->size++;
	printf("添加成功!\n");


}
void DelPersonInfo(AddressBook* addr_book)
{
	PersonInfo* info = &addr_book->persons[addr_book->size];
	int input = 0;
	printf("请输入您要删除的联系人序号：\n");
	scanf("%d", &input);
	if (input < 0 || input >= addr_book->size)
	{
		printf("编号非法！！\n");
	}
	addr_book->persons[input] = addr_book->persons[addr_book->size - 1];
	addr_book->size--;
	printf("删除完成！！\n");
}
void ModifPersonInfo(AddressBook* addr_book)
{

	int id = 0;
	printf("请输入您要修改的联系人编号：\n");
	scanf("%d", &id);
	PersonInfo* info = &addr_book->persons[id];
	if (id < 0 || id >= addr_book->size)
	{
		printf("编号非法！！\n");
		return;
	}

		printf("请输入修改后的姓名：（* 表示不修改当前项）\n");
		char name[100] = { 0 };
		scanf("%s", name);
		if (!strcmp("*", name) == 0)
		{
			strcpy(info->name, name);
		}
		printf("请输入修改后的性别：（* 表示不修改当前项）\n");
		int sexs = 0;
		scanf("%d", &sexs);
		if(sexs!='*')
		{
			info->sex = sexs;
		}
		printf("请输入修改后的年龄：（* 表示不修改当前项）\n");
		int age=0;
		scanf("%d", &age);
		if (age != '*')
		{
			info->age =age;
		}
		printf("请输入修改后的电话：（* 表示不修改当前项）\n");
		char phone[200] = { 0 };
		scanf("%s", phone);
		if (!strcmp("*", phone) == 0)
		{
			strcpy(info->phone, phone);
		}
		printf("请输入修改后的家庭住址：（* 表示不修改当前项）\n");
		char homedress[200] = { 0 };
		scanf("%s", homedress);
		if (!strcmp("*", homedress) == 0)
		{
			strcpy(info->homedress, homedress);
		}


	printf("修改完成\n");
	return;

}
void FindPersonInfo(AddressBook* addr_book)
{
	char name[200] = { 0 };
	printf("请输入要查找的姓名：\n");
	scanf("%s", name);
	for (int i = 0; i <= addr_book->size - 1; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		if (strcmp(info->name,name)==0)
		{
			printf("[%d]  %s   %s  %d   %s    %s\n", i, info->name, (addr_book->persons[i].sex== 1) ? "男" : "女", info->age, info->phone, info->homedress);
		}

	}
	printf("查找完毕！\n");

}
void PrintPersonInfo(AddressBook* addr_book)
{
	if (addr_book->size == 0)
	{
		printf("当前没有联系人!\n");
	}
	for (int i = 0; i < addr_book->size; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		printf("[%d]  %s   %s  %d   %s    %s\n", i, info->name, addr_book->persons[i].sex == 1 ? "男":"女" , info->age, info->phone, info->homedress);
	}
}
void CleanPersonInfo(AddressBook* addr_book)
{
	char input[200] = { 0 };
	printf("您将要格式化，是否确定（Y/N）？\n");
	scanf("%s", input);
	if ((strcmp(input,"Y")==0))
	{
		printf("删除成功！\n");
		addr_book->size = 0;

		return;
	}
	else
	{
		printf("取消成功！\n");
	}

}
void SortPersonInfo(AddressBook* addr_book)
{
	for (int i = addr_book->size-1; i >=0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (strcmp(addr_book->persons[j-1].name, addr_book->persons[j].name) > 0)
			{
		       PersonInfo t = addr_book->persons[j-1];
				addr_book->persons[j-1] = addr_book->persons[j];
				addr_book->persons[j] = t;
			}
			else
				continue;
		}
	}
	printf("排序成功！\n");
	return;
}
int main()
{
	AddressBook address_book;
	Init(&address_book);
	//转移表
	typedef void(*Func)(AddressBook*);
	Func func_table[] = {
		NULL,
		AddPersonInfo,
		DelPersonInfo,
		ModifPersonInfo,
		FindPersonInfo,
		PrintPersonInfo,
		CleanPersonInfo,
		SortPersonInfo,
	};
	while (1)
	{
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(func_table)/sizeof(func_table[0]))
		{
			printf(" 输入有误!\n");
			continue;
		}
		if (choice == 0)
		{
			printf(" GoodBye!\n");
			break;
		}
		func_table[choice](&address_book);

	}
	system("pause");
	return 0;
}
