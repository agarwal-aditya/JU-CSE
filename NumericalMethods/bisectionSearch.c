// Bisection Search
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0000005
#define f(x) (x*x - x - 6)

//float absError( float root, float iteration){
//	return fabs(root - iteration);
//}

int main(void){
	float a = 0, b = 0, mid = 0;
	printf("\nf(x) = (x*x - x - 6)");
	do{
		printf("\nEnter values of lower limit and upper limit respectively.\n");
		scanf("%f %f", &a, &b);
		if( f(a) * f(b) > 0 ){
			printf("f(%f) = %f;\nf(%f) = %f\n", a, f(a), b, f(b));
			printf("There is no root possible within the two points provided. Please try again.\n");
		}
	}while ( f(a) * f(b) > 0 );

	printf("       a\t|       b\t|   m=(a+b)/2\t|     f(m)\t|\n");
	printf("----------------------------------------------------------------\n");
	do{
		mid = (a+b)*0.5;
		printf("%11f\t|%11f\t|%11f\t|%12f\t|\n", a, b, mid, f(mid));
		if( f(mid) < EPSILON && f(mid) > -EPSILON ) //or  f(mid) == 0  
			break;
		else if ( f(mid) * f(a) > 0 )
			a = mid;
		else
			b = mid;
		
	} while ( fabs(a-b) > EPSILON );
	mid = (a + b)*0.5;
	printf("\n\tThe root is: %f\n", mid);
	return 0;
}
