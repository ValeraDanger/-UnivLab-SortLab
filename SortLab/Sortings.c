#include "ArrayTools.h"
#include "Sortings.h"

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
	int* max = arr;
	for (int i = arr_size - 1; i > 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (arr[j] > *max) {
				max = &arr[j];
			}
		}
		swap(max, &arr[i]);
	}
}