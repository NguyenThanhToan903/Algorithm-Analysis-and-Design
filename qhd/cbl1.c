#include<stdio.h>
#include<malloc.h>

typedef struct {
	char tendv[20];
	float GT;
	int TL, PA;
}dovat;

dovat* readfile(int *w, int *n){
	FILE *f = fopen("CaiBalo1.txt", "r");
	int i=0;
	fscanf(f, "%d", w);
	dovat *dsdv = (dovat*)malloc(sizeof(dovat));
	
	while(!feof(f)){
		fscanf(f, "%d%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tendv);
		dsdv[i].PA = 0;
		i++;
		dsdv = realloc(dsdv, sizeof(dovat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void printdata(dovat *dsdv, int n, int w){
	int i;
	printf("|---|--------------------|---------|---------|---------------|\n");
	printf("|STT|	Ten do vat       |T. Luong | Gia Tri |So DV duoc chon|\n");
	printf("|---|--------------------|---------|---------|---------------|\n");
	int tongTL = 0;
	float tongGT = 0;
	for(i=0;i<n;i++){
		printf("|%3d|%-20s|%-9d|%-9f|%-8d       |\n", i+1, dsdv[i].tendv, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
		tongTL += dsdv[i].PA*dsdv[i].TL;
		tongGT += dsdv[i].PA*dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------------|\n");
	printf("\nTrong luong cua ba lo = %d", w);
	printf("\nTong trong luong cua cac do vat trong ba lo = %d\nTong gia tri cua cac do vat trong ba lo = %.2f", tongTL, tongGT);
}

void taobang(dovat *dsdv, int n, int w, float f[][w+1], int x[][w+1]){
	int xk, yk, k;
	int xmax, v;
	float fmax;
	
	for(v=0; v<=w;v++){
		x[0][v] = v/dsdv[0].TL;
		f[0][v] = x[0][v]*dsdv[0].GT;
	}
	
	for(k=1; k<n; k++){
		for(v=0; v<=w;v++){
			fmax = f[k-1][v];
			xmax = 0;
			yk = v/dsdv[k].TL;
			
			for(xk=1; xk<=yk; xk++){
				if(f[k-1][v-xk*dsdv[k].TL]+xk*dsdv[k].GT>fmax){
					fmax = f[k-1][v-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					xmax = xk;
				}
			}
			f[k][v]=fmax;
			x[k][v]=xmax;
		}
	}
}

void inbang(int n, int w, float f[][w+1], int x[][w+1]){
	int v, k;
	printf("\n\nBang F va X:\n\n");
	for(k=0; k<n;k++){
		for(v=0; v<=w;v++){
			printf("%4.1f|%2d  ", f[k][v], x[k][v]);
		}
		printf("  \n");
	} 
}

void trabang(dovat *dsdv, int n, int w, int x[][w+1]){
	int k, v;
	v= w;
	for(k=n-1; k>=0;k--){
		dsdv[k].PA = x[k][v];
		v -=x[k][v]*dsdv[k].TL;
	}
}

int main(){
	dovat *dsdv;
	int n, w;
	dsdv = readfile(&w, &n);
	
	int x[n][w+1];
	float f[n][w+1];
	
	taobang(dsdv, n, w, f, x);
	inbang(n, w, f, x);	
	trabang(dsdv, n, w, x);
	printdata(dsdv, n, w);
	
	return 0;
}
