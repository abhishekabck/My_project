# include <stdio.h>
int main(){
	// Initializing both arrays
	int ar1[20], s1, s2, ar2[10], i = 0, temp;
	s1 = sizeof(ar1)/sizeof(ar1[0]);
	s2 = sizeof(ar2)/sizeof(ar2[0]);
	
	// Reading both Arrays
	printf("Enter your desired input in first array:- ");
	for (i = 0; i < s1; i++){
		scanf("%d",&ar1[i]);
	}
	for (i = 0; i < s2; i++){
		scanf("%d",&ar2[i]);
	}
	
	// Sorting first array
	for (i = 0; i < (s1-1); i++){
		for (i = 0; i < (s1-1); i++){
			if (ar1[i] > ar1[i+1]){
				temp = ar1[i];
				ar1[i] = ar1[i+1];
				ar1[i+1] = temp;
			}
		}
	}
	// sorting second array
	for (i = 0; i < (s1-1); i++){
		for (i = 0; i < (s1-1); i++){
			if (ar1[i] > ar1[i+1]){
				temp = ar1[i];
				ar1[i] = ar1[i+1];
				ar1[i+1] = temp;
			}
		}
	}
	
	// Initializing third array 
	int ar3[10+20], j = 0, k = 0;
	i=0;
	// Sorting both arrays and adding sorted elements in third array
	while ((((i < s1) || (j < s2)) && (k< (s1 + s2)))){
		if (ar1[i] > ar2[j]){
			ar3[k] = ar2[j];
			ar3[k+1] = ar1[i];
		}
		else if (ar1[i] < ar2[j]){
			ar3[k] = ar1[i];
			ar3[k+1] = ar2[j];
		}
		else {
			ar3[k] = ar1[i];
			ar3[k+1] = ar2[j];
		}
		i++,j++,k++,k++;
	}
	
	// Printing array third
	for (i = 0; i < (s2 + s1); i++){
		printf("%d ",ar3[i]);
	}
	
}