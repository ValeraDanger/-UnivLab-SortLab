#include "Searches.h"
#include "Sortings.h"
#include "ArrayTools.h"
#include <malloc.h>
#include "Structs.h"

extern struct AlgorithmTypeNum;
extern struct SortTypeNumTag SortTypeNum;
extern struct SearchTypeNumTag SearchTypeNum;
extern struct ReturnCodeTag ReturnCode;


int linear_search(int* arr, int size, int key){
	int i = 0;
	while (i < size && arr[i] != key)
		i++;
	if (arr[i] != key)
		i = ReturnCode.key_not_found;

	return i;
}

int binary_search(int* arr, int size, int key) {

	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else
			return mid;	
	}

	return ReturnCode.key_not_found;
}