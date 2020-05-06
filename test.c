#include <stdio.h>
#include <stdlib.h>

struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
};

int main() {
	//问题1
	int a[5] = { 1, 2, 3, 4, 5 };
	// ptr 的指向应该是 5 后面的一个元素.
	// &a 得到的是 int(*)[5]
	int* ptr = (int*)(&a + 1);
	// 2 5
	printf("%d,%d", *(a + 1), *(ptr - 1));  // ptr 已经在上面被强转成 int* 了

	//问题2
	struct Test* p = (struct Test*)0x100000;
	// 100020
	printf("%p\n", p + 0x1);
	// 下面的强制类型转换, 导致 p 就变成了一个 unsigned long, 再去 + 1 , 就只是单纯的整数 + 1
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);

	//问题3
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);

	//问题4
	//长度为 3 个元素的一维数组, 每个元素长度为 2  => 1
	//长度为 2 个元素的一维数组, 每个元素长度为 3  => 2
	int a[3][2] = { {0, 1}, {2, 3}, {4, 5} }
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	// a[0] 取到了一个长度为 2 个元素的一维数组
	// p 是当前这个数组的首元素地址
	p = a[0];
	// 0???
	printf("%d", a[0][0]);

	//问题5
	int a[5][5];	// 二维数组
	int(*p)[4];		// 数组指针
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	//问题6
	int aa[2][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10 }
	};
	// &aa 应该是一个数组指针 int(*)[2][5], 再 + 1 应该要跳过整个数组
	int *ptr1 = (int *)(&aa + 1);
	// aa 是二维数组名 再 + 1, 隐式转成 int(*)[5]
	int *ptr2 = (int *)(*(aa + 1));
	//int *ptr2 = (int *)(aa[1]);
	// 10   5
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));

	//问题 7
	//指针数组
	char *a[] = { "work","at","alibaba" };
	char**pa = a;
	pa++;
	printf("%s\n", *pa);

	问题 8
	char *c[] = { "ENTER","NEW","POINT","FIRST" };
	char**cp[] = { c + 3,c + 2,c + 1,c };
	char***cpp = cp;

	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);

	// cpp[-2] => *(cpp-2) 这个操作没有修改 cpp 的内容. 而上面的 ++ 操作修改 cpp
	printf("%s\n", *cpp[-2] + 3);
	//printf("%s\n", cpp[-1][-1] + 1);

	system("pause");
	return 0;
}
