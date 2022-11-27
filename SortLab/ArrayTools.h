#pragma once

void swap(int* elem1, int* elem2);
void printArray(int* arr, int size);
int findMax(int* arr, int size, int* compare_count);
int findMin(int* arr, int size, int* compare_count);
void copyArray(int* arr, int* copying_arr, int size, int* compare_count);
void generateRandomArray(int* arr, int size);
void manualArrayFilling(int* arr, int size);
void merge(int* arr, int left, int mid, int right, int* compare_count);	/*Объединяет в arr отсортированные элементы из [arr[left], arr[mid) с отсортированными элементами из [arr[mid], arr[right])*/