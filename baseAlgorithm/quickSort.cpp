#include <stdio.h>

void quickSort(int *array, int startIndex, int endIndex);
void printfIntArray(int *array, int length);
void quickSort2(int *array, int startIndex, int endIndex);

int main()
{
    printf("hello\n");
    int a[8] = {5, 8, -4, 15, 8, 1, 9, 5};
    printfIntArray(a, 8);
    quickSort2(a,0,7);
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
        //int r = partition(array, startIndex, endIndex);
        int r = partition(array, startIndex, endIndex);
        quickSort(array, startIndex, r - 1);
        quickSort(array, r + 1, endIndex);
    }
}

void quickSort2(int *array, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
        return;
    
    int key = array[startIndex];
    int l = startIndex, r = endIndex;
    
    while(l < r){
        while(l < r && array[r] > key){
            r--;
        }
        array[l] = array[r];

        while(l < r && array[l] <= key){
            l++;
        }
        array[r] = array[l];
    }
    array[l] = key;

    quickSort2(array, startIndex, l - 1);
    quickSort2(array, l + 1, endIndex);

}
void printfIntArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}