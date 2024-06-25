/* Write a Java program to accept two numbers from the
 user and calculate sum and product.  */

package Java;
import java.util.Scanner;

public class sample2 {
    public static void main(String[] args){
        int a,b, sum, product;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the First Number: ");
        a = scan.nextInt();
        System.out.print("Enter the Second Number: ");
        b = scan.nextInt();
        scan.close();
        sum = a + b;
        product = a*b;
        System.out.println("Sum = " + sum);
        System.out.println("Product = "+ product );
    }
}
