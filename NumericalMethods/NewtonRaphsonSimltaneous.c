#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000005

float f1( float x, float y);
float f2( float x, float y);
float df1x( float x, float y);
float df1y( float x, float y);
float df2x( float x, float y);
float df2y( float x, float y);
float jacobian(float x, float y);



int main(void){
	float x, y, error, max;
	float a, b, dx, dy, jac;
	printf("Enter initial approximation for x and y:\n");
	scanf("%f %f", &x, &y);
	do{
		printf("x: %f;\t dx: %f;\ny: %f;\t dy: %f\n\n", x, dx, y, dy);
		a = f1(x,y);
		b = f2(x,y);
		jac = jacobian(x,y);
		dx = (b*df1y(x,y) - a*df2y(x,y))/jac;
		dy = (a*df2x(x,y) - b*df1x(x,y))/jac;
		x = x + dx;
		y = y + dy;
		printf("x: %f;\t dx: %f;\ny: %f;\t dy: %f;\n\n", x, dx, y, dy);
		
		max = (fabs(dx) > fabs(dy))?fabs(dx):fabs(dy);
		
	}while(max > EPSILON);
	return 0;
}

float f1( float x, float y){
	return (x*x - 2*x - y + 0.5 );
}

float f2( float x, float y){
	return (x*x +4*y*y - 4);
}

float df1x( float x, float y){
	return (2*x - 2);
}

float df1y( float x, float y){
	return (-1);
}

float df2x( float x, float y){
	return (2*x);
}

float df2y( float x, float y){
	return (8*y);
}

float jacobian(float x, float y){
	return (df1x(x,y)*df2y(x,y) - df1y(x,y)*df2x(x,y));
}

