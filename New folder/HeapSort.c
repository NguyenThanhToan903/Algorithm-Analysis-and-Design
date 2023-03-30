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

void pushDown(recordType A[], int first, int last){
	int r = first;
	while(r<=(last-1)/2){
		if(last == 2*r+1){
			if(A[r].key>A[last].key)
				swap(&A[r], &A[last]);
			r = last;
		}
		else if((A[r].key > A[2*r+1].key) && (A[2*r+1].key <= A[2*r+2].key)){
			swap(&A[r], &A[2*r+1]);	
			r = 2*r+1;		
		}
		else if((A[r].key > A[2*r+2].key) && (A[2*r+2].key < A[2*r+1].key)){
			swap(&A[r], &A[2*r+2]);	
			r = 2*r+2;
		}
		else{
			r = last;
		}
	}
}
void heapSort(recordType A[], int n){
	int i;
	for(i=(n-2)/2; i>=0; i--){
		pushDown(A, i, n-1);
	}
	for(i=n-1; i>=2; i--){
		swap(&A[0], &A[i]);
		pushDown(A, 0, i-1);
	}
	swap(&A[0], &A[1]);
	
}

int main(){
	recordType A[100];
	int n;
	readFileData(A, &n);
	
	printf("Selection Sort\n\n");
	printf("Truoc khi su dung BubbleSort \n");
	printData(A, n);
	
	heapSort(A, n);
	printf("Sau khi su dung BubbleSort\n");
	printData(A, n);
	return 0;
}
