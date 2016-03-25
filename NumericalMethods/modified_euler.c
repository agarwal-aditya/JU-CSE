#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.00005

float dy(float x, float y){		// dy/dx
	return 2*x*x + 2*y;
}

float fx( float x ){		//Given Exact Solution
	return 1.5*exp(2*x) -x*x -x - 0.5;
}

int main(void){
	float x0, x1, y0, y10, y11;	
	float h = 0.1;
	x1 = 0;
	y11 = 1;

	printf("\n    X\t|\tY-computed\t|\tY-Actual\t|\tAbs. Error\t|\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("%f|\t%f\t|\t%f\t|\t%f\t|\n", x1, y11, fx(x1), fabs(y11 - fx(x1)) );	//Since first pt. given

	while(x1 <= 1){
		x0 = x1;
		x1 += h;
		y0 = y11;
		y11 = y0 + h*dy(x0,y0);
		do{
			y10 = y11;
			y11 = y0 + h/2*(dy(x0,y0) + dy(x1,y10));	
		} while( fabs(y10 - y11) >= EPSILON );
		printf("%f|\t%f\t|\t%f\t|\t%f\t|\n", x1, y11, fx(x1), fabs(y11 - fx(x1)) );
	}

}