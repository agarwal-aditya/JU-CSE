// Program to iteratively find out root of a quadratic equation
// x**2 - x - 6 = 0 => x = +/-{(x+6)**(0.5)}

#include <stdio.h>
#include <math.h>

#define E 0.0000005

float g1(float xOld){ //generating function : xNew = +sqrt(x+6)
	float xNew = 0;
	xNew = sqrt(xOld + 6);
	return xNew;
}
float g1Dash(float x){
	return 1/(2*sqrt(x+6));
}

float g2(float xOld){ //generating function : xNew = -sqrt(x+6)
	float xNew = 0;
	xNew = -sqrt(xOld + 6);
	return xNew;
}

float g2Dash(float x){
	return -1/(2*sqrt(x+6));
}

float error(float x, float xNew){
	return fabs(xNew-x);
}

float f(float x){
	return (x*x - x - 6);
}

int main(void){
	int count = 1;
	float x, xNew = 1; //assuming inital value of x to be 1;
	printf("g(x) = (x+6)**(0.5)\n");
	printf("Iteration No.\tx_(i-1)\t\tx_i\t\tg'(x)\t\tf(x)\t\tAbs.Error\n");
	do{
	x = xNew;
	xNew = g1(x);
	printf("%13d\t%f\t%f\t%f\t%9f\t%f\n", count, x, xNew,  g1Dash(xNew), f(xNew), error(x,xNew));
	if(g1Dash(xNew) > 1 || g1Dash(xNew) < -1){
		printf("Approximation will not converge!\n");
		break;
	}
	count ++;
	}while (x-xNew > E  || x-xNew < -E);
	printf("Root = %f\n", xNew);
	printf("\n\n");

	printf("g(x) = -(x+6)**(0.5)\n");
	xNew = 1;	
	count = 1;
	printf("Iteration No.\tx_(i-1)\t\tx_i\t\tg'(x)\t\tf(x)\t\tAbs.Error\n");
	do{
	x = xNew;
	xNew = g2(x);
	printf("%13d\t%9f\t%f\t%f\t%9f\t%f\n", count, x, xNew, g2Dash(xNew), f(xNew), error(x,xNew));
	if(g2Dash(xNew) > 1 || g2Dash(xNew) < -1){
		printf("Approximation will not converge!\n");
		break;
	}
	count ++;
	} while (x-xNew > E  || x-xNew < -E);
	printf("Root = %f\n", xNew);
	return 0;
}
