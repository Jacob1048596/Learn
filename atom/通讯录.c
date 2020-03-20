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
  printf("������ϵ��\n" );

  if (book->size>=MAX_SIZE) {
    printf("ͨѶ¼����������ʧ��\n");
    return;
  }
  printf("������������ϵ������: " );
  scanf("%s",infor->name);
  printf("������������ϵ�˵绰: " );
  scanf("%s",infor->number);
  printf("������������ϵ���Ա�: " );
  scanf("%s",infor->sexy);
  printf("������������ϵ�˵�ַ: " );
  scanf("%s",infor->address);
  printf("������������ϵ������: " );
  scanf("%d",&infor->age);
  book->size++;
  printf("������ϵ�˳ɹ�\n" );
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
    printf("��ϵ��Ϊ��\n");
    return;
  }
  printf("��ӡ��ϵ��\n");
  PersonInfor* infor=&book->people[book->size];
  int i=0;
  PersonInfor* people=&book->people[i];
  for(i=0;i<book->size;i++)
  {
    printf("[%d]:����:[%s] �Ա�:[%s] ����:[%d] ��ַ:[%s] ��ϵ��ʽ:[%s]\n",i,people->name,people->sexy,people->age,people->address,people->number);
  }
printf("����ӡ[%d]����ϵ��\n",i);
}
void PersonChange(Addressbook* book)
{
  assert(book);
    printf("�޸���ϵ����Ϣ\n");
    printf("������Ҫ�޸ĵ���ϵ�˱��\n");
    int id;
    scanf("%d",&id);
    PersonInfor* infor=&book->people[id];
    printf("������Ҫ�޸ĵ���ϵ������\n");
    char name[10];
    scanf("%s",&name);
    strcpy(infor->name,name);
    printf("������Ҫ�޸ĵ���ϵ������\n");
    int age;
    scanf("%d",&age);
    infor->age=age;
    printf("������Ҫ�޸ĵ���ϵ�˵�ַ\n");
    char address[20];
    scanf("%s",&address);
    strcpy(infor->address,address);
    printf("������Ҫ�޸ĵ���ϵ����ϵ��ʽ\n");
    char number[50];
    scanf("%s",&number);
    strcpy(infor->number,number);
    printf("������Ҫ�޸ĵ���ϵ���Ա�\n");
    char sexy[10];
    scanf("%s",&sexy);
    strcpy(infor->sexy,sexy);
    printf("�޸ĺ����ϢΪ\n" );
    printf("[%d]:����:[%s] �Ա�:[%s] ����:[%d] ��ַ:[%s] ��ϵ��ʽ:[%s]\n",
    id,infor->name,infor->sexy,infor->age,infor->address,infor->number);
}
void PersonDelete(Addressbook* book)
{
  printf("��ӡ��ϵ��\n");
}
void PersonFind(Addressbook* book)
{
  printf("������ϵ����Ϣ\n");
  printf("1.����id��ѯ\n2.����������ѯ\n");
  int i;
  scanf("%d",&i);
  if(i==1)
  {
    printf("������Ҫ�Ĳ�����ϵ�˱��\n");
    int id;
    scanf("%d",&id);
    PersonInfor* infor=&book->people[id];
    printf("[%d]:����:[%s] �Ա�:[%s] ����:[%d] ��ַ:[%s] ��ϵ��ʽ:[%s]\n",
    id,infor->name,infor->sexy,infor->age,infor->address,infor->number);
  }else
  {
    printf("������Ҫ�Ĳ�����ϵ������\n");
    char name[10];
    scanf("%s ",&name);
    for(int i=0;i<book->size;i++)
    {
      PersonInfor* infor=&book->people[i];
      if(strcmp(book->people[i].name,name)==1)
      {
        printf("[%d]:����:[%s] �Ա�:[%s] ����:[%d] ��ַ:[%s] ��ϵ��ʽ:[%s]\n",
        i,infor->name,infor->sexy,infor->age,infor->address,infor->number);
      }
    }
  }

}
void sort_by_name(Addressbook* book)
{
  printf("��ӡ��ϵ��\n");
}
int menu(void) {
  printf("*********************************\n");
  printf("***       ͨѶ¼�˵�          ***\n");
  printf("*********************************\n");
  printf("***  1.�����ϵ����Ϣ         ***\n");
  printf("*********************************\n");
  printf("***  2.ɾ��ָ����ϵ����Ϣ     ***\n");
  printf("*********************************\n");
  printf("***  3.����ָ����ϵ����Ϣ     ***\n");
  printf("*********************************\n");
  printf("***  4.�޸�ָ����ϵ����Ϣ     ***\n");
  printf("*********************************\n");
  printf("***  5.��ʾ������ϵ����Ϣ     ***\n");
  printf("*********************************\n");
  printf("***  6.���������ϵ��         ***\n");
  printf("*********************************\n");
  printf("***  7.����������������ϵ��   ***\n");
  printf("*********************************\n");
  printf("***  0.�˳��˵�               ***\n");
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
  printf("*�밴���ּ�ѡ����ģ��:\n");
  while (1)
  {
    int choice=menu();
    if (choice<0||choice>=(sizeof(Func_Table)/sizeof(Func_Table[0])))
    {
      printf("����������������������\n");
      continue;
    }
    if (choice==0) {
      printf("ллʹ�ã��ټ�\n");
        break;
    }
    // if (choice==0) {
    //   printf("ллʹ�ã��ټ�\n");
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
    // }else printf("����������������������");
    Func_Table[choice](&BookA);
    //system("cls");
  }



  return 0;
}
