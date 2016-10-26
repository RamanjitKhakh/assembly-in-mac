#include<stdio.h>

void arthimeticAvx(double a, double b, double *c);


int main(int argc, char** argv){
	double a, b;
	double c[8];
	int i;
	a = 1.23;
	b = 23.112;
	c[0] = 111.0;	
	arthimeticAvx(a,b,c);
	
	for(i = 0; i < 8; i++){
		printf("\n%lf\n", c[i]);
	}

	return 0;
}
