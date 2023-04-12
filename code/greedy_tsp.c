#include <stdio.h>

typedef struct
{
    float doDay;
    int dau, cuoi;
} canh;

void read_file(char *filename[], canh *a[], int *n)
{
    int i, j, t;
    float temp;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error opening");
        return;
            }
    fscanf(f, "%f", &n);
    int k = 0;
    for (i = 0; i < *n; i++){
        for(j = i; j < *n; j++){
            if(i == j){


        }
    }
}

int main()
{

    return 0;
}