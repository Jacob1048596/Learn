#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_SIZE 1000
typedef struct
{
  char name[10];
  char number[50];
  char sexy[10];
  char address[100];
  int  age;
}PersonInfor;
typedef struct{
  PersonInfor people[MAX_SIZE];
  int size;
}Addressbook;
void PersonAdd(Addressbook* book)
{
  assert(book);
  PersonInfor* infor=&book->people[book->size];
  printf("新增联系人\n" );

  if (book->size>=MAX_SIZE) {
    printf("通讯录已满，新增失败\n");
    return;
  }
  printf("请输入新增联系人姓名: " );
  scanf("%s",infor->name);
  printf("请输入新增联系人电话: " );
  scanf("%s",infor->number);
  printf("请输入新增联系人性别: " );
  scanf("%s",infor->sexy);
  printf("请输入新增联系人地址: " );
  scanf("%s",infor->address);
  printf("请输入新增联系人年龄: " );
  scanf("%d",&infor->age);
  book->size++;
  printf("新增联系人成功\n" );
  //_sleep(500);
}
void BookInit(Addressbook* book)
{
    book->size=0;
    for(int i=0;i<MAX_SIZE;i++)
    {
      strcpy(book->people[i].name," ");
      strcpy(book->people[i].number," ");
      strcpy(book->people[i].address," ");
      strcpy(book->people[i].sexy," ");
      book->people[i].age=0;
    }
}
void AddressBookClear(Addressbook* book)
{

}
void PersonPrint(Addressbook* book)
{
  assert(book);
  if (book->size==0) {
    printf("联系人为空\n");
    return;
  }
  printf("打印联系人\n");
  PersonInfor* infor=&book->people[book->size];
  int i=0;
  PersonInfor* people=&book->people[i];
  for(i=0;i<book->size;i++)
  {
    printf("[%d]:姓名:[%s] 性别:[%s] 年龄:[%d] 地址:[%s] 联系方式:[%s]\n",i,people->name,people->sexy,people->age,people->address,people->number);
  }
printf("共打印[%d]名联系人\n",i);
}
void PersonChange(Addressbook* book)
{
  assert(book);
    printf("修改联系人信息\n");
    printf("请输入要修改的联系人编号\n");
    int id;
    scanf("%d",&id);
    PersonInfor* infor=&book->people[id];
    printf("请输入要修改的联系人姓名\n");
    char name[10];
    scanf("%s",&name);
    strcpy(infor->name,name);
    printf("请输入要修改的联系人年龄\n");
    int age;
    scanf("%d",&age);
    infor->age=age;
    printf("请输入要修改的联系人地址\n");
    char address[20];
    scanf("%s",&address);
    strcpy(infor->address,address);
    printf("请输入要修改的联系人联系方式\n");
    char number[50];
    scanf("%s",&number);
    strcpy(infor->number,number);
    printf("请输入要修改的联系人性别\n");
    char sexy[10];
    scanf("%s",&sexy);
    strcpy(infor->sexy,sexy);
    printf("修改后的信息为\n" );
    printf("[%d]:姓名:[%s] 性别:[%s] 年龄:[%d] 地址:[%s] 联系方式:[%s]\n",
    id,infor->name,infor->sexy,infor->age,infor->address,infor->number);
}
void PersonDelete(Addressbook* book)
{
  printf("打印联系人\n");
}
void PersonFind(Addressbook* book)
{
  printf("查找联系人信息\n");
  printf("1.按照id查询\n2.按照姓名查询\n");
  int i;
  scanf("%d",&i);
  if(i==1)
  {
    printf("请输入要的查找联系人编号\n");
    int id;
    scanf("%d",&id);
    PersonInfor* infor=&book->people[id];
    printf("[%d]:姓名:[%s] 性别:[%s] 年龄:[%d] 地址:[%s] 联系方式:[%s]\n",
    id,infor->name,infor->sexy,infor->age,infor->address,infor->number);
  }else
  {
    printf("请输入要的查找联系人姓名\n");
    char name[10];
    scanf("%s ",&name);
    for(int i=0;i<book->size;i++)
    {
      PersonInfor* infor=&book->people[i];
      if(strcmp(book->people[i].name,name)==1)
      {
        printf("[%d]:姓名:[%s] 性别:[%s] 年龄:[%d] 地址:[%s] 联系方式:[%s]\n",
        i,infor->name,infor->sexy,infor->age,infor->address,infor->number);
      }
    }
  }

}
void sort_by_name(Addressbook* book)
{
  printf("打印联系人\n");
}
int menu(void) {
  printf("*********************************\n");
  printf("***       通讯录菜单          ***\n");
  printf("*********************************\n");
  printf("***  1.添加联系人信息         ***\n");
  printf("*********************************\n");
  printf("***  2.删除指定联系人信息     ***\n");
  printf("*********************************\n");
  printf("***  3.查找指定联系人信息     ***\n");
  printf("*********************************\n");
  printf("***  4.修改指定联系人信息     ***\n");
  printf("*********************************\n");
  printf("***  5.显示所有联系人信息     ***\n");
  printf("*********************************\n");
  printf("***  6.清空所有联系人         ***\n");
  printf("*********************************\n");
  printf("***  7.以名字排序所有联系人   ***\n");
  printf("*********************************\n");
  printf("***  0.退出菜单               ***\n");
  printf("*********************************\n");
  int choice=0;
  scanf("%d",&choice);
  return choice;
}
int main(int argc, char const *argv[])
{
  Addressbook BookA;
  BookInit(&BookA);
  typedef void(*Func)(Addressbook*);
  Func Func_Table[]={
    NULL,
    PersonAdd,
    PersonDelete,
    PersonFind,
    PersonChange,
    PersonPrint,
    AddressBookClear,
    sort_by_name,
  };
  printf("*请按数字键选择功能模块:\n");
  while (1)
  {
    int choice=menu();
    if (choice<0||choice>=(sizeof(Func_Table)/sizeof(Func_Table[0])))
    {
      printf("您的输入有误，请重新输入\n");
      continue;
    }
    if (choice==0) {
      printf("谢谢使用，再见\n");
        break;
    }
    // if (choice==0) {
    //   printf("谢谢使用，再见\n");
    //   break;
    // }else if (choice==1) {
    //   PersonAdd(&BookA);
    // }else if (choice==2) {
    //   PersonDelete(&BookA);
    // }else if (choice==3) {
    //   PersonFind(&BookA);
    // }else if (choice==4) {
    //   PersonChange(&BookA);
    // }else if (choice==5) {
    //   PersonPrint(&BookA);
    // }else if (choice==6) {
    //   AddressBookClear(&BookA);
    // }else if (choice==7) {
    //   sort_by_name(&BookA);
    // }else printf("您的输入有误，请重新输入");
    Func_Table[choice](&BookA);
    //system("cls");
  }



  return 0;
}
