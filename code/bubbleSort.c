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

void bubbleSort(recordType A[], int n){
	int i, j;
	for(i=0; i<=n-2;i++){
		for(j=n-1; j>=i+1;j--){
			if(A[j].key<A[j-1].key){
				swap(&A[j],&A[j-1]);
			}
		}
	}
}

int main(){
	recordType A[100];
	int n;
	readFileData(A, &n);
	
	printf("Selection Sort\n\n");
	printf("Truoc khi su dung BubbleSort \n");
	printData(A, n);
	
	bubbleSort(A, n);
	printf("Sau khi su dung BubbleSort\n");
	printData(A, n);
	return 0;
}
