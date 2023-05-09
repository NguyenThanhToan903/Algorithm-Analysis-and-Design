#include<stdio.h>

#define size 30

typedef struct{
	float dodai;
	int dau, cuoi;
	int dadung;
}canh;

void readfile(canh a[][size], int *n){
	int i, j;
	FILE *f = fopen("tsp.txt", "r");
	if(f==NULL){
		printf("Loi mo file!!");
		return;
	}
	fscanf(f, "%d", n);
	for(i=0; i<*n;i++){
		for(j=0; j<*n; j++){
			fscanf(f, "%f", &a[i][j].dodai);
			a[i][j].dau = i;
			a[i][j].cuoi = j;
			a[i][j].dadung=0;
		}
	}
	fclose(f);
}

void inmatran(canh a[][size], int n){
	int i, j;
	printf("\nMa tran TRONG SO cua do thi la\n");
	for(i=0; i<n; i++){
		for(j=0; j<n;j++){
			printf(" %c%c = %5.2f	", a[i][j].dau+97, a[i][j].cuoi+97, a[i][j].dodai);
		}
		printf("\n");
	}
}

void inPa(canh pa[], int n){
	int i;
	float sum =0;
	printf("\nPHUONG AN TIM DUOC:\n");
	for(i=0; i<n; i++){
		sum+= pa[i].dodai;
		printf("Canh %c%c = %5.2f\n", pa[i].dau+97, pa[i].cuoi+97, pa[i].dodai);
	}
	printf("Chu trinh: \n");
	for(i=0;i<n; i++){
		printf("%c", pa[i].dau+97);
		printf("-> ");
	}
	printf("%c", pa[0].dau+97);
	printf("\nTong do dai cac canh cua chu trinh = %5.2f\n", sum);
}

float canhNN(canh a[][size], int n){ 
	int i, j;
	float Cmin=999999999;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=j && !(a[i][j].dadung) && a[i][j].dodai<Cmin){
				Cmin = a[i][j].dodai;
		}
		}
	}
	return Cmin;
}

float canduoi(canh a[][size], float TGT, int n, int i){
	return TGT+(n-i)*canhNN(a, n);
}

void capnhatPATNTT(canh a[][size], int n, float TGT, float *GiaNNTT, canh x[], canh pa[]){
	int i;
	x[n-1] = a[x[n-2].cuoi][x[0].dau];
	TGT += x[n-1].dodai;
	if(*GiaNNTT>TGT){
		*GiaNNTT = TGT;
		for(i = 0; i<n; i++){
			pa[i]=x[i];
		}
	}
}

int cochutrinh(canh pa[], int k, int ketiep){
	int i = 0, coCT=0;
	while(i<k&&!coCT==0){
		if(ketiep==pa[i].dau) coCT=1;
		else i++;
	}
	return coCT;
}
void nhanhcan(canh a[][size], int n, int i, int dau, float *TGT, float *CD, float *GiaNNTT, canh x[], canh pa[]){
	int j;
	for(j=0; j<n; j++){
		if(dau!=j && !a[dau][j].dadung && !cochutrinh(x, i, j)){
			*TGT += a[dau][j].dodai;
			*CD = canduoi(a, *TGT, n, i+1);
			if(*CD < *GiaNNTT){
				x[i] = a[dau][j];
				a[dau][j].dadung=1;
				a[j][dau].dadung=1;
				
				if(i==n-2){
					capnhatPATNTT(a, n, *TGT, GiaNNTT, x, pa);
				}
				else{
					nhanhcan(a, n, i+1, j, TGT, CD, GiaNNTT, x, pa);
				}
			}
			*TGT -= a[dau][j].dodai;
			a[dau][j].dadung=1;
			a[j][dau].dadung=1;
		}
	}
}

void reset(canh a[][size], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			a[i][j].dadung = 0;
		}
	}
}


int main(){
	canh a[size][size];
	int n;
	readfile(a, &n);
	canh pa[n], x[n];
	char tpxp;
	inmatran(a, n);
	float TGT = 0, CD = 0, GiaNNTT = 3.40282e+38;
	nhanhcan(a, n, 0, 0, &TGT, &CD, &GiaNNTT, x, pa);
	inPa(pa, n);
	
	
}
