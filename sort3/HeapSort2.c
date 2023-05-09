#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfield;
}recordtype;


void swap(recordtype *a, recordtype *b){
	recordtype temp =*a;
	*a=*b;
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
	else{
		printf("Loi mo file");
	}
	fclose(f);
	*n = i;
}

void printdata(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfield);
	}
}

void PushDown(recordtype a[], int first, int last){
	int r = first;
	while(r<=(last-2)/2){
		if(last == r*2+1){
			if(a[r].key>a[last].key) swap(&a[r], &a[last]);
			r = last;
		}
		else if(a[r].key>a[2*r+1].key && a[r*2+1].key<=a[r*2+2].key){
			swap(&a[r], &a[2*r+1]);
			r = 2*r+1;
		}
		else if(a[r].key>a[2*r+2].key && a[r*2+1].key>a[r*2+2].key){
			swap(&a[r], &a[2*r+2]);
			r = 2*r+2;
		}
		else{
			r = last;
		}
	}
}

void HeapSort(recordtype a[], int n){
	int i;
	for(i=(n-2)/2; i>=0; i--){
		PushDown(a, i, n-1);
	}
	for(i=n-1; i>1;i--){	
		swap(&a[0], &a[i]);
		PushDown(a, 0, i-1);
	}
	swap(&a[0], &a[1]);
}

int main(){
	recordtype a[100];
	int n;
	printf("Giai thuat Quick Sort: \n\n");
	readdata(a, &n);
	printf("Du lieu truoc khi sap xep: \n");
	printdata(a, n);
	printf("Du lie sau khi sap xep: \n");
	HeapSort(a, n);
	printdata(a, n);
	return 0;
}
