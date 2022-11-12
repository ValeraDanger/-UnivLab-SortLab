#include <stdio.h>
#include <locale.h>
#include "ArrayTools.h"
#include "Sortings.h"
#include "Searches.h"
#include "Structs.h"
#include <malloc.h>


void main() {
	setlocale(LC_ALL, "Russian");
	for (;;) {
		printf_s("\nВыберите номер типа алгоритма: \n");
		printf_s("\t %" PRIu8 ". Сортировка массива \n", AlgorithmTypeNum.sorting);
		printf_s("\t %" PRIu8 ". Поиск по массиву \n", AlgorithmTypeNum.search);
		uint8_t chosen_alg_type = ReturnCode.unchosen_num;
		scanf_s("%" SCNu8, &chosen_alg_type);
		int arr[] = { 2, 3, 1, 3, 2, 5, 2, 1 , 0 };

//------------------------------Сортировки--------------------------------------------------------------------
		if (chosen_alg_type == AlgorithmTypeNum.sorting) {
			printf_s("Выберите номер метода сортировки: \n");
			printf_s("\t %" PRIu8 ". Сортировка пузырьком \n", SortTypeNum.bubble_sort);
			printf_s("\t %" PRIu8 ". Сортировка выбором \n", SortTypeNum.selection_sort);
			printf_s("\t %" PRIu8 ". Сортировка вставками \n", SortTypeNum.insertion_sort);
			printf_s("\t %" PRIu8 ". Сортировка подсчетом \n", SortTypeNum.counting_sort);
			printf_s("\t %" PRIu8 ". Быстрая сортировка  \n", SortTypeNum.quick_sort);
			printf_s("\t %" PRIu8 ". Сортировка слиянием  \n", SortTypeNum.merge_sort);


			uint8_t chosen_sorting_type = ReturnCode.unchosen_num;
			scanf_s("%" SCNu8, &chosen_sorting_type);


			if (chosen_sorting_type == SortTypeNum.bubble_sort) {
				bubble_sort(arr, 9);
			}
			
			else if (chosen_sorting_type == SortTypeNum.selection_sort) {
				select_sort(arr, 9);
			}

			else if (chosen_sorting_type == SortTypeNum.insertion_sort) {
				insertion_sort(arr, 9);
			}

			else if (chosen_sorting_type == SortTypeNum.counting_sort) {
				counting_sort(arr, 9);
			}

			else if (chosen_sorting_type == SortTypeNum.quick_sort) {
				quick_sort(arr, 0, 8);
			}

			else if (chosen_sorting_type == SortTypeNum.merge_sort) {

			}

			else {
				printf_s("Неверный номер метода сортировки!\n");
				continue;
			}

			printArray(arr, 9);
		}
//-------------------------------------------------------------------------------------------------------------------

//---------------------Поиск-----------------------------------------------------------------------------------------
		else if (chosen_alg_type == AlgorithmTypeNum.search) {

			printf_s("Выберите номер метода поиска: \n");
			printf_s("\t %" PRIu8 ". Линейный поиск \n", SearchTypeNum.linear_search);
			printf_s("\t %" PRIu8 ". Бинарный поиск \n", SearchTypeNum.binary_search);

			uint8_t chosen_searching_type = ReturnCode.unchosen_num;
			scanf_s("%" SCNu8, &chosen_searching_type);

			int key_index = ReturnCode.key_not_found;

			if (chosen_searching_type == SearchTypeNum.linear_search) {
				key_index = linear_search(arr, 9, 5);
			}

			else if (chosen_searching_type == SearchTypeNum.binary_search) {
				int* copied_arr = (int*)malloc(9 * sizeof(int));
				copyArray(arr, copied_arr, 9);
				insertion_sort(copied_arr, 9);
				key_index = binary_search(copied_arr, 9, 5);
			}

			else {
				printf_s("Неверный номер метода поиска!\n");
				continue;
			}


			if (key_index == ReturnCode.key_not_found)
				printf_s("Заданный элемент в массиве не найден!");
			else
				printf_s("Заданный элемент находится в массиве по индексу %d", key_index);
		}
//-------------------------------------------------------------------------------------------------------------------
		else {
			printf_s("Неверный номер типа алгоритма!\n");
			continue;
		}
	}
}