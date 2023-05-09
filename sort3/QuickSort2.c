#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfield;
}recordtype;

void readfile(recordtype a[], int *n){
	FILE *f = fopen("data.txt", "r");
	int i;
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
	for(i=0; i<n; i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfield);
	}
}

void swap(recordtype *a, recordtype *b){
	recordtype temp =*a;
	*a = *b;
	*b = temp;
}

int  FindPivot(recordtype a[], int i, int j){
	int k=i+1;
	keytype firstkey = a[i].key;
	while((k<=j)&&(a[k].key==firstkey)) k++;
	if(k>j) return -1;
	else if(a[k].key>firstkey) return k; else return i;
}

int Partiton(recordtype a[], int i, int j, keytype pivot){
	int l, r;
	l = i;
	r = j;
	while(l<r){
		while(a[l].key<pivot) l++;
		while(a[r].key>=pivot) r--;
		if(l<r) swap(&a[l], &a[r]);
	}
	return l;
}


void QuickSort(recordtype a[], int i, int j){
	int pivot, k, pivotindex = FindPivot(a, i, j);
	if(pivotindex!=-1){
		pivot = a[pivotindex].key;
		k = Partiton(a, i, j, pivot);
		QuickSort(a, i, k-1);
		QuickSort(a, k, j);
	}
}

int main(){
	int n;
	recordtype a[100];
	readfile(a, &n);
	printf("Giai thuat QuickSort:\n\n");
	printf("Du lieu truoc khi sap xep:\n");
	printdata(a, n);
	printf("Du lieu sau khi sap xep:\n");
	QuickSort(a, 0, n-1);
	printdata(a, n);
	
	return 0;
}
