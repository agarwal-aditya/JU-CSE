//Gauss Jordan Elimination
#include <stdio.h>

int main(void){
	int n, i, j,  k, l, flag;
	printf("Enter the number of equations:\t");
	scanf("%d",&n);

	float a[n][n+1], factor, x[n], max, var;

	printf("Enter the %d x %d matrix:\n", n, n+1);
	for(i=0;i<n;i++){
    		for(j=0;j<n+1;j++)
            		scanf("%f",&a[i][j]);
    	}

    for(k=0;k<n;k++){
		max=a[k][k];
		flag=0;
        for(l=k+1;l<n;l++){
            if(a[l][k]>max){
				max=a[l][k];		
				flag=l;
            }
        }
        if(flag){
			for(j=0;j<n+1;j++){
				var=a[flag][j];
				a[flag][j]=a[k][j];
				a[k][j]=var;
			}
		}
        for(i=0;i<n;i++){
            if(i == k)
                continue;
            factor= a[i][k] / a[k][k];
            for(j=k;j<=n;j++){
                a[i][j] = (a[i][j] - (factor * a[k][j]));
            }
        }
        printf("\nModified Matrix\n");
        for(i=0; i<n; i++){
			for(j=0; j<n+1; j++){
				printf("%.4f\t", a[i][j]);
			}
			printf("\n");
		}
    }
    
    	/*printf("\n\nFinal Modified Matrix:\n\n");
    	for(i=0; i<n; i++){
		for(j=0; j<n+1; j++){
			printf("%g\t", a[i][j]);
		}
		printf("\n");
	}*/
	
	x[n-1] = a[n-1][n] / a[n-1][n-1];
	for(i=n-2;i>=0;i--){
        		x[i] = a[i][n]/a[i][i];
    	}
    	
    	printf("\nSolution of the Given System:\n");
    	
    	for(i=0;i<n;i++){
        		printf("x_%d = %.6f\n", i, x[i]);
    	}
    	
    	return 0;
}
