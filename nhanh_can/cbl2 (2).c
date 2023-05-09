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

void taonutgoc(float w, float *TLConLai, float *CT, float *GiaLNTT, float *TGT, float DonGiaLonNhat){
	*TGT = 0;
	*TLConLai = w;
	*CT = *TLConLai*DonGiaLonNhat;
	*GiaLNTT = 0;
}

void capNhatPATNTT(float TGT, float *GiaLNTT, int x[], dovat *dsdv, int n){
	int i;
	if(*GiaLNTT<TGT){
		*GiaLNTT = TGT;
		for(i=0;i<n;i++){
			dsdv[i].PA = x[i];
		}
	}
}

int min(int a, int b){
	return a<b?a:b;
}

void nhanhcan(int i, float *TGT, float *CT, float *TLConLai, float *GiaLNTT, int x[], dovat *dsdv, int n){
	int j;
	int temp = min(dsdv[i].SL,*TLConLai/dsdv[i].TL);
	for(j=temp;j>=0;j--){
		*TGT += j*dsdv[i].GT;
		*TLConLai -= j*dsdv[i].TL;
		*CT = *TGT * *TLConLai*dsdv[i+1].DG;
		
		if(*CT>*GiaLNTT){
			x[i]=j;
			if((i==n-1)||(*TLConLai==0)){
				capNhatPATNTT(*TGT, GiaLNTT, x, dsdv, n);
			}
			else{
				nhanhcan(i+1, TGT, CT, TLConLai, GiaLNTT, x, dsdv, n);
			}
		}x[i]=0;
		*TGT-=j*dsdv[i].GT;
		*TLConLai+=j*dsdv[i].TL;
	}
}

int main(){
	dovat *dsdv;
	int n;
	float w, CT, TGT, TLConLai, GiaLNTT;
	dsdv = readfile(&n, &w);
	int x[n];
	bubblesort(dsdv, n);
	taonutgoc(w, &TLConLai, &CT, &GiaLNTT, &TGT, dsdv[0].DG);
	nhanhcan(0, &TGT, &CT, &TLConLai, &GiaLNTT, x, dsdv, n);
	printdata(dsdv, n, w);
	free(dsdv);
	return 0;
}
