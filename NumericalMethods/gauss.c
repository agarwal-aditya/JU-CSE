//Gaussian Elimination
#include <stdio.h>

int main(void){
	int n, i, j, k;
	printf("Enter the number of linear simultaneous equations:\t");
	scanf("%d", &n);

	float a[n][n+1], factor, x[n], sum;

	printf("Enter the %d x %d matrix:\n", n, n+1);
	for(i = 0; i < n; i++){
    		for(j = 0; j < n + 1; j++){
            		scanf("%f",&a[i][j]);
        		}
    	}

    	for(k = 0; k < n - 1; k++){
        		for(i = k + 1; i < n; i++){
            		factor = a[i][k] / a[k][k];
            		for(j = k; j <= n; j++)
                			a[i][j] = (a[i][j] - (factor * a[k][j]));
        		}
    	}
    
    	printf("Modified Matrix:\n\n");

    	for(i = 0; i < n; i++){
		for(j = 0; j < n + 1; j++){
			printf("%.6f\t", a[i][j]);
		}
		printf("\n");
	}
	
	x[n-1] = a[n-1][n] / a[n-1][n-1];
	for(i = n-2; i >= 0; i--){
        		sum = 0;
        		for(j = i+1; j < n;j++)
            		sum = sum + (a[i][j] * x[j]);
        		x[i] = (a[i][n] - sum)/a[i][i];
    	}
    	
    	printf("\nSolution of the Given System of Equations:\n");
    	
    	for(i = 0; i < n; i++){
        		printf("x_%d = %.6f\n", i, x[i]);
    	}
    	
    	return 0;
}
