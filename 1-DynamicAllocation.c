#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Example 1
    int *numbers;
    int size = 4;

    numbers = (int *)malloc(size * sizeof(int));

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = %d\n", i, numbers[i]);
    }
    free(numbers);

    return 0;
}