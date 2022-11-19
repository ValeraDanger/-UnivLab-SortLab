#include <stdio.h>
#include "ArrayTools.h"
#include <stdlib.h>
#include "config.h"
#include "ExtraTools.h"
#include <malloc.h>


void swap(int *elem1, int *elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}


void printArray(int* arr, int size) {

	#ifndef PRINT_ARRAYS
	printf_s("[WARNING] Вывод массивов отключен в настройках проекта! Проверьте файл config.h \n");
	return;
	#endif // DEBUG

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


void manualArrayFilling(int* arr, int size) {
	printf_s("Введите элементы массива (каждый на новой строке) :\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}
}


void merge(int* arr, int left, int mid, int right) {
	int left_arr_i = 0, right_arr_i = 0, res_i = 0;
	int* res_arr = (int*)malloc((right-left) * sizeof(int));

	while (left + left_arr_i < mid && mid + right_arr_i < right) {
		if (arr[left + left_arr_i] < arr[mid + right_arr_i]) res_arr[res_i] = arr[left + left_arr_i++];	/*Ухудшается читаемость кода, не использовать*/
		else res_arr[res_i] = arr[mid + right_arr_i++];
		res_i++;
	}

	while (left + left_arr_i < mid) res_arr[res_i++] = arr[left + left_arr_i++];
	while (mid + right_arr_i < right) res_arr[res_i++] = arr[mid + right_arr_i++];

	copyArray(res_arr, arr + left, res_i);
}

