#include <stdio.h>
#include <assert.h>
 void* Memcpy(void* destination,const void* source,int num)
{
  assert(destination!=NULL&&source!=NULL);
   void*ret=destination;
  for(int i=0;i<num;i++)
  {
    *(char*)destination=*(char*)source;
    destination=(char*)destination+1;
    source=(char*)source+1;
  }
  return ret;
}
void* Memmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	// 先判定缓冲区内存是否重叠
	char* cdest = (char*)dest;
	char* csrc = (char*)src;
	if (csrc < cdest && cdest < csrc + num) {
		// 需要从后往前拷贝
		char* pdest = cdest + num - 1;  // 最后一个位置的字节
		char* psrc = csrc + num - 1;
		for (size_t i = 0; i < num; i++) {
			*pdest = *psrc;
			pdest--;
			psrc--;
		}
	} else {
		Memcpy(dest, src, num);
	}
	return dest;
}
int main(int argc, char const *argv[]) {
  /* code */
  int  arr2[15]={1,2,3,4,5,6,7,8,9,114514};
  int arr3[5]={0};
  int *arr1=arr3+0;
  Memmove(arr1,arr2,15);
  for (size_t i = 0; i < 15; i++) {
    printf("%d ",arr1[i]);
  }
  return 0;
}
