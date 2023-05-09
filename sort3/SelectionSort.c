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
	*b = temp;
}

void SelectionSort(recordtype a[], int n){
	int i, j, lowindex;
	keytype lowkey;
	for(i=0; i<n-1;i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j=i+1; j<n; j++){
			if(a[j].key<lowkey) {
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		swap(&a[i], &a[lowindex]);
	}
}

void readfile(recordtype a[], int *n){
	int i=0;
	FILE *f=fopen("data.txt", "r");
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfield);
			i++;
		}
	}
	else printf("Loi mo file!");
	*n = i;
	fclose(f);
}

void printdata(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfield);
	}
}


int main(){
	
	printf("Giai thuat Selection Sort:\n\n");
	int n;
	recordtype a[100];
	readfile(a, &n);
	printf("Du lieu truoc khi sap xep: \n");
	
	printdata(a, n);
	printf("Du lieu sau khi sap xep: \n");
	SelectionSort(a, n);
	printdata(a, n);
	return 0;
}
