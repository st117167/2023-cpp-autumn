#include<iostream>
#include<cstdlib>
#include<ctime>

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void add_element(int*& arr, int& size, int elem)
{
    int* new_arr = new int[size + 1] { 0 };
    if (arr != nullptr)
    {
        for (int i = 0; i < size; ++i)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
    }
    arr = new_arr;
    ++size;
}

void remove_element(int*& arr, int& size, int index)
{
    if (index >= 0 && index < size)
    {
        int* new_arr = new int[size - 1];
        for (int i = 0; i < index; ++i)
        {
            new_arr[i] = arr[i];
        }
        for (int i = index + 1; i < size; ++i)
        {
            new_arr[i - 1] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        --size;
    }
}

void sort_array(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void reverse_array(int* arr, int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void swap_max_min(int* arr, int size)
{
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > arr[max_index])
        {
            max_index = i;
        }
        if (arr[i] <= arr[min_index])
        {
            min_index = i;
        }
    }
    int temp = arr[max_index];
    arr[max_index] = arr[min_index];
    arr[min_index] = temp;
}

void remove_duplicates(int*& arr, int& size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; )
        {
            if (arr[j] == arr[i])
            {
                remove_element(arr, size, j);
            }
            else
            {
                ++j;
            }
        }
    }
}

void add_random_elements(int*& arr, int& size, int num_elements)
{
    srand(time(0));
    for (int i = 0; i < num_elements; ++i)
    {
        add_element(arr, size, rand() % 100);
    }
}

void print_menu()
{
    std::cout << "0 - Exit" << std::endl;
    std::cout << "1 - Print array" << std::endl;
    std::cout << "2 - Add element" << std::endl;
    std::cout << "3 - Remove element" << std::endl;
    std::cout << "4 - Sort array" << std::endl;
    std::cout << "5 - Reverse array" << std::endl;
    std::cout << "6 - Swap max min" << std::endl;
    std::cout << "7 - Remove duplicates" << std::endl;
    std::cout << "8 - Add random elements" << std::endl;
}
