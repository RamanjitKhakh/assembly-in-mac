#include<stdio.h>

void packArithmetic(float *a, float *b, float *c);

int main(int argc, char **argv){
	float a[8];
	float b[8];
	float c[8];
	int i;
	printf("\nthe size of float is %d\n", sizeof(float));
	a[0] = 1.0;  b[0] = 2.33;
	a[1] = 2.0;  b[1] = 2.33;
	a[2] = 3.0;  b[2] = 2.33;
	a[3] = 4.0;  b[3] = 2.33;
	a[4] = 5.0;  b[4] = 2.33;
	a[5] = 6.0;  b[5] = 2.33;
	a[6] = 7.0;  b[6] = 2.33;
	a[7] = 8.0;  b[7] = 2.33;

	packArithmetic(a,b,c);
	
	for(i = 0; i<8; i++){
		printf("%f\n", c[i]);
	}

	return 0;
}
