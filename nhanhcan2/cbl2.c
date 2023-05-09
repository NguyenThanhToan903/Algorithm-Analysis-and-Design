#include<stdio.h>
#include<malloc.h>

typedef struct{
	char tendv[50];
	float TL, GT, DG;
	int SL, PA;
}dovat; 

dovat* readfile(int *n, float *w){
	FILE *f = fopen("CaiBalo2.txt", "r");
	dovat *dsdv;
	fscanf(f, "%f", w);
	dsdv = (dovat*)malloc(sizeof(dovat));
	int i=0;
	while(!feof(f)){
		fscanf(f, "%f%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].tendv);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
		i++;
		dsdv = realloc(dsdv, sizeof(dovat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void printdata(dovat *dsdv, int n, float w){
	int i =0;
	float tongtl=0, tonggt = 0;
	
	printf("|---|-----------------------|---------|---------|---------|---------------|\n");
	printf("|STT|      Ten do vat       | T.Luong | Gia Tri | Don Gia |So DV duoc chon|\n");
	printf("|---|-----------------------|---------|---------|---------|---------------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d|%-20s|%-9.2f|%-9.2f|%-9.2f|%-9.2f|%8d        \n");
		tongtl += dsdv[i].PA*dsdv[i].TL;
		tonggt += dsdv[i].PA*dsdv[i].GT;	
	}
	printf("Trong luong cua ba lo = %.2f", w);
	printf("Tong trong luong cua do vat trong ba lo = %.2f\nTong gia tri cua do vat trong ba lo = %.2f", tongtl, tonggt);
}

void swap(dovat *a, dovat *b){
	dovat temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(dovat *dsdv, int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>=i+1; j--){
			if(dsdv[j].DG>dsdv[j-1].DG) swap(&dsdv[j], &dsdv[j-1]);
		}
	}
}

void taonutgoc(float w, float *TLConlai, float *CT, float GLNTT, float *TGT, float DGLN){
	*TGT = 0;
	*TLConlai = w;
	*CT = *TLConlai*DGLN;
	GLNTT = 0;
}

void capnhatPATNTT(dovat *dsdv, float *TGT, float GTNTT, int n, int x[]){
	
}

int min(int a, int b) a>b?a:b;

void nhanhcan(int i, float *TGT, float *CT, float *TLConlai, dovat *dsdv, int x[], int n){
	int j;
	int temp = min
}


int main(){
	
	return 0;
}
