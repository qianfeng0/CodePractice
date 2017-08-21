#include <stdio.h>

void printfArray(int *array, int length);
void merge(int *array, int p, int q, int r);
void mergeSort(int *A, int p, int r);

int main()
{
    printf("hello\n");
    int a[8] = {1, 10, 5, 8, 2, 4, 5, 6};
    printfArray(a, sizeof(a) / sizeof(int));
    mergeSort(a, 0, 7);
    //merge(a, 2, 3, 7);
    printfArray(a, sizeof(a) / sizeof(int));
    getchar();
    return 0;
}

void merge(int *array, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    //int L[n1], R[n2];
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[p + i];

    for (int i = 0; i < n2; i++)
        R[i] = array[q + 1 + i];

    int L_index = 0;
    int R_index = 0;
    int index = p;
    while (L_index < n1 && R_index < n2)
    {
        if (L[L_index] < R[R_index])
            array[index++] = L[L_index++];
        else
            array[index++] = R[R_index++];
    }

    while (L_index < n1)
        array[index++] = L[L_index++];
    while (R_index < n2)
        array[index++] = R[R_index++];

    delete R;
    delete L;
    
}

void mergeSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
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