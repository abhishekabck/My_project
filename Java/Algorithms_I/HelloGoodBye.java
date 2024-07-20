package Java.Algorithms_I;

import java.util.Scanner;

public class HelloGoodBye {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String name1 = sc.nextLine();
        String name2 = sc.nextLine();
        sc.close();
        System.out.println("Hello "+ name1+" and "+name2);
        System.out.println("GoodBye "+name2+" and "+name1);
    }
}
