# include <stdio.h>
void main(){
	int a[] = {2,1,4,9,3,7,5,8}, i, j, size, flag;
	size = sizeof(a)/sizeof(a[0]);
	for (i = 0; i<size; i++) {
		flag = 0;
		for (j = i; j<size-1; j++){
			if (a[j+1]>a[i]) {
				printf("%d ----> %d\n",a[i],a[j+1]);
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			printf("%d ----> %d\n",a[i],-1);
		}
	}
}