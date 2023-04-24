#include <stdio.h>
typedef int keytype;
typedef float othertype;

typedef struct
{
    keytype key;
    othertype otherfield;
} recordtype;

void swap(recordtype *a, recordtype *b)
{
    recordtype temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void readData(recordtype a[], int *n)
{
    FILE *f;
    f = fopen("data.txt", "r");
    int i = 0;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d%f", &a[i].key, &a[i].otherfield);
            i++;
        }
    }
    else
    {
        printf("Error reading");
    }
    fclose(f);
    *n = i;
}
void InsertionSort(recordtype a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while ((j > 0) && (a[j].key < a[j - 1].key))
        {
            swap(&a[j], &a[j - 1]);
            j--;
        }
    }
}

void printData(recordtype a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d%5d%8.2f\n", i + 1, a[i].key, a[i].otherfield);
    }
}
int main()
{
    recordtype a[100];
    int n;
    printf("Thuat toan Insertion Sort:\n\n");
    readData(a, &n);
    printf("Du lieu truoc khi sap xep:\n");
    printData(a, n);
    InsertionSort(a, n);
    printf("Du lieu sau khi sap xep:\n");
    printData(a, n);
    return 0;
}