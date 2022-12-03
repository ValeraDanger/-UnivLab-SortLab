#pragma once

void bubble_sort(int* arr, int arr_size, int* compare_count, int* swap_count);
void cocktail_sort(int* arr, int arr_size, int* compare_count, int* swap_count);
void select_sort(int* arr, int arr_size, int* compare_count, int* swap_count);
void insertion_sort(int* arr, int arr_size, int* compare_count);
void counting_sort(int* arr, int arr_size, int* compare_count);
void quick_sort(int* arr, int left, int right, int* compare_count, int* swap_count);
void merge_sort(int* arr, int left, int right, int* compare_count);