// Write a program to print only unique elements in the given array
#include <iostream>

using namespace std;
int main() {
	int array[] = {4,5,5,7,0,5,4,3,5,6,8,5,4,7,5};
	int size = sizeof(array)/sizeof(array[0]);
	int ar[size], id = 0, cnt;
	for (int i = 0; i<size; i++){
		cnt = 0;
		for (int j = 0; j<size; j++){
			if (array[i] == array[j]) {
				cnt++;
			}
		}
		if (cnt == 1){
			ar[id] = array[i];
			id++;
		}
	}
	
	// Printing array
	for (int i = 0; i < id; i++) {
		cout<<ar[i]<<", ";
	}
	return 0;
}
