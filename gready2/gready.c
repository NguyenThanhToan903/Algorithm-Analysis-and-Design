#include<stdio.h>
#include<malloc.h>

typedef struct{
	char tenDV[50];
	float TL, GT, DG;
	int SL;
}Dovat;

Dovat* readfile(float *w, int *n){
	FILE *f = fopen("CaiBaLo1.txt", "r");
	fscanf(f, "%f", w);
	Dovat *dsdv;
	dsdv = (Dovat*)malloc(sizeof(Dovat));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tenDV);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
		dsdv[i].SL = 0;
		i++;
		dsdv = realloc(dsdv, sizeof(Dovat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void indsdv(ovat *dsdv, int n, float w){
	int i;
	float tongTL = 0, tongGT = 0;
	printf("\nPhuong an thu duoc tu ky thuat Tham An nhu sau: \n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("|STT|	  Ten do vat	 |T. Luong | Gia Tri | Don Gia |So DV Duoc chon|\n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	for(i=0; i<n;i++){
		printf("|%-3d|%-20s|%-9.2f|%-9.2f|%-9.2f|%8d       |\n", i+1, dsdv[i].tenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].SL);
		tongTL += dsdv[i].TL*dsdv[i].SL;
		tongGT += dsdv[i].GT*dsdv[i].SL;
	}
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("\nTrong luong cua ba lo = %-9.2f\n", w);
	printf("Tong trong luong cac vat duoc chon = %-9.2f\n\nTong gia tri = %-9.2f\n", tongTL, tongGT);
}

void swap(Dovat *x, Dovat *y){
	Dovat temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(Dovat *dsdv, int n){
	 int i, j;
	 for(i=0; i<n-1;i++){
	 	for(j=n-1; j>=i+1;j--){
	 		if(dsdv[j].DG>dsdv[j-1].DG){
	 			swap(&dsdv[j], &dsdv[j-1]);
			}
		 }
	 }
}

void gready(Dovat *dsdv, int n, float w){
	int i;
	for(i=0; i<n;i++){
		dsdv[i].SL = (w/dsdv[i].TL);
		w -= dsdv[i].SL * dsdv[i].TL;
	}
}

int main(){
	int n;
	float w;
	Dovat *dsdv;
	dsdv = readfile(&w, &n);
	BubbleSort(dsdv, n);
	gready(dsdv, n, w);
	indsdv(dsdv, n, w);
	free(dsdv);
	return 0;
	
	return 0;
}
