// Jacobi Method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 0.0000005

void print1(float *a, int n);
void print2(float **a, int n);

int main(void){
	int n, i, j, k;
	printf("Enter the number of simultaneous equations in the system: ");
	scanf("%d", &n);
	
	float *a[n], *d[n], *l[n], *u[n], *x, *b, *mat[n], temp, err;
	
	for(i = 0; i<n; i++){
		a[i] = (float *) calloc( n , sizeof(float));
		d[i] = (float *) calloc( n , sizeof(float));
		l[i] = (float *) calloc( n , sizeof(float));
		u[i] = (float *) calloc( n , sizeof(float));
		mat[i] = (float *) calloc( n , sizeof(float));
	}
	x = (float *)calloc( n , sizeof(float));
	b = (float *)calloc( n , sizeof(float));
	
	printf("Enter the augmented matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			scanf("%f", &a[i][j]);
		scanf("%f", &b[i]);
	}

	printf("A Matrix:\n");
	print2(a, n);
	printf("B Matrix:\n");
	print1(b, n);

	for(i = 0; i<n; i++){
		for(j = 0; j < n; j++){
			if( i > j)
				l[i][j] = a[i][j];
			else if( i == j)
				d[i][j] = a[i][j];
			else
				u[i][j] = a[i][j];
			mat[i][j] = l[i][j] + u[i][j];	// mat = l + u
		}
	}
	printf("L Matrix:\n");
	print2(l, n);
	printf("U Matrix:\n");
	print2(u, n);
	printf("D Matrix:\n");
	print2(d, n);
	for(i=0; i<n;i++)
		d[i][i] = 1/d[i][i];

	printf("D Inverse Matrix:\n");
	print2(d, n);

	for(i=0; i<n; i++)
		b[i] = b[i]*d[i][i];		//D^(-1)*B

	//printf("D^(-1)*B Matrix:\n");
	//print1(b, n);

	//printf("(l+u) Matrix:\n");
	//print2(mat, n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			temp = 0;
			for( k = 0; k < n; k++)
				temp += d[i][k]*mat[k][j];
			mat[i][j] = temp;
				
		}
	}
	//printf("d-1(l+u) Matrix:\n");
	//print2(mat, n);

	do{
		printf("X Matrix:\n");
		print1(x, n);
		err = 0;	
		for(i = 0; i < n; i++){
			temp = b[i];
			for(j = 0; j < n; j++)
				temp -= mat[i][j]*x[j];
			if(fabs(temp - x[i]) > err)
				err = fabs(temp - x[i]);
			x[i] = temp;
		}
	}while(err >= E);
	
	print1(x, n);

	free(x);
	free(b);
	for(i=0;i<n;i++){
		free(a[i]);
		free(l[i]);
		free(u[i]);
		free(d[i]);
		free(mat[i]);
	}
	
	return 0;
}

void print1(float *a, int n){
	int i;
	for(i=0;i<n;i++){
		printf("\n\t");
		printf("%.6f ",a[i]);
	}
	printf("\n\n");
}

void print2(float **a, int n){
	int i, j;
	for(i=0;i<n;i++){
		printf("\n\t");
		for(j=0;j<n;j++)
			printf("%.6f ", a[i][j]);
	}
	printf("\n\n");
}