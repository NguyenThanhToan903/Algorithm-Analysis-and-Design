#include<stdio.h>
#include<malloc.h>
typedef struct{
	char tendv[50];
	float TL, DG, GT;
	int PA;
}dovat;

dovat* readfile(int *n, float *w){
	FILE *f = fopen("CaiBalo1.txt", "r");
	int i=0;
	dovat *dsdv = (dovat*)malloc(sizeof(dovat));
	fscanf(f, "%f", w);
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tendv);
			dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
			dsdv[i].PA = 0;
			i++;
			dsdv=realloc(dsdv, sizeof(dovat)*(i+1));
		}
	}
	else{
		printf("1");
	}
	*n = i;
	fclose(f);
	return dsdv;
}


void swap(dovat *a, dovat *b){
	dovat temp =*a; 
	*a= *b;
	*b= temp;
}

void BubbleSort(dovat *dsdv, int n){
	int i, j;
	for(i=0; i<n-1;i++){
		for(j=n-1; j>=i+1;j--){
			if(dsdv[j].DG>dsdv[j-1].DG) swap(&dsdv[j], &dsdv[j-1]);
		}
	}
}

void gready(dovat *dsdv, int n, float w){
	int i;
	for(i=0; i<n; i++){
		dsdv[i].PA = w/dsdv[i].TL;
		if(dsdv[i].PA>1) dsdv[i].PA =1;
		w-=dsdv[i].PA*dsdv[i].TL;
	}
}

void indsdv(dovat *dsdv, int n, float w){
	int i;
	float tongTL = 0, tongGT = 0;
	printf("\nPhuong an thu duoc tu ky thuat Tham An nhu sau: \n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("|STT|	  Ten do vat	 |T. Luong | Gia Tri | Don Gia |So DV Duoc chon|\n");
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	for(i=0; i<n;i++){
		printf("|%-3d|%-20s|%-9.2f|%-9.2f|%-9.2f|%8d       |\n", i+1, dsdv[i].tendv, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
		tongTL += dsdv[i].TL*dsdv[i].PA;
		tongGT += dsdv[i].GT*dsdv[i].PA;
	}
	printf("|---|--------------------|---------|---------|---------|---------------|\n");
	printf("\nTrong luong cua ba lo = %-9.2f\n", w);
	printf("Tong trong luong cac vat duoc chon = %-9.2f\n\nTong gia tri = %-9.2f\n", tongTL, tongGT);
}

int main(){
	int n;
	float w;
	dovat *dsdv;
	dsdv = readfile(&n, &w);
	BubbleSort(dsdv, n);
	gready(dsdv, n, w);
	indsdv(dsdv, n, w);
	free(dsdv);
	return 0;
}
