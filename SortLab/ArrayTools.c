#include <stdio.h>
#include "ArrayTools.h"

void swap(int *elem1, int *elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf_s("%d ", arr[i]);
	}
}

