#include <stdio.h>

void printArray(int *array, long length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", *(array+i));
    }
}

void swapNumbers(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp; 
}

int *sort_array(int *array, long length) {
    
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-1; j++) {
            if (array[j] > array[j+1]) {
                swapNumbers(&array[j], &array[j+1]);
            }
        }
    }

    printArray(array, length);
    return array;
}


int main() {
    int my_array[] = {8, 7, 3, 99, 5, 10, };
    long my_array_length = sizeof(my_array) / sizeof(my_array[0]);
    int *sorted_array = sort_array(my_array, my_array_length);
}