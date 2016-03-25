//NewtonRaphson
#include <stdio.h>
#include <math.h>
#define f(x) (pow(E,x) - (2*x) - 1) 		
#define fDash(x) (pow(E,x) - 2) 
#define E 2.718281828	 	
#define EPSILON 0.0000005

int main(){
	FILE *fp1 = fopen("nRaph1.txt", "w"), *fp2 = fopen("nRaphP1.txt", "w"); 
	float x,  x_n;
	int count = 0;
	printf("\nEnter the value of x_0:\t");
	scanf("%f", &x_n);
	printf("Iteration.No.\tx_i\t\tf(x_i)\t\tx_(i+1)\t\tAbs. Error.\n");
	do{
		x = x_n;
		x_n = x - f(x)/fDash(x);
		printf("\t%d\t%f\t%f\t%f\t%f\n", count, x, f(x), x_n, fabs(x_n-x));
		fprintf(fp1,"%f %f\n%f 0\n\n",x, f(x), x_n);
		fprintf(fp2,"%f %f\n%f 0\n\n",x, f(x), x);
		count++;
	} while( fabs(x-x_n) > EPSILON );
	printf("\n\tRoot = %f\n\n", x);
	return 0;
}
