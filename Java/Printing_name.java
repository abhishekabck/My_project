package Java;
import java.util.Scanner;

public class Printing_name {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String Name = sc.nextLine();
        sc.close();
        System.out.println("Your Name is : " + Name);

    }
}
