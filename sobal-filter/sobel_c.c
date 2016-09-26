#define I(a,b,c) a[(b)*(cols*3)+(c)]

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
