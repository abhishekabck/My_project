# include <stdio.h>

// int main(){
// 	int a,b,rem,GCD;
// 	printf("Enter Both numbers one by one:-");
// 	scanf("%d%d",&a,&b);
// 	while (1){
// 		rem = a%b;
// 		if (rem == 0){
// 			GCD = b;
// 			break;
// 		}
// 		else {
// 			a = b;
// 			b = rem;
// 		}
// 	}
// 	printf("GCD of Entered number is :- %d",GCD);
// }

// int b;
// int main(){
//     int a=56;
//     int b;
//     {
//         extern int b;
//         b = 9;
//         a = a-b;
//     }
//     printf("%d-->>%d",a,b);
// }


// int fact(int num){
//     if (num==1){
//         return 1;
//     }
//     return num*fact(num-1);
// }

// int main(){
//     printf("%d",fact(10));
// }


int fib(int n){
    if (n==0 || n==1) return n;
    return (fib(n-1)+fib(n-2));
}

int fact(int n){
    if (n == 1){
        return 1;
    }
    return n*fact(n-1);
}

int GCD(int a, int b){
    if (b==0){
        return a;
    }
    int rem = b%a;
    a = b;
    b = rem;
    return GCD(a,b);

}

int main(){
    int num = 5, a = 45, b = 60;
    printf("Fibonacci Element:- %d", fib(num));
    printf("\nFactorial %d",fact(num));
    printf("\nGCD %d",GCD(a,b));
}