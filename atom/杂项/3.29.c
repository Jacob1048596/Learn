#include<stdlib.h>
int* addToArrayForm(int *A,int Asize,int k,int* returnSize)
{
  int temp=k;
  int kNum=0;
  while (temp) {
    kNum++;
    temp/=10;
  }
  int newArraySize=Asize>kNum?Asize+1:kNum+1;
  int* newArray=(int*)malloc(sizeof(int)*newArraySize);
  int i=0;
  int idx=Asize-1;
  int step=0;
  while (idx>=0||k>0)
  {
    newArray[i]=step;
    if (idx>=0)

      newArray[i]+=A[idx];
      if (k>0)
        newArray[1]+=k%10;
      if (newArray[i]>9)
      {
        newArray[i]-=10;
        step=1;
      }else step=0;
      --idx;
      k/=10;
      ++i;
    }
  if (step==1)
    newArray[i++]=1;
    //reverse(newArray,0,i-1);
    *returnSize=i;
    return newArray;

}
