#include<stdio.h>
//1 1 2 3 5 8 13 21
int fibonacci(int i);
int fibonacci2(int v);

int main(void){
	int val;
	
	val = fibonacci(5);
	printf("the value of the assembly fibonacci is %d\n", val);

	val = fibonacci2(5);
	printf("the value of c fibonacci is %d\n", val);
	return 0;
}

int fibonacci2(int b){
	if((b == 0) || (b == 1)){
		return 1;
	}

	return fibonacci2(b-1) + fibonacci2(b-2);
}
