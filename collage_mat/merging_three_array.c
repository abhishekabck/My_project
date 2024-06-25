# include <stdio.h>

void main(){
	int a[] = {1,4,5,10,2}, b[] = {6,7,8}, c[] = {4,5,6,4,6}, x, y,z, i = 0;
	x = sizeof(a)/sizeof(a[0]);
	y = sizeof(b)/sizeof(b[0]);
	z = sizeof(c)/sizeof(c[0]);
	int d[x+y+z];
	for (i; i<(x+y+z); i++){
		if (i<x) d[i] = a[i];
		else if (i<(x+y) && i>=x) d[i] = b[i-x];
		else d[i] = c[i-(x+y)];
	}
	for (i = 0; i<(x+y+z); i++) printf("%d, ",d[i]);
}