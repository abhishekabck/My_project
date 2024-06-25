# include <stdio.h>
 // Rotation Code anticlockwise              
void main() {
	int a[] = {1, 2, 3, 4, 5, 6}, i, temp;
	temp = a[5];
	for (i = 4; i>= 0; i--){
		a[i+1] = a[i];
	}
	a[0] = temp;
	for (i = 0; i<6; i++){
		printf("%d ", a[i]);
	}
}