#include <stdio.h>
#include <locale.h>
#include "ArrayTools.h"
#include "Sortings.h"
#include "Searches.h"
#include "Structs.h"
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "ExtraTools.h"
#include "config.h"

void main() {
	setlocale(LC_ALL, "Russian");

	#ifdef USE_TIME_FOR_RANDOM 
		srand(time(NULL));	
	#endif


	for (;;) {
/*------------------------------------Иннициализация массивов-------------------------------------------------------------------------*/
		printf_s("Введите размер массива: \n");
		int chosen_array_size;
		scanf_s("%d", &chosen_array_size);
		printf_s("Выберите способ заполнения массива: \n");
		printf_s("\t %" PRIu8 ". Ручное заполнение \n", ArrayFillingTypeNum.manual);
		printf_s("\t %" PRIu8 ". Заполнение случайными числами [%d, %d] \n", ArrayFillingTypeNum.random_ints, LOWER_RAND_VALUE, UPPER_RAND_VALUE);
		uint8_t chosen_filling_type;
		scanf_s("%"SCNu8, &chosen_filling_type);

		int* arr = (int*)malloc(chosen_array_size * sizeof(int));

		if (chosen_filling_type == ArrayFillingTypeNum.manual) {
			manualArrayFilling(arr, chosen_array_size);
		}
		else if (chosen_filling_type == ArrayFillingTypeNum.random_ints) {
			generateRandomArray(arr, chosen_array_size);
		}
		else {
			printf_s("Неверный номер способа заполнения! \n");
			continue;
		}
		#ifdef PRINT_ARRAYS
			printArray(arr, chosen_array_size);
		#endif
/*------------------------------------------------------------------------------------------------------------------------------------*/


		printf_s("Выберите номер типа алгоритма: \n");
		printf_s("\t %" PRIu8 ". Сортировка массива \n", AlgorithmTypeNum.sorting);
		printf_s("\t %" PRIu8 ". Поиск по массиву \n", AlgorithmTypeNum.search);
		uint8_t chosen_alg_type = ReturnCode.unchosen_num;
		scanf_s("%" SCNu8, &chosen_alg_type);


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
				bubble_sort(arr, chosen_array_size);
			}
			
			else if (chosen_sorting_type == SortTypeNum.selection_sort) {
				select_sort(arr, chosen_array_size);
			}

			else if (chosen_sorting_type == SortTypeNum.insertion_sort) {
				insertion_sort(arr, chosen_array_size);
			}

			else if (chosen_sorting_type == SortTypeNum.counting_sort) {
				counting_sort(arr, chosen_array_size);
			}

			else if (chosen_sorting_type == SortTypeNum.quick_sort) {
				quick_sort(arr, 0, chosen_array_size - 1);
			}

			else if (chosen_sorting_type == SortTypeNum.merge_sort) {

			}

			else {
				printf_s("Неверный номер метода сортировки!\n");
				continue;
			}
			#ifdef PRINT_ARRAYS
				printArray(arr, chosen_array_size);
			#else
				printf_s("[INFO] Массив отсортирован \n");
			#endif
		}
//-------------------------------------------------------------------------------------------------------------------

//---------------------Поиск-----------------------------------------------------------------------------------------
		else if (chosen_alg_type == AlgorithmTypeNum.search) {
			printf_s("Введите искомый элемент: \n");
			int chosen_key;
			scanf_s("%d", &chosen_key);
			printf_s("Выберите номер метода поиска: \n");
			printf_s("\t %" PRIu8 ". Линейный поиск \n", SearchTypeNum.linear_search);
			printf_s("\t %" PRIu8 ". Бинарный поиск (поиск происходит по отсортированному массиву)\n", SearchTypeNum.binary_search);

			uint8_t chosen_searching_type = ReturnCode.unchosen_num;
			scanf_s("%" SCNu8, &chosen_searching_type);

			int key_index = ReturnCode.key_not_found;

			if (chosen_searching_type == SearchTypeNum.linear_search) {
				key_index = linear_search(arr, chosen_array_size, chosen_key);
			}

			else if (chosen_searching_type == SearchTypeNum.binary_search) {
				int* copied_arr = (int*)malloc(chosen_array_size * sizeof(int));
				copyArray(arr, copied_arr, chosen_array_size);
				insertion_sort(copied_arr, chosen_array_size);
				#ifdef PRINT_ARRAYS
					printArray(copied_arr, chosen_array_size);
				#endif
				key_index = binary_search(copied_arr, chosen_array_size, chosen_key);
				free(copied_arr);
			}

			else {
				printf_s("Неверный номер метода поиска!\n");
				continue;
				free(arr);
			}


			if (key_index == ReturnCode.key_not_found)
				printf_s("Заданный элемент в массиве не найден!\n");
			else
				printf_s("Заданный элемент находится в массиве по индексу %d\n", key_index);
		}
//-------------------------------------------------------------------------------------------------------------------
		else {
			printf_s("Неверный номер типа алгоритма!\n");
			continue;
			free(arr);
		}
	}
}