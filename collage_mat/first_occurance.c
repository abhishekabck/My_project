// Write a program to to find out first and last occuarance of a given number in a given array
// Linear Search

# include <stdio.h>
void main(){
	int a[] = {1,2,3,3,4,5}, mid, result;
	int data = 2;
	int low = 0;
	int high = 5;
	while (low<=high){
		mid = (low+high)/2;
		if (a[mid] == data){
			result = mid;
			high = mid - 1;
		}
		else if (a[mid]>data){
			high = mid -1;
		}
		else {
			low = mid +1;
		}
	}
	printf("First occurace is at %d",result);
}