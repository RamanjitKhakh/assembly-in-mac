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
#define I(a,b,c) a[(b)*(cols*3)+(c)]


void sobel (unsigned char *data, unsigned char* out, long rows, long cols);

void sobel (unsigned char *data, unsigned char* out, long rows, long cols){
	int r, c;
	int gx, gy;
	r = c = gx = gy = 0;
	
	for(r = 1; r < (rows)-1; r++) {
		for(c = 1; c < (cols*3)-1; c++) {
			gx = -I(data, r-1, c-1) + I(data, r-1, c+1) +
			     -2*I(data, r, c-1) + 2*I(data, r, c+1) +
			     -I(data, r+1, c-1) + I(data, r+1, c+1);
			gy = -I(data, r-1, c-1) - 2*I(data, r-1, c) -
			      I(data, r-1, c+1) + I(data, r+1, c-1) +
			      2*I(data, r+1, c) + I(data, r+1, c+1);
			I(out, r, c) = (float)sqrt((float)(gx) * (float)(gx)+
					    (float)(gy) * (float)(gy));
		}
	}
}

int main(int argv, char** argc){

	int x,y,n,i;
	x = 3840;
	y = 2160;
	n = 3;
	
	unsigned char *final = calloc(x*y, n);
	
	unsigned char *data = stbi_load("./a.jpg", &x, &y, &n, 0);
	
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
