#include<stdio.h>
typedef int keytype;
typedef float othertype;

typedef struct{
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
	*n = i;
	fclose(f);
}

void prindata(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d%5d%8.3f\n", i+1, a[i].key, a[i].otherfield);
	}
}


void Pushdown(recordtype a[], int first, int last){
	int r = first;
	while(r<=(last-2)/2){
		if(last == r*2+1){
			if(a[r].key>a[last].key) swap(&a[r], &a[last]);
			r = last;
		}
		else if(a[r].key>a[r*2+1].key && a[r*2+1].key<=a[2*r+2].key) {
			swap(&a[r], &a[r*2+1]);
			r = 2*r+1;
		}
		else if(a[r].key>a[r*2+2].key && a[r*2+1].key>a[2*r+2].key){
			swap(&a[r], &a[r*2+2]);
			r = 2*r+2;
		}else{
			r= last;
		}
	}
}

void HeadSort(recordtype a[], int n){
	int i;
	for(i=(n-2)/2; i>=0; i--){
		Pushdown(a, i, n-1);
	}
	for(i=n-1; i>=2; i--){
		swap(&a[0], &a[i]);
		Pushdown(a, 0, i-1);
	}
	swap(&a[0], &a[1]);
}



int main(){
	recordtype a[100];
	int n;
	readfile(a, &n);
	printf("Giai Thuat HeapSort:\n\n");
	printf("Du lieu truoc khi sap xep:\n");
	prindata(a, n);
	printf("Du lieu sau khi sap xep:\n");
	HeadSort(a, n);
	prindata(a, n);
	return 0;
}
