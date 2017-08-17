#include <stdio.h>

void quickSort(int *array, int startIndex, int endIndex);
void printfIntArray(int *array, int length);

int main()
{
    printf("hello\n");

    int a[8] = {5, 8, -4, 15, 8, 1, 9, -20};
    printfIntArray(a, 8);
    quickSort(a,0,7);
    printfIntArray(a, 8);
    getchar();
    return 0;
}

int partition(int *array, int startIndex, int endIndex)
{
    int key = array[endIndex];

    int temp;
    int i = startIndex - 1;
    for (int j = startIndex; j < endIndex; j++)
    {
        if (array[j] < key)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[endIndex] = array[i + 1];
    array[i + 1] = key;
    return i + 1;
}

void quickSort(int *array, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int r = partition(array, startIndex, endIndex);
        quickSort(array, startIndex, r - 1);
        quickSort(array, r + 1, endIndex);
    }
}

void printfIntArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}