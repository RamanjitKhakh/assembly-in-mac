#include<stdio.h>

void arthimeticAvx(double a, double b, double *c);


int main(int argc, char** argv){
	double a, b;
	double c[8];
	char *names[8] = {
		"vaddsd",
		"vsubsd",
		"vmulsd",
		"vdivsd",
		"vminsd",
		"vmaxsd",
		"vsqrtsd of a",
		"fabs b"
	};
	int i;
	a = 1.23;
	b = 23.112;
	c[0] = 111.0;	
	arthimeticAvx(a,b,c);
	printf("floating point arthimetic\n");
	printf("a:%lf\n", a);
	printf("b:%lf\n", b);
	
	for(i = 0; i < 8; i++){
		printf("%s : %lf\n",names[i], c[i]);
	}

	return 0;
}
