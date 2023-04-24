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
    FILE *f = fopen("data.txt", "r");
    int i = 0;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d%f", &a[i].key, &a[i].otherfield);
            i++;
        }
    }
    else{
    	prinf("Loi mo file!");
	}
	*n = i;
    fclose(f);
}

void BubbleSort(recordtype a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (a[j].key < a[j - 1].key)
                swap(&a[j], &a[j - 1]);
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
	printf("Giai thuat Bubble Sort: \n\n");
	readData(a, &n);
	printf("Du lieu truoc khi sap xep: \n");
	printData(a, n);
	BubbleSort(a, n);
	printf("Du lieu sau khi sap xep: \n");
	printData(a, n);
    return 0;
}
