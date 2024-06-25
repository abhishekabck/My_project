# include <stdio.h>

void main(){
	int a[] = {1,2,3,8,7,6,5}, flag = 0,mid;
	int low = 0;
	int high = 6;
	while (low <= high){
		mid = (low + high)/2;
		if (a[mid]>a[mid-1] && a[mid]>a[mid+1])
		{
			flag = 1;
			break;
		}
		else if (a[mid]<a[mid+1]){
			low = mid + 1;
		}
		else high = mid - 1;
	}
	if (flag == 1) printf("The Bitonic Point is at %d",mid);
	else printf("The Bitonic POint is Not found");
	
}