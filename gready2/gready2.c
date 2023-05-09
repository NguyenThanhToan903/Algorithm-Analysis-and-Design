#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct{
	char tendovat[50];
	float TL, GT, DG;
	int SL, PA;
}doVat;

doVat* readfile(float *w, int *n){
	FILE *f;
	f = fopen("CaiBalo2.txt", "r");
	if(f==NULL) {
		printf("Loi");
		return;
	}
	doVat *dsdv;
	dsdv = (doVat*)malloc(sizeof(doVat));
	fscanf(f,"%f", w);
	int i=0;
	while(!feof(f)){
		fscanf(f,"%f%f%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].tendovat);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = realloc(dsdv, sizeof(doVat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}


void printdata(doVat *dsdv, int n, float w){
	int i = 0;
	float tongGt = 0, tongTl = 0;
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("|STT|	Ten do vat       |T. Luong | Gia Tri | Don Gia |So DV duoc chon|\n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	for(i=0; i<n;i++){
		printf("|%3d|%-20s|%-9.2f|%-9.2f|%-9.2f|%8d       |\n", i+1, dsdv[i].tendovat, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		tongTl += dsdv[i].TL+dsdv[i].PA;
		tongGt += dsdv[i].GT+dsdv[i].PA;
	}
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("\nTrong luong cua  ba lo la = %.2f", w);
	printf("\nTong trong luong cac do vat duoc chon = %.2f\nTong gia tri cac do vat duoc chon = %.2f", tongTl, tongGt);
}

void swap(doVat *a, doVat *b){
	doVat temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(doVat *dsdv, int n){
	int i, j;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>=i+1;j--){
			if(dsdv[j].DG>dsdv[j-1].DG) swap(&dsdv[j], &dsdv[j-1]);
		}
	}
}

void gready(doVat *dsdv, int n, float w){
	int i;
	for(i=0; i<n; i++){
		dsdv[i].PA = (w/dsdv[i].TL);
		if(dsdv[i].PA>=dsdv[i].SL){
			dsdv[i].PA = dsdv[i].SL;
		}
		w-=dsdv[i].PA*dsdv[i].TL;
	}
}

int main(){
	int n;
	doVat *dsdv;
	float w;
	dsdv = readfile(&w, &n);
	bubblesort(dsdv, n);
	
	gready(dsdv, n, w);
	printdata(dsdv, n, w);
	free(dsdv);
	
	return 0;
}
