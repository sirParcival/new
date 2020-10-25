// ExampleApp.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define length(arr) (sizeof(arr)/sizeof(arr[0])) 
#define NUMBER_OF_TOP_PLACES 3

void bubble_sort(int* array);
void copy_array(int* array, int* array_copy);
void find_index(int* array, int* result_array, int* destination);

int main()
{
    char* names[TABLE_SIZE] = { "Jan", "Piotr", "Michal", "Pawel", "Jakub", "Stefan", "Robert","Mariusz", "Tadeusz", "Konrad" };
    int times[TABLE_SIZE] = { 56, 60, 51, 44, 66, 50, 49, 62, 43, 70 };
    int results[TABLE_SIZE];
    int indexes[NUMBER_OF_TOP_PLACES];
    //char* standings[TABLE_SIZE];
    while (1) { 
        printf("Choose an option: 1 - calculate; 2 - exit program\n"); 
        int option; 
        scanf_s("%d", &option); 
        switch (option) { 
            case 1:
                copy_array(times, results);
                bubble_sort(results);
                find_index(times, results, indexes);
                for (int i = 0; i < TABLE_SIZE; i++) {
                    /* Write your code here */ 
                    printf("%s - %d\n", names[i], times[i]);
                   
                }
                printf("**********\n");
                for (int i = 0; i < NUMBER_OF_TOP_PLACES; i++)
                {
                    printf("%s - %d\n", names[indexes[i]], results[i]);
                }
                break; 
            case 2:
                printf("Exiting program\n"); 
                return 0; 
            default:
                printf("Wrong option choose once again\n"); 
        } 
    }return 0;
}
void bubble_sort(int *array) {
    int tmp;
    for (int i = 0; i < TABLE_SIZE - 1; i++)
    {
        for (int j = 0; j < TABLE_SIZE - i - 1; j++)
        {
            if (array[j] > array[j + 1]) /* For decreasing order use '<' instead of '>' */
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}
void copy_array(int* array, int *array_copy) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        array_copy[i] = array[i];
    }
}
void find_index(int *array, int *result_array, int* destination) {
    int new_array[NUMBER_OF_TOP_PLACES];
    for (int i = 0; i < NUMBER_OF_TOP_PLACES; i++){
        for (int j = 0; j < TABLE_SIZE; j++)
        {
            if (result_array[i] == array[j])
            {
                destination[i] = j;
            }
        }
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
