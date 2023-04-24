#include <stdio.h>
#define N 100
typedef int keyType;
typedef float otherType;

typedef struct
{
    keyType key;
    otherType otherField;
} recordType;

void swap(recordType *x, recordType *y)
{
    recordType temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(recordType a[], int n)
{
    int i, j, lowindex;
    keyType lowkey;
    for (i = 0; i <= n - 2; i++)
    {
        lowkey = a[i].key;
        lowindex = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[j].key < lowkey)
            {
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        swap(&a[i], &a[lowindex]);
    }
}

void readData(recordType a[], int *n)
{
    FILE *f;
    f = fopen("data.txt", "r");
    int i = 0;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d%f", &a[i].key, &a[i].otherField);
            i++;
        }
    }
    else
    {
        printf("Loi mo file");
    }
    fclose(f);
    *n = i;
}

void printData(recordType a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d%5d%8.2f\n", i + 1, a[i].key, a[i].otherField);
    }
}

int main()
{

    recordType a[N];
    int n;
    printf("Thuat toan Selection Sort:\n\n");
    readData(a, &n);
    printf("Du lieu truoc khi sap xep: \n");
    printData(a, n);
    SelectionSort(a, n);
    printf("Du lieu sau khi sap xep: \n");
    printData(a, n);
    return 0;
}