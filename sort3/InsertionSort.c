#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfield;
}recordtype;


void swap(recordtype *a, recordtype *b){
	recordtype temp =*a;
	*a = *b;
	*b = temp;
}

void readfile(recordtype a[], int *n){
	FILE *f =fopen("data.txt", "r");
	int i=0; 
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfield);
			i++;
		}
	}
	*n=i;
	fclose(f);
}

void printdata(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfield);
	}
}

void InsertionSort(recordtype a[], int n){
	int i, j;
	for(i=0; i<n; i++){
		j = i;
		while((j>0)&&(a[j].key<a[j-1].key)){
			swap(&a[j], &a[j-1]);
			j--;
		}
	}
}

int main(){
	
	printf("Giai thuat sap xep InsertionSort\n\n");
	int n;
	recordtype a[100];
	readfile(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	printdata(a, n);
	printf("Du lieu sau khi sap xep:\n");
	InsertionSort(a, n);
	printdata(a, n);
	return 0;
}
