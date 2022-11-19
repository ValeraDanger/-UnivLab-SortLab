#include "ArrayTools.h"
#include "Sortings.h"
#include <malloc.h>

void bubble_sort(int *arr, int arr_size) {
	for (int i = arr_size-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void select_sort(int* arr, int arr_size) {
	for (int i = arr_size - 1; i > 0; i--) {
		int* max = arr;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > *max) {
				max = &arr[j];
			}
		}
		swap(max, &arr[i]);
	}
}

void insertion_sort(int* arr, int arr_size) {
	for (int i = 1; i < arr_size; i++) {
		int j = i - 1;
		int key = arr[i];
		for (; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

void counting_sort(int* arr, int arr_size) {
	int max = findMax(arr, arr_size);
	int min = findMin(arr, arr_size);
	int len = max - min + 1;
	int* res = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {
		res[i] = 0;
	}

	for (int i = 0; i < arr_size; i++) {
		res[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < res[i]; j++) {
			arr[index++] = i + min;
		}
	}

	free(res);

}

void quick_sort(int* arr, int left, int right) {
	int i = left;
	int j = right;
	int mid = arr[(i + j) / 2];
	while (i <= j) {
		while (arr[i] < mid)
			i++;							/*Здесь унарный оператор внести нельзя*/
		while (arr[j] > mid)
			j--;

		if (i <= j) 
			swap(&arr[i++], &arr[j--]);		/*Внесенные унарные операторы, ухудшает читаемость*/
	}

	if (j > left) 
		quick_sort(arr, left, j);
	if (i < right) 
		quick_sort(arr, i, right);
		
}

void merge_sort(int* arr, int left, int right) {
	if (left+1 >= right) {
		return;
	}
	int mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid, right);
	merge(arr, left, mid, right);
}