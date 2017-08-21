#include <stdio.h>

void insertSort(int *array, int length);
void printfArray(int *array, int length);

int main()
{
    printf("hello\n");

    int array[] = {10, 7, -2, 5, 8, 4, 1, -1, 5};
    printfArray(array, sizeof(array) / sizeof(int));
    insertSort(array, sizeof(array) / sizeof(int));
    printfArray(array, sizeof(array) / sizeof(int));
    getchar();
    return 0;
}

void insertSort(int *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printfArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}