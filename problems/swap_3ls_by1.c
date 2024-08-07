# include <stdio.h>

void swap(int* ptr, int* ptr2){
    int temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}

void cswap(char* ptr, char* ptr2){
    int temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}

int main(){
    int pos[] = {3,5,2,6};
    int hlth[] = {10,10,15,12};
    char dr[] = "RLRL";
    int ps = 4;
    for (int i = 0; i < ps-1; i++){
        for (int j = 0; j<ps-1-i; j++){
            if (pos[j]>pos[j+1]){
                swap(pos+j, pos+j+1);
                swap(hlth+j, hlth+j+1);
                cswap(dr+j,dr+j+1);
            }
        }
    }
    // Stack
    int top = -1;
    char late,pr;
    int stack[ps] = (int*)malloc(ps*sizeof(int));
    for (int i = 0; i < ps; i++){
        if (top == -1){
            late = dr[i];
            // Pushing element
            stack[++top] = hlth[i];
        }
        else if (dr[i] == late){
            pr = late;
            stack[++top] = hlth[i];
        }
        else if (hlth[i] == stack[top]){
            top--;
            late = pr;
            
        }
    }
}