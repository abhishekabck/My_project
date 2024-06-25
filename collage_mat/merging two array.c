# include <stdio.h>

void main(){
	int a[] = {1,4,5,10,2}, b[] = {6,7,8}, x, y, i = 0;
	x = sizeof(a)/sizeof(a[0]);
	y = sizeof(b)/sizeof(b[0]);
	int c[x+y];
	for (i; i<(x+y); i++){
		if (i<x) c[i] = a[i];
		else c[i] = b[i-x];
	}
	for (i = 0; i<(x+y); i++) printf("%d, ",c[i]);
}