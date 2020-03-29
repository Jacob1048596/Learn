// #include <stdio.h>
// int main(int argc, char const *argv[]) {
//   int a;
//   scanf("%d",&a);
//   printf("%d\n",a);
//   return 0;
// }
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include <math.h>
double power(double n,int k)
{
  double result;
     if(k==0) return 1;
  else if(k>0)
   {
     result= (n*power(n,k-1));
     return result;
   }
     else if(k<0)
     {
       k=k*-1;
       result= (n*power(n,k-1));
       double ret =1/result;
       return ret;
     }
}
int main()
{
	// int arr[100] = { 0 };
	// int n = 0;
	// printf("请输入元素个数:\n");
	// scanf("%d", &n);
	// for (int k = 0; k < n; k++)
	// {
	// 	scanf("%d", &arr[k]);
	// }
  // int num[50]={0};
  // for(int i=0;i<100;i++)
  // {
  //   num[arr[i]]++;
  // }
  // for(int i=0;i<50;i++)
  // {
  //   if(num[i]!=0)
  //   printf("[%d] %d ",i,num[i]);
  // }
  // printf("\n");
  // for(int i=1;i<50;i++)
  // {
  //   if(num[i]==1) printf("%d ",i);
  // }
	// for (int i = n-1; i >=0; i--)
	// { int count = 0;
	// 	for (int j = 0; i < n; j++)
	// 	{
  //
	// 		if (arr[i] == arr[j])
	// 		{
	// 			count++;
	// 		}
	// 	}
	// 	if (count == 1)
	// 	{
	// 		printf("%d\n", arr[i]);
	// 	}
	// 	continue;
	// }
	int money,year;
	double rate;

	scanf("%d %d %lf",&money,&year,&rate);
	printf("%d,%d,%f\n",money,year,rate );
	double sum=money*power((1+rate),year);
	printf("%7.2f\n",sum);
	return 0;
	system("pause");
}
