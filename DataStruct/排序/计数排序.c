#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printarr(int* arr,int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
void Countsort(int* arr,int n)
{
    int min=arr[0],max=arr[0];
    for(int i=1;i<n;++i)
    {
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
    }
    int range=max-min+1;
    int* CountArr=(int*)malloc(sizeof(int)*range);
    memset(CountArr,0,sizeof(int)*range);
    for(int i=0;i<n;++i)
    {
        CountArr[arr[i]-min]++;
    }
    int idx=0;
    for(int i=0;i<range;++i)
    {
        while(CountArr[i]--)
        {
            arr[idx++]=i+min;
        }
    }
    free(CountArr);

}
int main(int argc, char const *argv[])
{
    int arr[10]={5,4,9,8,6,3,2,7,1,0};
    Countsort(arr,10);
    printarr(arr,10);
    return 0;
}
