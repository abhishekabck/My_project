# include <stdio.h>
					//linear Search
void main(){
	int i,flag = 0,data = 8;
	int array[6] = {4,5,6,7,9,8};
	for (i = 0; i<6 ; i++)
	{
		if (array[i] == data){
			flag = 1;
			break;
		}
	}
	if (flag == 1){
		printf("Number Found and is at location %d",i);
	}
	else {
		printf("Number not found");
	}
} 