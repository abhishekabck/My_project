// Write a program to to find out first and last occuarance of a given number in a given array
// BinaRY sEARCH

# include <stdio.h>
void main(){
	int a[] = {1,2,2,3,3,4,5}, mid, result;
	int data = 3;
	int low = 0;
	int high = 5;
	while (low<=high){
		mid = (low+high)/2;
		if (a[mid] == data){
			result = mid;
			low = mid + 1;
		}
		else if (a[mid]<data){
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("Last occurace is at %d",result);
}