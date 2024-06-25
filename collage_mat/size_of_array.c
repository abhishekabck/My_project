# include <stdio.h>

void main(){
	int a[] = {1,2,3,4};
	int n = sizeof(a)/sizeof(a[0]);
	printf("The of size of array is %d",n);
}