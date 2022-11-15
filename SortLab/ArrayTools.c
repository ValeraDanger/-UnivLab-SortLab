#include <stdio.h>
#include "ArrayTools.h"
#include <stdlib.h>
#include "config.h"
#include "ExtraTools.h"


void swap(int *elem1, int *elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}

int findMax(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int findMin(int* arr, int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void copyArray(int* arr, int* copying_arr, int size) {
	for (int i = 0; i < size; i++) {
		copying_arr[i] = arr[i];
	}
}

void generateRandomArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = getRandInt(LOWER_RAND_VALUE, UPPER_RAND_VALUE);
	}
}

