/* LU Decomposition for solving linear equations */

#include<stdio.h>
#include <stdlib.h>

int main(void){
    	int n,i,k,j,p;
    	
	printf("Enter the order of the matrix\n");
    	scanf("%d",&n);
    	
    	float a[n][n], b[n], sum;
    	float *l[n], *u[n], *z, *x;
    	z = (float*)calloc(n, sizeof(float));
    	x = (float*)calloc(n, sizeof(float));
    	for(i = 0;i<n;i++){
    		l[i] = (float*)calloc(n, sizeof(float));
    		u[i] = (float*)calloc(n, sizeof(float));
    	}
    		
    	printf("Enter all coefficients of matrix :\n");
    	for(i=0;i<n;i++){
        	for(j=0;j<n;j++)
            		scanf("%f",&a[i][j]);
    	}
    	printf("Enter elements of B matrix :\n");
    	for(i=0;i<n;i++)
       		scanf("%f",&b[i]);
    
    	// LU decomposition
    	for(i=0;i<n;i++){
    		u[i][i] = 1;
    		l[i][0] = a[i][0]; 
    	}
    	for(j=1;j<n;j++){
    		u[0][j] = a[0][j]/l[0][0]; 
    	}
    	for(i=1;i<n;i++){
    		for(j=1;j<=i;j++){
    			sum = 0;
    			for(k=0; k <= j-1;k++){
    				sum += l[i][k]*u[k][j];
    			}
    			l[i][j] = a[i][j] - sum;
    		}
    		for(j = i+1; j < n; j++){
    			sum = 0;
    			for(k=0; k <= i-1; k++){
    				sum += l[i][k]*u[k][j];
    			}
    			u[i][j] = (a[i][j] - sum)/l[i][i];
    		}
    	}
    	
    	//Displaying LU matrix
    	printf("L matrix is \n");
    	for(i=0;i<n;i++){
        	for(j=0;j<n;j++)
            		printf("\t%.6f\t",l[i][j]);
            	printf("\n");
    	}
    	printf("\n");
    	printf("U matrix is \n");
    	for(i=0;i<n;i++){
        	for(j=0;j<n;j++)
           		printf("\t%.6f\t",u[i][j]);
           	printf("\n");
    	}

    	//FINDING Z; LZ=B
    	for(i=0;i<n;i++){              	//forward subtitution
        	sum=0;
        	for(p=0;p<i;p++)
        		sum+=l[i][p]*z[p];
        	z[i]=(b[i]-sum)/l[i][i];
    	}
    
    	//FINDING X; UX=Z
    	for(i=n-1;i>=0;i--){
        	sum=0;
        	for(p=n-1;p>i;p--)
        		sum+=u[i][p]*x[p];
        		x[i]=(z[i]-sum)/u[i][i];
    	}
    	
    	//Output the solution to the screen : X 
    	printf("Set of solution is:\n");
    	for(i=0;i<n;i++)
        	printf("x[%d] = %.6f\n",i, x[i]);
       	printf("\n");
    	
    	return 0;
}
