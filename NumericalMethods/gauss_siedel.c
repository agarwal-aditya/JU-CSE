// Gauss Siedel Method

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
	
	float *a[n], *d[n], *l[n], *u[n], *x, *b, *mat[n], *inv[n],  *t, temp, err, ratio;
	
	for(i = 0; i<n; i++){
		a[i] = (float *) calloc( n , sizeof(float));
		d[i] = (float *) calloc( n , sizeof(float));
		l[i] = (float *) calloc( n , sizeof(float));
		u[i] = (float *) calloc( n , sizeof(float));
		inv[i] = (float *) calloc( n , sizeof(float));
		mat[i] = (float *) calloc( 2*n , sizeof(float));
	}
	x = (float *)calloc( n , sizeof(float));
	b = (float *)calloc( n , sizeof(float));
	t = (float *)calloc( n , sizeof(float));
	
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
			mat[i][j] = l[i][j] + d[i][j];	// mat = l + d
		}
	}
	printf("L Matrix:\n");
	print2(l, n);
	printf("U Matrix:\n");
	print2(u, n);
	printf("D Matrix:\n");
	print2(d, n);
	printf("L+D Matrix:\n");
	print2(mat, n);

	for(i = 0; i < n;i++){
		for(j = n; j < 2*n; j++){
			if( j - n == i)
				mat[i][j] = 1;
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i != j){
				ratio = mat[j][i]/mat[i][i];
				for(k = 0; k< 2*n; k++){
					mat[j][k] -= ratio * mat[i][k];
				}
			}
			else{
                			ratio = mat[i][i];
                			for(k=0; k< 2*n; k++)
                    			mat[i][k] /= ratio ;
                		}
		}
	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			inv[i][j] = mat[i][j+n];
	}

	printf("(L+D)-1 Matrix:\n");
	print2(inv, n);

	for(i = 0; i<n; i++){
		free(mat[i]);
		mat[i] = (float *) calloc( n , sizeof(float));
	}

	for(i=0; i<n; i++)
		for(j=0;j<n;j++)
			t[i] += inv[i][j]*b[j];	

	printf("D^(-1)*B Matrix:\n");
	print1(t, n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for( k = 0; k < n; k++)
				mat[i][j] += inv[i][k]*u[k][j];
		}
	}
	printf("((L+D)^-1)*U Matrix:\n");
	print2(mat, n);

	do{
		printf("X Matrix:\n");
		print1(x, n);
		err = 0;	
		for(i = 0; i < n; i++){
			temp = t[i];
			for(j = 0; j < n; j++)
				temp -= mat[i][j]*x[j];
			if(fabs(temp - x[i]) > err)
				err = fabs(temp - x[i]);
			x[i] = temp;
		}
	}while(err >= E);


	printf("\nSolution of the given system:\n");
	print1(x, n);
		
	free(x);
	free(b);
	free(t);
	for(i=0;i<n;i++){
		free(a[i]);
		free(l[i]);
		free(u[i]);
		free(d[i]);
		free(mat[i]);
		free(inv[i]);
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