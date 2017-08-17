#include <stdio.h>
void printfArray(int *array, int length);
//void maxHeapify(int *array, int size, int index);
//void buildMaxHeap (int* array, int size);
void heapSort(int *array, int size);
inline int heapLeft(int i)
{
    return 2 * i + 1;
}

inline int heapRight(int i)
{
    return 2 * i + 2;
}

int main()
{
    printf("hello\n");
    int a[8] = {8, 5, 10, 9, -9, 12, 7, 0};
    printfArray(a, 8);
    heapSort(a, 8);
    //maxHeapify(a, 8, 0);
    //buildMaxHeap(a,8);
    printfArray(a, 8);
    getchar();

    return 0;
}

void maxHeapify(int *array, int size, int index)
{
    int LIndex = heapLeft(index);
    int RIndex = heapRight(index);
    int maxIndex = index;

    if (LIndex < size && array[LIndex] > array[maxIndex])
        maxIndex = LIndex;
    if (RIndex < size && array[RIndex] > array[maxIndex])
        maxIndex = RIndex;
    if (maxIndex != index)
    {
        int temp = array[index];
        array[index] = array[maxIndex];
        array[maxIndex] = temp;
        maxHeapify(array, size, maxIndex);
    }
}

void buildMaxHeap(int *array, int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        maxHeapify(array, size, i);
    }
}

void heapSort(int *array, int size)
{
    buildMaxHeap(array, size);
    int temp;
    for (int i = size - 1; i >= 1; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        size--;
        maxHeapify(array, size, 0);
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