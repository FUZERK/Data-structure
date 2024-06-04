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

void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int);i++) {
		printf("%d", a[i]);
	}
}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}


void PrintTopK(int k) {
	

	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}

	for (int i = (k-1-1)/2; i >= 0; i--) {
		AdjustDown(kminheap, k, i);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("最大前%d个数：", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");

}

int main() {
	
	//CreateNDate();
	PrintTopK(10);
	return 0;
}

