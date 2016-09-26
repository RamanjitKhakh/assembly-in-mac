//https://github.com/nothings/stb/blob/master/stb_image.h

// Basic usage (see HDR discussion below for HDR usage):
//    int x,y,n;
//    unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
//    // ... process data if not NULL ...
//    // ... x = width, y = height, n = # 8-bit components per pixel ...
//    // ... replace '0' with '1'..'4' to force that many components per pixel
//    // ... but 'n' will always be the number that it would have been if you said 0
//    stbi_image_free(data)


#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
//this line needs to be defined before the include 

#include "stb_image.h"
#include "stb_image_write.h"

void sobel (unsigned char *data, unsigned char* out, long rows, long cols);

int main(int argv, char** argc){

	int x,y,n,i;
	unsigned char *data = stbi_load("./a.jpg", &x, &y, &n, 0);
	unsigned char *final = calloc(x*y, n);
	
	sobel(data, final, y, x);
	/*for(i=0;i<x;i++){
		if(!(i%3)){
			printf("\n");
		}
		printf("%hhx, ", *(data+i));
		printf("%hhx, ", *(final+i));
	}*/
	char *file = "./b.bmp";
 	stbi_write_bmp(file, x, y, n, final);
	return 0;
}
