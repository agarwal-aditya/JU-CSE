#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(void){
	int i, j, n;
	printf("Enter the number of given values in the table:\t");
	scanf("%d", &n);
	
	float x[n], y[n], l[n], z,fz, c;

	printf("Enter the x_i and f(x_i) values, one at a time.\n");
	for(i=0;i<n;i++)
		scanf("%f %f", &x[i], &y[i]);
	
	printf("Enter the value of x for which value has to be interpolated.\n");
	scanf("%f", &z);
	
	for(i = 0; i < n; i++){
		l[i] = 1;
		for(j=0;j<n; j++){
			if(i!=j)
				l[i] *= (z - x[j])/(x[i] - x[j]);
		}
	}
	fz = 0;
	for(i = 0;i<n;i++)
		fz += y[i]*l[i];
	
	printf("f(%f) = %f\n", z, fz);

	return  0;
}	