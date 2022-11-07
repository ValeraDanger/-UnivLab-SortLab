#include <stdio.h>
#include <locale.h>
#include <inttypes.h>
#include "ArrayTools.h"
#include "Sortings.h"

//------ Структуры -------------------------------------------------------
struct AlgorithmTypesStruct {
	const uint8_t sorting;
	const uint8_t search;
};

struct SortTypesStruct {
	const uint8_t bubble_sort;
	const uint8_t selection_sort;
	const uint8_t insertion_sort;
	const uint8_t counting_sort;
	const uint8_t quick_sort;
	const uint8_t merge_sort;
};

struct SearchTypesStruct {
	const uint8_t linear_search;
	const uint8_t binary_search;
};

const struct SortTypesStruct SortType = { 0, 1, 2, 3, 4, 5 };
const struct SearchTypesStruct SearchType = { 0, 1 };
const struct AlgorithmTypesStruct AlgorithmType = { 0, 1 };
//------------------------------------------------------------------------

void main() {
	setlocale(LC_ALL, "Russian");
	for (;;) {
		printf_s("\nВыберите номер типа алгоритма: \n");
		printf_s("\t %" PRIu8 ". Сортировка массива \n", AlgorithmType.sorting);
		printf_s("\t %" PRIu8 ". Поиск по массиву \n", AlgorithmType.search);
		uint8_t chosen_alg_type = -1;
		scanf_s("%" SCNu8, &chosen_alg_type);
		int arr[] = { 2, 3, 1, 3, 2, 5, 2, 1 , 0 };

		if (chosen_alg_type == AlgorithmType.sorting) {
			printf_s("Выберите номер метода сортировки: \n");
			printf_s("\t %" PRIu8 ". Сортировка пузырьком \n", SortType.bubble_sort);
			printf_s("\t %" PRIu8 ". Сортировка выбором \n", SortType.selection_sort);
			printf_s("\t %" PRIu8 ". Сортировка вставками \n", SortType.insertion_sort);
			printf_s("\t %" PRIu8 ". Сортировка подсчетом \n", SortType.counting_sort);
			printf_s("\t %" PRIu8 ". Быстрая сортировка  \n", SortType.quick_sort);
			printf_s("\t %" PRIu8 ". Сортировка слиянием  \n", SortType.merge_sort);


			uint8_t chosen_sorting_type = -1;
			scanf_s("%" SCNu8, &chosen_sorting_type);


			if (chosen_sorting_type == SortType.bubble_sort) {
				bubble_sort(&arr, 9);
			}
			
			else if (chosen_sorting_type == SortType.selection_sort) {
				select_sort(&arr, 9);
			}

			else if (chosen_sorting_type == SortType.insertion_sort) {

			}

			else if (chosen_sorting_type == SortType.counting_sort) {

			}

			else if (chosen_sorting_type == SortType.quick_sort) {

			}

			else if (chosen_sorting_type == SortType.merge_sort) {

			}

			else {
				printf_s("Неверный номер метода сортировки!\n");
				continue;
			}

			printArray(&arr, 9);
		}

		else if (chosen_alg_type == AlgorithmType.search) {
			printf_s("Выберите номер метода поиска: \n");
		}

		else {
			printf_s("Неверный номер типа алгоритма!\n");
			continue;
		}
	}
}