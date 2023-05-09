#include<stdio.h>
#include<malloc.h>

typedef struct{
	float dodai;
	int dau, cuoi;
}canh;

void readfile(canh a[], int *n){
	FILE *f = fopen("TSP.txt", "r");
	int i, j, k=0;
	float temp;
	if(f!=NULL){
		fscanf(f, "%d", n);
		for(i=0; i<*n; i++){
			for(j=i; j<*n; j++){
				if(j==i) for(t=0; t<=j;t++) fscanf(f, "%f", &temp);
				else{
					fscanf(f, "%f", &a[k].dodai);
					a[k].dau = i;
					a[k].cuoi = j
					k++;
				}
			}
		}	
	}
}

void indscanh()


int main(){
	return 0;
}
