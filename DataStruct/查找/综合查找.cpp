#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define MAXL 100
#define MAXI 100
#define NULLKEY -1
#define DELKEY   -2
typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;
	int link;
}IdxType;
typedef IdxType IDX[MAXI];
typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];


typedef struct node
{
	KeyType key;
	InfoType data;
	struct node *lchild,*rchild;
}BSTNode;
typedef struct
{	KeyType key;
	InfoType data;
	int count;
}HashTable[MAXL];
int SeqSearch(SeqList R,int n,KeyType k)      //顺序查找
{	int i=0;
	while(i<n && R[i].key!=k)
	{		i++;
	}
		return i+1;
}
int BinSearch(SeqList R,int n,KeyType k)       //折半查找
{
	int low=0,high=n-1,mid,count=0;
	while(low<=high)
	{
		count++;
		mid=(low+high)/2;
		if(R[mid].key==k)

          return count+1;
		if(R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
int IdxSearch(IDX I,int b,SeqList R,int n,KeyType k)  //索引查找
{
	int low=0,high=b-1,mid,i;
	int count=0;
	int s=n/b;
	while(low<=high)
	{
		count++;
		mid=(low+high)/2;
		if(I[mid].key>=k)
			high=mid-1;
		else
			low=mid+1;
	}
	i=I[high+1].link;
	while(i<=I[high+1].link+s-1&&R[i].key!=k)
	{
		count++;
		i++;
	}
	if(i<=I[high+1].link+s-1)
		return count+1;
	else
		return 0;
}


int SearchHT(HashTable ha,int p,KeyType k)   //散列查找
{
	int i=0,adr=0;
	int m=50;
	adr =k%p;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		i++;
		adr =(adr+1)%m;
	}
	if(ha[adr].key==k)
		return i+1;
	else
		return -1;
}
void InsertHT(HashTable ha,int n,KeyType k,int p)   //哈希表的插入
{
	int i,adr;
	adr=k%p;
	if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY)
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else
	{
		i=1;
		do
		{
			adr=(adr+1)%p;
			i++;
		}while(ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);
		ha[adr].key=k;
		ha[adr].count=i;
	}
	n++;
}
void CreateHT(HashTable ha,KeyType x[],int n,int m,int p)    //哈希表的创建
{
	int i,n1=0;
	for(i=0;i<m;i++)
	{
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	for(i=0;i<n;i++)
		InsertHT(ha,n1,x[i],p);
}

int InsertBST(BSTNode * p,KeyType k)    //二叉排序树的插入
{
	if(p==NULL)
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;
		p->lchild=p->rchild=NULL;
		return 1;
	}
	else if(k==p->key)
		return 0;
	else if(k<p->key)
		return InsertBST(p->lchild,k);
	else
		return InsertBST(p->rchild,k);
}
BSTNode *CreateBST(KeyType a[],int n)     //二叉排序树的创建
{
	BSTNode *bt=NULL;
	int i=0;
	while (i<n)
	{
		InsertBST(bt,a[i]);
		i++;
	}
	return bt;
}

int SearchBST(BSTNode *bt,KeyType k)     //二叉排序树查找
{
	if(bt==NULL||bt->key==k)
		return 1;
	if(k < bt->key)
	{
        return SearchBST(bt->lchild ,k) + 1;
	}

	else
	{
		return SearchBST(bt->rchild ,k) + 1;
	}

}

int  main()
{
	SeqList R;int i;int e;int a;int b;
	HashTable ha;
	int T[50];
	IDX I;
	double j,k,m,n,sum=0;
	srand((int)time(0));
	for(i=0;i<50;i++)
	{

		R[i].key=1+(int)(50.0*rand()/(RAND_MAX+1.0));
		printf("%d\t",R[i].key);
	}
	printf("***************************************************************************\n");

	for(i=0;i<50;i++)
		for(a=i+1;a<50;a++)
		if(R[i].key>R[a].key)
		{
			e=R[i].key;
			R[i].key=R[a].key;
			R[a].key=e;
		}

	for(i=0;i<50;i++)
			T[i]=R[i].key;
	for(i=0;i<50;i++)
	{
		sum=sum+SeqSearch(R,50,R[i].key);
	}
	printf("顺序查找平均查找长度：%6.2f\n",sum/50.0);
	sum=0;
	for(i=0;i<50;i++)
	{

		sum=sum+BinSearch(R,50,R[i].key);
	}
	printf("折半查找平均查找长度：%6.2f\n",sum/50.0);
	sum=0;
	for(i=0;i<5;i++)
	{
		I[i].link=i*10;
		I[i].key=R[i*10+9].key;
	}
	for(i=0;i<50;i++)
	{
		sum=sum+IdxSearch(I,5,R,50,R[i].key);
	}
	printf("索引查找平均查找长度：%6.2f\n",sum/50.0);
	sum=0;
	CreateHT(ha,b,50,53,53);
	for(i=0;i<50;i++)
	{
		sum=sum+SearchHT(ha,53,ha[i].key);
	}
	printf("哈希表查找平均查找长度：%6.2f\n",sum/50.0);
	sum=0;
	for(i=0;i<50;i++)
	{

		sum=sum+SearchBST(CreateBST(b,50),b);
	}
		printf("二叉树查找平均查找长度：%6.2f\n",sum/50.0);
return 0;
}
