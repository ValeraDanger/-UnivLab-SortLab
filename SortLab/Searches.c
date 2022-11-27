#include "Searches.h"
#include "Sortings.h"
#include "ArrayTools.h"
#include <malloc.h>
#include "Structs.h"


int linear_search(int* arr, int size, int key, int* compare_count){
	int i = 0;
	while (i < size && arr[i] != key) {
		(*compare_count)++;
		i++;
	}
	if (arr[i] != key) {
		(*compare_count)++;
		i = ReturnCode.key_not_found;
	}

	return i;
}

int binary_search(int* arr, int size, int key, int* compare_count) {

	int left = 0;
	int right = size - 1;

	while (left <= right) {
		(*compare_count)++;
		int mid = (left + right) / 2;
		if (arr[mid] < key) {
			(*compare_count)++;
			left = mid + 1;
		}

		else if (arr[mid] > key) {
			(*compare_count)++;
			right = mid - 1;
		}

		else {
			(*compare_count)++;
			return mid;
		}
	}

	return ReturnCode.key_not_found;
}
