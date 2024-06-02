#define _CRT_SECURE_NO_WARNINGS 1
#include "HEAP.h"

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	Heap hp;
	HeapInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}

	/*int i = 0;
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		a[i++] = HeapTop(&hp);
		HeapPop(&hp);
	}
	printf("\n");*/

	// 找出最小的前k个
	int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestory(&hp);
}



int main() {
	TestHeap1();
	return 0;
}

