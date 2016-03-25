#include <stdio.h>
#include <math.h>
#define f(x) (x*x-x-6)
#define EPSILON 0.0000005

int main(void){
	float a, b, c = 0, cOld;
	FILE *fp = fopen("regula.txt", "w");
	printf("Enter a and b:\n");
	scanf("%f %f", &a, &b);
	while( f(a) * f(b) > 0){
		printf("Enter different a and b:\n");
		scanf("%f %f", &a, &b);
	}
	printf("  a\t\t  f(a)\t\t  b\t\t  f(b)\t\t  c\t\t   f(c)\t\t  error\n");
	do{	
		cOld = c;
		c = ((b*f(a)) - (a*f(b)))/( f(a)-f(b) );
		fprintf(fp,"%f %f\n", a, f(a));
		fprintf(fp, "%f %f\n\n", b, f(b));
		printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",a, f(a), b, f(b), c, f(c), (float)fabs(c-cOld) );
		if (f(c) < EPSILON && f(c)>-EPSILON ){
			break;
		}
		if( f(c) * f(a) < 0 )
			b = c;
		else
			a = c;
	}while( (c-cOld) > EPSILON || (c-cOld) < -EPSILON );
	printf("\tRoot:%f\n", c);
	return 0;
}
