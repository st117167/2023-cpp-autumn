#pragma once
#include<iostream>

void print_menu();
void print_array(int* arr, int size);
void add_element(int*& arr, int& size, int elem);
void remove_element(int*& arr, int& size, int index);
void sort_array(int* arr, int size);
void reverse_array(int* arr, int size);
void swap_max_min(int* arr, int size);
void remove_duplicates(int*& arr, int& size);
void add_random_elements(int*& arr, int& size, int num_elements);
