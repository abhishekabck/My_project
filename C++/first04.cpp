// write a program to find out number of occurances of a number present in a array
# include <iostream>
# include <map>

using namespace std;

void withmap() {
	int array[] = {4,5,5,7,0,5,4,3,5,6,8,5,4,7,5};
	map<int, int> m;
	int s = sizeof(array)/sizeof(array[0]);
	for (int i = 0; i<s; i++) {
		m[array[i]]++;
	}
	
	// Frequency of elements are
	for (auto it:m) {
		cout<<it.first<<"  ->>  "<<it.second<<endl;
	}
}

void withoutmap() {
	int array[] = {4,5,5,7,0,5,4,3,5,6,8,5,4,7,5};
	int s = sizeof(array)/sizeof(array[0]);
	int freq[10] = {0};
	for (int i = 0; i<s; i++){
		freq[array[i]]++;
	}
		// Frequency of elements are
	for (int i = 0; i<10; i++){
		if (freq[i] != 0){
			cout<<i<<" --> "<<freq[i]<<endl;
		}
	}
}

int main(){
	withmap();
	withoutmap();
	return 0;
}
