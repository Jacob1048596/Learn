#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int Strcmp(const char* str1, const char* str2) {
	// 针对这个函数来说, 不太好用返回值来表示出错情况
	assert(str1 != NULL && str2 != NULL);
	// 依次比较两个字符串对应字符是否相等
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			// 当前字符难分高下
			// 继续再去比较下一个字符
			str1++;
			str2++;
		}
	}
	// 看是哪个字符串先到达 \0 哪个字符串就更小
	if (*str1 < *str2) {
		return -1;
	} else if (*str1 > *str2) {
		return 1;
	} else {
		return 0;
	}
}

const char* Strstr(const char* str1, const char* str2) {
	// 最简单粗暴的方式, 穷举/暴力枚举
	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0') {
		// 此时说明 str2 是一个空字符串
		return NULL;
	}

	const char* black = str1;
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		while (*red != '\0' && *sub != '\0' && (*red == *sub)) {
			red++;
			sub++;
		}
		// 当上面的循环结束, 可能有三种情况:
		// 1. red 遇到 \0
		// 2. sub 遇到 \0
		// 3. *red 和 *sub 不相等
		if (*sub == '\0') {
			// 找到匹配的子串
			return black;
		}
		// 这个 if 和上面不能交换!!!
		// 此处的条件意味着 *sub != '\0' && *red == '\0'
		if (*red == '\0') {
			// 此时 str1 不可能包含 str2 了
			return NULL;
		}
		// 继续处理下次循环的匹配情况
		black++;
	}
	// 没有找到匹配的子串
	return NULL;
}

void* Memcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	void* ret = dest;
	for (size_t i = 0; i < num; i++) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
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

int main() {
	//char str1[] = "hehe";
	//char str2[] = "hehe";
	//// str1 > str2   => 大于 0 的整数
	//// str1 < str2   => 小于 0 的整数
	//// str1 == str2  => 0

	//// strcmp 被调用了两次
	//// 一旦字符串非常大(几个G)
	//// 这可能是个考点(改错题)
	//int ret = Strcmp(str1, str2);
	//if (ret < 0) {
	//	printf(" str1 < str2 \n");
	//} else if (ret > 0) {
	//	printf(" str1 > str2 \n");
	//} else {
	//	printf(" str1 == str2 \n");
	//}

	//char str1[] = "hello world world world";
	//char str2[] = "world";
	//char* ret = strstr(str1, str2);
	//printf("%p, %p\n", str1, ret);

	//char str[] = "This a simple string";
	//// 此处使用 " " 作为分割符
	//// 如果在字符串中没找到分割符, 就返回 NULL
	//char* pch = strtok(str, " ");
	//while (pch != NULL) {
	//	printf("%s\n", pch);
	//	// 第一个参数传 NULL 表示继续上次切分的位置, 往后切分
	//	pch = strtok(NULL, " ");
	//}

	//char str1[] = "hehe";
	//char str2[] = "hahahaha";
	//// 要拷贝的最大的个数
	//strncpy(str1, str2, sizeof(str2) - 1);
	//printf("%s\n", str1);

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	int* p = arr + 2;
	Memcpy(p, arr, 8);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr2[i]);
	}

	system("pause");
	return 0;
}