# include<stdio.h>
					//////////////////////////////Brute Force Algorithm///////////////////////////////////////
/*
void main(){
	int a[] = {1,2,5},i , j, size = 4;
	int N = 5,flag;
	for (i = 1; i<N; i++){
		flag = 0;
		for (j = 0; j<size; j++){
			if (a[j] == i){
				flag = 1;
				break;
				}
		}
		if (flag == 0){
			printf("\nMissing No is %d",i);
	}
}
}
*/

void main() {
	int a[] = {1,2,4,5},i;
	int n = 5;
	int n_sum = n*(n+1)/2;
	for (i=0; i<(sizeof(a)/sizeof(a[0])); i++){
		n_sum -= a[i]; 
	}
	printf("Missing Number is %d",n_sum);
}
/*
//Teachers Approach

void main(){
	int a[] = {1,2,4,5},i,missing,size = 4,N=5;
	int sum = 0, arr_sum = 0;
	for (i = 1; i<=N; i++){
		sum = sum + i;
	}
	for (i = 0; i<size; i++){
		arr_sum += a[i];
	}
	missing = sum - arr_sum;
	printf("Missing no is %d",missing);
}
*/