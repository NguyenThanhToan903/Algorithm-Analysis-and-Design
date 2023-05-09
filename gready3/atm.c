#include<stdio.h>
#include<malloc.h>

typedef struct{
	char tentien[25];
	int mg, pa;
}Tien;


Tien* readfile(int *n){
	FILE *f = fopen("ATM.txt", "r");
	Tien *dslt;
	dslt = (Tien*)malloc(sizeof(Tien));
	int i =0;
	while(!feof(f)){
		fscanf(f, "%d%[^\n]", &dslt[i].mg, &dslt[i].tentien);
		dslt[i].pa = 0;
		i++;
		dslt =  (Tien*)realloc(dslt, sizeof(Tien)*(i+1));
	}
	*n = i;
	fclose(f);
	return dslt;
}

void inDS(Tien *dslt, int n, int TienCanRut){
	int i;
	int tongTienTra = 0;
	printf("|---|------------------------|---------|---------|-----------|\n");
	printf("|STT|       Loai Tien        |Menh Gia |  So to  | Thanh Tien|\n");
	printf("|---|------------------------|---------|---------|-----------|\n");
	for(i=0; i<n; i++){
		printf("|%-3d", i+1);
		printf("|%-24s", dslt[i].tentien);;
		printf("|%-9d", dslt[i].mg);
		printf("|%-9d", dslt[i].pa);
		printf("|%-11d|\n", dslt[i].mg*dslt[i].pa);
		tongTienTra += dslt[i].pa*dslt[i].mg;
	}
	printf("|---|------------------------|---------|---------|-----------|\n");
	printf("So tien can rut = %9d\n", TienCanRut);
	printf("So tien da tra = %9d\n", tongTienTra);
}


void swap(Tien *a, Tien *b){
	Tien temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(Tien *dslt, int n){
	int i, j;
	for(i=0; i<n-1;i++){
		for(j=n-1; j>=i+1;j--){
			if(dslt[j].mg>dslt[j-1].mg) swap(&dslt[j], &dslt[j-1]);
		}
	}
}

void gready(Tien *dslt, int n, int TienCanrut){
	int i;
	for(i=0;i<n; i++){
		dslt[i].pa = TienCanrut/dslt[i].mg;
		TienCanrut-=dslt[i].pa*dslt[i].mg;
	}
}



int main(){
	int n;
	int TienCanRut;
	printf("Nhap so tien can rut: ");
	scanf("%d", &TienCanRut);
	Tien *dslt;
	dslt = readfile(&n);
	BubbleSort(dslt, n);
	gready(dslt, n, TienCanRut);
	inDS(dslt, n, TienCanRut);
	free(dslt);
	return 0;
}
