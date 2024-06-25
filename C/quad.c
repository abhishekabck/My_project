#include <stdio.h>
#include <math.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    double a,b,c,D;
    scanf("%lf %lf %lf",&a,&b,&c);
    D = b*b - 4*a*c;
    if (D > 0) {
        printf("REAL AND DISTINCT\n");
        printf("%.2lf %.2lf",(-b + sqrt(D))/(2*a),(-b - sqrt(D))/(2*a));
    }
    
    else if (D == 0) {
        printf("REAL AND EQUAL\n");
        printf("%.2lf %.2lf",-b/(2*a), -b/(2*a));
    }
    
    else {
        printf("IMAGINARY ROOTS\n");
        printf("%.2lf+%.2lfi %.2lf-%.2lfi",-b/(2*a),sqrt(-1*D),-b/(2*a),sqrt(-1*D));
    }
    return 0;
}
