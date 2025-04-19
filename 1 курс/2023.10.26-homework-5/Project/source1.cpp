#include"source.h"
#include<iostream>
#include<cstdlib>
#include<ctime>


int main(int argc, char* argv[])
{
    int* arr = nullptr;
    int size = 0;
    bool exit = false;
    while (!exit)
    {
        {
            system("cls");
            print_menu();
            print_array(arr, size);
        }
        int choice;
        {
            std::cin >> choice;
        }
        {
            switch (choice)
            {
            case 0:
            {
                exit = true;
                break;
            }
            case 1:
            {
                print_array(arr, size);
                break;
            }
            case 2:
            {
                int elem = 0;
                std::cout << "Input element to add : ";
                std::cin >> elem;
                add_element(arr, size, elem);
                break;
            }
            case 3:
            {
                int index = 0;
                std::cout << "Input index to extract : ";
                std::cin >> index;
                remove_element(arr, size, index);
                break;
            }
            case 4:
            {
                sort_array(arr, size);
                break;
            }
            case 5:
            {
                reverse_array(arr, size);
                break;
            }
            case 6:
            {
                swap_max_min(arr, size);
                break;
            }
            case 7:
            {
                remove_duplicates(arr, size);
                break;
            }
            case 8:
            {
                std::cout << "Enter number of random elements to add: ";
                int num_elements;
                std::cin >> num_elements;
                add_random_elements(arr, size, num_elements);
                break;
            }
            default:
            {
                std::cout << "Unknow command" << std::endl;
                break;
            }
            }
        }
    }

    return 0;
}
