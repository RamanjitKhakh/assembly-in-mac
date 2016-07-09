#include<stdio.h>

void mystart();

int main(int argv, char** argc){
	printf("hello from the C side\n");
	mystart();
	printf("We back to C side!!!\n");
	return(0);
}
