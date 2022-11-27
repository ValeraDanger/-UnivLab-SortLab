#include "ArrayTools.h"
#include "Sortings.h"
#include <malloc.h>

void bubble_sort(int *arr, int arr_size, int* compare_count) {
	for (int i = arr_size-1; i > 0; i--) {
		(*compare_count)++;
		for (int j = 0; j < i; j++) {
			(*compare_count)++;
			if (arr[j] > arr[j + 1]) {
				(*compare_count)++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void cocktail_sort(int* arr, int arr_size, int* compare_count) {
	int last_i = arr_size - 1, left = 0, right = arr_size - 1;
	while (left < right) {
		(*compare_count)++;
		for (int i = left; i < right; i++) {
			(*compare_count)++;
			if (arr[i] > arr[i + 1]) {
				(*compare_count)++;
				swap(&arr[i], &arr[i + 1]);
				last_i = i;	/*индекс последнего обмена*/
			}
		}
		right = last_i;	/*сужаем область сортировки до последнего обмена, поскольку остальная часть массива уже отсортированна*/

		for (int i = right; i > left; i--) {
			(*compare_count)++;
			if (arr[i] < arr[i - 1]) {
				(*compare_count)++;
				swap(&arr[i], &arr[i - 1]);
				last_i = i;	/*индекс последнего обмена*/
			}
		}
		left = last_i;	/*сужаем область сортировки до последнего обмена, поскольку остальная часть массива уже отсортированна*/

	}
}

void select_sort(int* arr, int arr_size, int* compare_count) {
	for (int i = arr_size - 1; i > 0; i--) {
		(*compare_count)++;
		int* max = arr;
		for (int j = 0; j <= i; j++) {
			(*compare_count)++;
			if (arr[j] > *max) {
				(*compare_count)++;
				max = &arr[j];
			}
		}
		swap(max, &arr[i]);
	}
}

void insertion_sort(int* arr, int arr_size, int* compare_count) {
	for (int i = 1; i < arr_size; i++) {
		(*compare_count)++;
		int j = i - 1;
		int key = arr[i];
		for (; j >= 0 && arr[j] > key; j--)
			(*compare_count)++;
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

void counting_sort(int* arr, int arr_size, int* compare_count) {
	int max = findMax(arr, arr_size, compare_count);
	int min = findMin(arr, arr_size, compare_count);
	int len = max - min + 1;
	int* res = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {
		(*compare_count)++;
		res[i] = 0;
	}

	for (int i = 0; i < arr_size; i++) {
		(*compare_count)++;
		res[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < len; i++) {
		(*compare_count)++;
		for (int j = 0; j < res[i]; j++) {
			(*compare_count)++;
			arr[index++] = i + min;
		}
	}

	free(res);

}

void quick_sort(int* arr, int left, int right, int* compare_count) {
	int i = left;
	int j = right;
	int mid = arr[(i + j) / 2];
	while (i <= j) {
		(*compare_count)++;
		while (arr[i] < mid) {
			(*compare_count)++;
			i++;							/*Здесь унарный оператор внести нельзя*/
		}

		while (arr[j] > mid) {
			(*compare_count)++;
			j--;
		}
		if (i <= j) {
			(*compare_count)++;
			swap(&arr[i++], &arr[j--]);		/*Внесенные унарные операторы, ухудшает читаемость*/
		}
	}

	if (j > left) {
		(*compare_count)++;
		quick_sort(arr, left, j, compare_count);
	}

	if (i < right) {
		(*compare_count)++;
		quick_sort(arr, i, right, compare_count);
	}
		
}

void merge_sort(int* arr, int left, int right, int* compare_count) {
	if (left+1 >= right) {
		(*compare_count)++;
		return;
	}
	int mid = (left + right) / 2;
	merge_sort(arr, left, mid, compare_count);
	merge_sort(arr, mid, right, compare_count);
	merge(arr, left, mid, right, compare_count);
}