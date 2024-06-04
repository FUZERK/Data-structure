#define _CRT_SECURE_NO_WARNINGS 1
#include "HEAP.h"

void Swap(HPDataType* A, HPDataType* B)
{
	HPDataType tmp = *A;
	*A = *B;
	*B = tmp;
}

void AdjustUp(HPDataType* arr, int child) {
	
	int parrent = (child - 1) / 2;
	while (child > 0) {
		//小堆的情况下
		if (arr[child] < arr[parrent]) {
			Swap(&arr[child], &arr[parrent]);
			child = parrent;
			parrent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(HPDataType* arr, int n, int parent) {
	//小堆的情况
	int child = parent * 2 + 1;
	while (child < n) {
		if (arr[child] > arr[child + 1] && child + 1 < n) {
			child++;
		}
		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}

	}
	
}

void HeapInit(Heap* php) {
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;

}

void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;

}

void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->_capacity == hp->_size) {
		int Newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, Newcapacity * sizeof(HPDataType));
		if (tmp == NULL) {
			perror("realloc fail");
			exit(1);
		}
		hp->_a = tmp;
		hp->_capacity = Newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size-1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp) {
	assert(hp);
	if (hp->_size != 0)return 0;
	else return -1;
}

void HeapSort(int* arr, int n) {
	//降序排列 小堆
	//向上调整法 
	//for (int i = 1; i < n; i++) {
	//	AdjustUp(arr, i);
	//}
	//向下调整法建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	while (end>0) {
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}

}