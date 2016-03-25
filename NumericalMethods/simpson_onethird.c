#include <stdio.h>
#include <math.h>
#define EPSILON 0.00005

float f( float x ){
	return 1.0/(1+x);
}

float simpson(float a, float b, int n){
	float h = (b-a)/n;
	float sum = f(a) + f(b);
	int i;
	for(i = 1; i < n; i++){
		if( i & 1 ){
			sum += 4*f(a + i*h);
		}
		else{
			sum += 2 * f(a + i*h);
		}
	}
	return sum*h/3.0;
}

int main(void){
	float a, b, i1, i2 = 0;
	int n = 2;
	printf("Enter the lower and upper bounds of the integration respectively.\n");
	scanf("%f %f", &a, &b);
	do{
		i1 = i2;
		i2 = simpson(a, b, n);
		n *= 2;
	} while( fabs(i2-i1) >= EPSILON);
	printf("Integration of f(x) = 1/(1+x) from %.2f to %.2f is :\t%f\n", a, b, i2);

	return 0;
}