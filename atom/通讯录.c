#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_SIZE 1000
FILE *fp;
typedef struct
{
  char name[10];
  char number[50];
  char sexy[10];
  char address[100];
  int  age;
}PersonInfor;
typedef struct address{
  PersonInfor people[MAX_SIZE];
  int size;
}Addressbook;
void file_write(Addressbook* book)     //�ļ�д��
{
    FILE * fp;
    fp=fopen("book","wb");
            if(fp==NULL)
                return;
            fwrite(book,sizeof(*book),1,fp);
            fclose(fp);
}
void file_read(Addressbook* book)      //�ļ���ȡ
{
    FILE * fp;
    fp = fopen("book", "rb");
    fread(book, sizeof (*book), 1, fp);
    fclose(fp);
}
void PersonAdd(Addressbook* book)
{
  assert(book);
  PersonInfor* infor=&book->people[book->size];
  printf("������ϵ��\n" );
  fp = fopen("book","wb");
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
  fwrite(book,sizeof(*book),1,fp);
  printf("������ϵ�˳ɹ�\n" );
  fclose(fp);
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
  fp = fopen("book","wb");
  fread(book,sizeof(*book),1,fp);
  char input[200] = { 0 };
  printf("���������ϵ����Ϣ���Ƿ����(Y/N)\n");
  	scanf("%s", input);
    if ((strcmp(input,"Y")==0))
	{
    BookInit(book);
    book->size = 0;
		printf("ɾ���ɹ���\n");
    fwrite(book,sizeof(*book),1,fp);
    printf("�޸���ɣ���\n");
    fclose(fp);
		return;
	}
	else
	{
    fwrite(book,sizeof(*book),1,fp);
		printf("ȡ���ɹ���\n");
    fclose(fp);
	}
}
void PersonPrint(Addressbook* book)
{
  assert(book);
  fp = fopen("book","rb");
  fread(book,sizeof(*book),1,fp);
  if (book->size==0) {
    printf("��ϵ��Ϊ��\n");
    return;
  }
  printf("��ӡ��ϵ��\n");
  //PersonInfor* infor=&book->people[book->size];
  int i=0;
    for(i=0;i<book->size;i++)
    {
      PersonInfor* people=&book->people[i];
      printf("[%d]:����:[%s] �Ա�:[%s] ����:[%d] ��ַ:[%s] ��ϵ��ʽ:[%s]\n",i,people->name,people->sexy,people->age,people->address,people->number);
    }
    printf("����ӡ[%d]����ϵ��\n",i);

  fclose(fp);
}
void PersonChange(Addressbook* book)
{
  assert(book);
  fp = fopen("book","wb");
    fread(book,sizeof(*book),1,fp);
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
    fwrite(book,sizeof(*book),1,fp);
  	printf("�޸���ɣ���\n");
    fclose(fp);
}
void PersonDelete(Addressbook* book)
{
  fp = fopen("book","wb");
    fread(book,sizeof(*book),1,fp);
  PersonInfor* infor=&book->people[book->size];
	int input = 0;
	printf("��������Ҫɾ������ϵ����ţ�\n");
	scanf("%d", &input);
	if (input < 0 || input >= book->size)
	{
		printf("��ŷǷ�����\n");
	}
	book->people[input] = book->people[book->size - 1];
	book->size--;
  fwrite(book,sizeof(*book),1,fp);
	printf("ɾ����ɣ���\n");
  fclose(fp);
}
void PersonFind(Addressbook* book)
{
  fp = fopen("book","rb");
  fread(book,sizeof(*book),1,fp);
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
  fclose(fp);
}
void sort_by_name(Addressbook* book)
{
    PersonInfor* infor=&book->people[book->size];
    for (int i = book->size-1; i >=0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (strcmp(book->people[j-1].name, book->people[j].name) > 0)
			{
		    PersonInfor t = book->people[j-1];
				book->people[j-1] = book->people[j];
				book->people[j] = t;
			}
			else
				continue;
		}
	}
	printf("����ɹ���\n");
	return;
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
  //file_read(&BookA);
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

  //file_write(&BookA);


  return 0;
}
