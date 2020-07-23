#include<iostream>
#include<stdio.h>
using namespace std;
int FindSubString(char* pch)
{
    int count=0;
    char*p1=pch;
    while (*p1!='\0')
    {
        /* code */
        if(*p1==p1[1]-1)
        {
            p1++;
            count++;
        }else break;
    }
    int count2=count;
    while(*p1!='\0')
    {
        if(*p1==p1[1]+1)
        {
            p1++;
            count2--;
        }else break;
    }
    if(count2==0) return (count);
    return(0);
    
}
void ModifyString(char* pText)
{
    char* p1=pText;
    char* p2 =p1;
    while (*p1!='\0')
    {
        /* code */
        int count=FindSubString(p1);
        if(count>0)
        {
            *p2++ =*p1;
            sprintf(p2,"%i",count);
            while(*p2!='\0')
            {
                p2++;
            }
            p1+=count+count+1;
        }else *p2++ =*p1++;
    }
    
}
class a
{
    public:
    a(){cout<<"A";}
    ~a(){cout<<"deA";}
    virtual void f(){cout<<"A";}
};
class b
{
    public:
     b(){cout<<"B";}
    ~b(){cout<<"deB";}
    virtual void f(){cout<<"B";}
};
class c:public a,public b
{
    public:
    c(){cout<<"C";}
    ~c(){cout<<"deC";}
};
int main()
{
   a *a=new c();
  
   delete a;
   return 0;
iterator}

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int sum=0;
        int leftSum=0,rightSum=0;
        int leftMin=30,rightMin=30;
        for(int i=0;i<n;i++)
        {
            if(left[i]*right[i]==0)sum+=(left[i]+right[i]);
            else{
                leftSum+=left[i];
                rightSum+=right[i];
                leftMin = min(leftMin,left[i]);
                rightMin = min(rightMin,right[i]);
            }
        }
        return sum + min(leftSum-leftMin+1,rightSum-rightMin+1) + 1;
    }
};


#include<iostream>
 
using namespace std;
 
int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        while(n > 0)
        {
            if(n & 1) ++count;
            n >>= 1;
        }
 
        cout << count << endl;
    }
     
    return 0;
}