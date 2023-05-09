#include<stdio.h>
#define size 30


typedef struct{
	float do_dai;
	int dau, cuoi;
}canh;

void readfile(char file_name[],canh a[], int *n){
	int i, j, t;
	float temp;
	FILE *f = fopen(file_name, "r");
	if(f!=NULL){
		fscanf(f, "%d", n);
		int k = 0;
		for(i=0; i<*n;i++){
			for(j=i; j<*n; j++){
				if(i==j) for(t=0; t<=j;t++) fscanf(f,"%f", &temp);
				else{
					fscanf(f, "%f", &a[k].do_dai);
					a[k].dau = i;
					a[k].cuoi = j;
					k++;
				}
			}
		}
	}else{
		printf("Loi mo file!!\n");
		return;
	}
	fclose(f);
}

void indsCanh(canh a[], int m, int la_pa){
	int i;
	float tong = 0;
	for(i=0; i<m; i++){
		printf("%3d %c%c = %8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].do_dai);
		if(la_pa){
			tong+=a[i].do_dai;
		}
	}
	if(la_pa){
		printf("Tong do dai cac canh = %5.2f\n", tong);
	}
}

void swap(canh *a, canh *b){
	canh temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(canh a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j = n-1;j>i;j--){
			if(a[j].do_dai<a[j-1].do_dai){
				swap(&a[j], &a[j-1]);
			}
		}
	}
}

int dinh_cap3(canh pa[], int k, canh moi){
	int i, dem;
	i = 0;
	dem  =1;
	while(i<k && dem <3){
		if(moi.dau == pa[i].dau || moi.dau == pa[i].cuoi){
			dem++;
		}
		i++;
	}
	if(dem==3)return 1;
	i=0;
	dem  =1 ;
	while(i<k && dem<3){
		if(moi.cuoi==pa[i].dau || moi.cuoi == pa[i].cuoi){
			dem++;
		}
		i++;
	}
	return dem==3;
}

void init_forest(int parent[], int n){
	int i;
	for(i=0; i<n; i++){
		parent[i] = i;
	}
}

int find_root(int parent[], int u){
	while(u!=parent[u]){
		u = parent[u];
	}
	return u;
}

int chu_trinh(int r_dau, int r_cuoi){
	return (r_dau == r_cuoi);
}

void update_forest(int parent[], int r1, int r2){
	parent[r2] = r1;
}

void gready(canh ds_canh[], int n, canh pa[]){
	int i, j;
	int parent[n];
	init_forest(parent, n);
	int r_dau, r_cuoi;
	j=0;
	for(i=0;i<n*(n-1)/2 && j<n-1;i++){
		r_dau = find_root(parent, ds_canh[i].dau);
		r_cuoi = find_root(parent, ds_canh[i].cuoi);
		if(!dinh_cap3(pa, j, ds_canh[i])&&!chu_trinh(r_dau, r_cuoi)){
			pa[i] = ds_canh[i];
			j++;
			update_forest(parent, r_dau, r_cuoi);
		}
	}
	
	for(;i<n*(n-1)/2;i++){
		r_dau = find_root(parent, ds_canh[i].dau);
		r_cuoi = find_root(parent, ds_canh[i].cuoi);
		if(!dinh_cap3(pa, n-1, ds_canh[i])&&!chu_trinh(r_dau, r_cuoi)){
			pa[n-1] = ds_canh[i];
			break;
		}
	}
}

int main(){
	canh ds_canh[size];
	int n;
		
	printf("Phuong an TSP dung thuat toan THAM AN:\n");
	readfile("TSP.txt", ds_canh, &n);
	printf("Danh sach cac canh cua do thi:\n");
	indsCanh(ds_canh, n*(n-1)/2, 0);
	
	BubbleSort(ds_canh, n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da SAP XEP:\n");
	indsCanh(ds_canh, n*(n-1)/2, 0);
	
	canh PA[n];
	gready(ds_canh, n, PA);
		
	printf("\nPHUONG AN\n");
	indsCanh(PA, n, 1);
	return 0;
}
