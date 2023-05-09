#include<stdio.h>
typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfield;
}recordtype;

void swap(recordtype *a, recordtype *b){
	recordtype temp =*a;
	*a =*b;
	*b=temp;
}

void readdata(recordtype a[], int *n){
	FILE *f = fopen("data.txt", "r");
	int i=0;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfield);
			i++;
		}
	}
	*n = i;
	fclose(f);
}

void printdata(recordtype a[], int n){
	int i;
	for(i=0; i< n; i++){
		printf("%3d|%5d|%8.2f\n", i+1, a[i].key, a[i].otherfield);
	}
}

void BubbleSort(recordtype a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>=i+1; j--){
			if(a[j].key<a[j-1].key){
				swap(&a[j], &a[j-1]);
			}
		}
	}
}
int main(){
	printf("Giai thuat sap xep BubbleSort\n\n");
	int n;
	recordtype a[100];
	readdata(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	printdata(a, n);
	printf("Du lieu sau khi sap xep:\n");
	BubbleSort(a, n);
	printdata(a, n);
	return 0;
}
