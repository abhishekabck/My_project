# include <stdio.h>
int  main(){
	int array[] = {10,12,9,8,14,7}, i,temp,j,cnt = 0;
	int size = sizeof(array)/sizeof(array[1]);   //  a += b -= a;
	for (j = 0; j<size; j++){
		for (i = 0; i<size-1; i++){
			if (i%2 == 0 && array[i]<array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] =temp;
				cnt ++;
			}
			else if (i%2 == 1 && array[i]>array[i+1]);
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] =temp;
				cnt++;
		}
		if (cnt == size -1) break;
	}
		
	
	for (i = 0; i<size;i++) printf("%d ",array[i]);
}
