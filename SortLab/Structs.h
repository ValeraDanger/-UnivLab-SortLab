#pragma once

#include <inttypes.h>


struct AlgorithmTypeNumTag {
	const uint8_t sorting;
	const uint8_t search;
};

struct SortTypeNumTag {
	const uint8_t bubble_sort;
	const uint8_t selection_sort;
	const uint8_t insertion_sort;
	const uint8_t counting_sort;
	const uint8_t quick_sort;
	const uint8_t merge_sort;
};

struct SearchTypeNumTag {
	const uint8_t linear_search;
	const uint8_t binary_search;
};

struct ReturnCodeTag {
	const uint8_t key_not_found;
	const uint8_t unchosen_num;
};

struct ArrayFillingTypeNumTag {
	const uint8_t manual;
	const uint8_t random_ints;
};


extern struct AlgorithmTypeNumTag AlgorithmTypeNum;
extern struct SortTypeNumTag SortTypeNum;
extern struct SearchTypeNumTag SearchTypeNum;
extern struct ReturnCodeTag ReturnCode;
extern struct ArrayFillingTypeNumTag ArrayFillingTypeNum;
