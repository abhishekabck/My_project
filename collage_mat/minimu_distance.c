# include <stdio.h>
/*       /// Distance between two elements of an array
void main(){
	int a[] = {1,2,2,3,4,5,5}, i,index1, index2,num1 = 2, num2 = 5, dis;
	int size = sizeof(a)/sizeof(a[0]);
	for (i =0; i<size;i++){
		if (a[i] == num1) index1 = i;
		
		else if (a[i] == num2) {
			index2 = i;
			break;
		}
	}
	dis = index2 - index1;
	printf("%d",dis);
}


void main(){				///  Distance between first occurance of two elements of an array
	int a[] = {1,2,2,3,4,5,5}, i,index1, index2,num1 = 2, num2 = 5, dis, flag1 =-1,flag2 = -2;
	int size = sizeof(a)/sizeof(a[0]);
	for (i =0; i<size;i++){
		if (a[i] == num1) {
			if (flag1 == -1){
				index1 = 1;
				flag1 = 1;
			}
		}
		else if (a[i] == num2) {
			if (flag2 == -2) {
				index2 = i;
				flag2 = 1;
			}
		}
	}
	if (flag1 ==1 && flag2 ==1){
		printf("%d",index2 - index1);
	}
	else printf("Element does not found");
	
}


///          Maximum Distance between two elements 
void main(){				///  Distance between first occurance of two elements of an array
	int a[] = {1,2,2,3,4,5,5}, i,index1, index2,num1 = 2, num2 = 5, dis, flag1 =-1,flag2 = -2;
	int size = sizeof(a)/sizeof(a[0]);
	for (i =0; i<size;i++){
		if (a[i] == num1) {
			if (flag1 == -1){
				index1 = i;
				flag1 = 1;
			}
		}
		else if (a[i] == num2) {
			index2 = i;
			flag2 = 1;
		}
	}
	if (flag1 ==1 && flag2 ==1){
		printf("Maximum Distance = %d",index2 - index1);
	}
	else printf("Element does not found");
	
}

*/

///          Minimum Distance between two elements 
void main(){				///  Distance between first occurance of two elements of an array
	int a[] = {1,2,2,3,4,5,5}, i,index1, index2,num1 = 9, num2 = 5, dis, flag1 =-1,flag2 = -2;
	int size = sizeof(a)/sizeof(a[0]);
	for (i =0; i<size;i++){
		if (a[i] == num1) {
			index1 = i;
			flag1 = 1;
		}
		else if (a[i] == num2) {
			if (flag2 == -2) {
				index2 = i;
				flag2 = 1;
			}
		}
	}
	if (flag1 == 1 && flag2 ==1){
		
		printf("Minimum Distance = %d",index2 - index1);
	}
	else printf("Element does not found");
}