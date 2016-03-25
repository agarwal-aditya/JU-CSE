// Program to iteratively find out root of a quadratic equation
// e**x - 4*x*x = 0

#include <stdio.h>
#include <math.h>

#define E 2.718281828
#define EPSILON 0.0000005
float f(float x){
	return (pow(E,x) - 4*x*x);
}

float g1(float xOld){ //generating function : xNew = +pow(e,x/2)/2
	float xNew = 0;
	xNew = pow(E,xOld/2)/2;
	return xNew;
}
float g1Dash(float x){
	return 1.0/4*pow(E,x/2);
}

float g2(float xOld){ //generating function : xNew = ln(4*x*x)
	float xNew = 0;
	xNew = log(4*xOld*xOld);
	return xNew;
}

float g2Dash(float x){
	return 2.0/x;
}

float error(float x, float xNew){
	return fabs(xNew-x);
}

int main(void){
	int count = 1;
	float x, xNew = 1; //assuming inital value of x to be 1;
	printf("g(x) = e**(x/2)/2\n");
	printf("Iteration No.\tx_(i-1)\t\tx_i\t\tg'(x)\t\tf(x)\t\tAbs.Error\n");
	do{
	x = xNew;
	xNew = g1(x);
	printf("%13d\t%f\t%f\t%f\t%f\t%f\n", count, x, xNew, g1Dash(xNew), f(xNew), error(x,xNew));
	if(g1Dash(xNew) > 1 || g1Dash(xNew) < -1){
		printf("Approximation will not converge!\n");
		break;
	}
	count ++;
	}while (x-xNew > EPSILON  || x-xNew < - EPSILON);
	printf("\nRoot = %f\n", xNew);
	printf("\n\n");

	printf("g(x) = ln(4*x*x)\n");
	xNew = 4;	
	count = 1;
	printf("Iteration No.\tx_(i-1)\t\tx_i\t\tg'(x)\t\tf(x)\t\tAbs.Error\n");
	do{
	x = xNew;
	xNew = g2(x);
	printf("%13d\t%f\t%f\t%f\t%f\t%f\n", count, x, xNew, g2Dash(xNew), f(xNew), error(x,xNew));
	if(g2Dash(xNew) > 1 || g2Dash(xNew) < -1){
		printf("Approximation will not converge!\n");
		break;
	}
	count ++;
	} while (x-xNew > EPSILON  || x-xNew < - EPSILON);
	printf("\nRoot = %f\n", xNew);

	return 0;
}
