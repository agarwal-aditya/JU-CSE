//NewtonRaphson
#include <stdio.h>
#include <math.h>
#define f(x) ((x*x)-x-6) 		
#define fDash(x) (2*x-1)	 	
#define EPSILON 0.0000005

int main(){
	FILE *fp1 = fopen("nRaph.txt", "w"), *fp2 = fopen("nRaphP.txt", "w"); 
	float x,  x_n;
	int count = 0;
	printf("Enter the value of x_0:\t");
	scanf("%f", &x_n);
	do{
		x = x_n;
		printf("x_%d  =  %f\n", count, x);
		x_n = x - f(x)/fDash(x);
		fprintf(fp1,"%f %f\n%f 0\n\n",x, f(x), x_n);
		fprintf(fp2,"%f %f\n%f 0\n\n",x, f(x), x);		
	} while( fabs(x-x_n) > EPSILON );
	printf("\n\tRoot = %f\n", x);
	return 0;
}
