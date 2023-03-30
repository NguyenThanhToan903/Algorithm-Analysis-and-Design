#include<stdio.h>

typedef int keyType;
typedef float otherType;

typedef struct{
	keyType key;
	otherType otherFields;
}recordType;

void swap(recordType *a, recordType *b){
	recordType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void readFileData(recordType A[], int* n){
	FILE *fptr;
	int i=0;
	fptr = fopen("data.txt", "r");
	if(fptr!=NULL){
		
		while(!feof(fptr)){
			fscanf(fptr, "%d%f", &A[i].key, &A[i].otherFields);
			i++;
		}
		
	}else{
		printf("loi mo file!");
	}
	*n = i;
}



void printData(recordType A[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d %5d %8.2f\n", i+1, A[i].key, A[i].otherFields);
	}
}

int findPivot(recordType A[], int i, int j){
	keyType firstKey;
	int k;
	k=i+1;
	firstKey = A[i].key;
	while((k<=j)&&(A[k].key==firstKey)) k++;
	if(k>j) return -1;
	else
		if(A[k].key>firstKey) return k;
		else return i;
}

int partition(recordType A[], int i, int j, keyType pivot){
	int L, R;
	L=i;
	R=j;
	while(L<=R){
		while(A[L].key<pivot) L++;
		while(A[R].key>=pivot) R--;
		if(L<R) swap(&A[L], &A[R]);
	}
	return L;
}

void quickSort(recordType A[], int i, int j){
	keyType pivot;
	int pivotIndex, k;
	pivotIndex = findPivot(A, i, j);
	if(pivotIndex != -1){
		pivot = A[pivotIndex].key;
		k = partition(A, i, j, pivot);
		quickSort(A, i, k-1);
		quickSort(A, k, j);
	}
}

int main(){
	recordType A[100];
	int n;
	readFileData(A, &n);
	
	printf("Selection Sort\n\n");
	printf("Truoc khi su dung BubbleSort \n");
	printData(A, n);
	
	quickSort(A, 0, n);
	printf("Sau khi su dung BubbleSort\n");
	printData(A, n);
	return 0;
}
