#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int Strcmp(const char* str1, const char* str2) {
	// ������������˵, ��̫���÷���ֵ����ʾ�������
	assert(str1 != NULL && str2 != NULL);
	// ���αȽ������ַ�����Ӧ�ַ��Ƿ����
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			// ��ǰ�ַ��ѷָ���
			// ������ȥ�Ƚ���һ���ַ�
			str1++;
			str2++;
		}
	}
	// �����ĸ��ַ����ȵ��� \0 �ĸ��ַ����͸�С
	if (*str1 < *str2) {
		return -1;
	} else if (*str1 > *str2) {
		return 1;
	} else {
		return 0;
	}
}

const char* Strstr(const char* str1, const char* str2) {
	// ��򵥴ֱ��ķ�ʽ, ���/����ö��
	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0') {
		// ��ʱ˵�� str2 ��һ�����ַ���
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
		// �������ѭ������, �������������:
		// 1. red ���� \0
		// 2. sub ���� \0
		// 3. *red �� *sub �����
		if (*sub == '\0') {
			// �ҵ�ƥ����Ӵ�
			return black;
		}
		// ��� if �����治�ܽ���!!!
		// �˴���������ζ�� *sub != '\0' && *red == '\0'
		if (*red == '\0') {
			// ��ʱ str1 �����ܰ��� str2 ��
			return NULL;
		}
		// ���������´�ѭ����ƥ�����
		black++;
	}
	// û���ҵ�ƥ����Ӵ�
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
	// ���ж��������ڴ��Ƿ��ص�
	char* cdest = (char*)dest;
	char* csrc = (char*)src;
	if (csrc < cdest && cdest < csrc + num) {
		// ��Ҫ�Ӻ���ǰ����
		char* pdest = cdest + num - 1;  // ���һ��λ�õ��ֽ�
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
	//// str1 > str2   => ���� 0 ������
	//// str1 < str2   => С�� 0 ������
	//// str1 == str2  => 0

	//// strcmp ������������
	//// һ���ַ����ǳ���(����G)
	//// ������Ǹ�����(�Ĵ���)
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
	//// �˴�ʹ�� " " ��Ϊ�ָ��
	//// ������ַ�����û�ҵ��ָ��, �ͷ��� NULL
	//char* pch = strtok(str, " ");
	//while (pch != NULL) {
	//	printf("%s\n", pch);
	//	// ��һ�������� NULL ��ʾ�����ϴ��зֵ�λ��, �����з�
	//	pch = strtok(NULL, " ");
	//}

	//char str1[] = "hehe";
	//char str2[] = "hahahaha";
	//// Ҫ���������ĸ���
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