//Secant Method
#include <stdio.h>
#include <math.h>
#define f(x) 	((x)*sin(x) + cos(x))	//((x*x)- x - 6)			//(pow(E,x) - (2*x) - 1) 		
#define df(x) 	((x)*cos(x))	//(2*x - 1)				//(pow(E,x) - 2) 
#define E 2.718281828	 	
#define EPSILON 0.0000005

int main(void){
	FILE *fp1 = fopen("secant.txt", "w"), *fp2 = fopen("secantP1.txt", "w");
	float x0, x1, x2, order, e0, e1 = E;
	int count = 0;
	printf("Enter the values of x0, and x1\n");
	scanf("%f %f", &x0, &x1);
	while(f(x0)*f(x1) > 0){
		printf("Please enter the values of x0 and x1 again.\n");
		scanf("%f %f", &x0, &x1);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("Iteration.No.\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\tx2\t\tAbs. Error.\tOrder of Convergence\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	do{
		x2 = (x0*f(x1) - x1*f(x0))/(f(x1) - f(x0));
		e0 = fabs(x1-x0);
		e1 = fabs(x2-x1);
		order = logf(e1)/logf(e0);
		printf("%d \t\t%f \t%f \t%f \t%f \t%f \t%f \t%f\n", count, x0, f(x0), x1, f(x1), x2, e1, order );
		fprintf(fp1,"%f %f\n%f %f\n\n",x0, f(x0), x1, f(x1));
		fprintf(fp2,"%f %f\n%f 0\n\n",x0, f(x0), x0);
		fprintf(fp2,"%f %f\n%f 0\n\n",x1, f(x1), x1);
		fprintf(fp2,"%f %f\n%f 0\n\n",x2, f(x2), x2);
		count++;
		x0 = x1;
		x1 = x2;
	} while(fabs(x1-x0) > EPSILON); 
	printf("\nRoot : %f\n", x1);
	return 0;
}

