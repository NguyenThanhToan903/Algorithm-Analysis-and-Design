#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct{
	char tendv[50];
	float TL, DG, GT;
	int PA;
}dovat;


dovat* readfile( int *n, float *w){
	FILE *f = fopen("CaiBalo3.txt", "r");
	if(f==NULL){
		printf("Loi!");
		return;
	}
	dovat *dsdv;
	dsdv = (dovat*)malloc(sizeof(dovat));
	int i=0;
	fscanf(f, "%f", w);
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tendv);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
		i++;
		dsdv = realloc(dsdv,sizeof(dovat)*(i+1));
	}
	*n = i;
	return dsdv;
}

void printdata(dovat *dsdv, int n, float w){
	int i;
	float tonggt=0, tongtl=0;
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("|STT|     Ten do vat     |T. Luong | Gia Tri | Don Gia |So DV duoc chon|\n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	for(i=0;i<n;i++){	
		printf("|%-3d|%-20s|%-9.2f|%-9.2f|%-9.2f|%8d       |\n", i+1, dsdv[i].tendv, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		tongtl +=dsdv[i].PA*dsdv[i].TL;
		tonggt +=dsdv[i].PA*dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("Trong luong cua ba lo = %f", w);
	printf("Tong trong luong cua do vat = %f\nTong gia tri cua do vat = %f\n", tongtl, tonggt);
}

void swap(dovat *a, dovat *b){
	dovat temp = *a;
	*a =*b;
	*b = temp;
}

void bubblesort(dovat *dsdv, int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>i+1; j--){
			if(dsdv[j].DG>dsdv[j-1].DG)  swap(&dsdv[j] ,&dsdv[j-1]);
		}
	}
}

void gready(dovat *dsdv, int n, float w){
	int i;
	for(i=0;i<n;i++){
		dsdv[i].PA = w/dsdv[i].TL;
		if(dsdv[i].PA>1) dsdv[i].PA = 1;
		w-=dsdv[i].PA*dsdv[i].TL;
	}
}

int main(){
	dovat *dsdv;
	int n;
	float w;
	dsdv = readfile(&n, &w);
	bubblesort(dsdv, n);
	gready(dsdv, n, w);
	printdata(dsdv, n, w);
	return 0;
}


