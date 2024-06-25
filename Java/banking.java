package Java;


import java.util.*;

public class banking {

    
    public static class storage{
            int A_no = 746764687;
            String name;
            String M_no;
            int Age;
            String Gender;
            int ammount = 0;
    }

    public static int handler(){
        System.out.print("Menu:-\n1.Ammount\n2.Withdraw\n3.Deposite\n4.Exit\nEnter Your Choice:-");
        Scanner scan2 = new Scanner(System.in);
        int choice = scan2.nextInt();
        storage s1 = new storage();
        if (choice == 1){
            System.out.println("Your Account Balance = " + s1.ammount);
            scan2.close();
        }
        else if (choice == 2){
            System.out.print("Enter Withdrawal Ammount: ");
            int amt = scan2.nextInt();
            if (amt>s1.ammount) System.out.println("Insufficient Ammount..");
            else {
                s1.ammount = s1.ammount - amt;
                System.out.println("Ammount Withdrwal SuccessFul\nRemaining Ammount:-"+s1.ammount);
            }
            scan2.close();
        }
        
        else if (choice == 3){
            System.out.print("Enter the Ammout to be Deposited: ");
            int amt = scan2.nextInt();
            s1.ammount += amt;
            System.out.println("Ammount Deposited Successfully..");
            scan2.close();
        }
        
        
        return 1;
    }


    public static void main(){
        System.out.println("\t\tWelcome to Union Bank\nThere is no prior Data Exist --> Please Enter Create Your Data:-");
        storage s1 = new storage();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Your Name:- ");
        s1.name = scan.nextLine();
        System.out.print("Enter Your Number:- ");
        s1.M_no = scan.nextLine();
        System.out.print("Genders: \n1.Male\n2.Female\n3.Other\nPlease Select Your Gender:- ");
        int ch = scan.nextInt();
        if (ch == 1){
            s1.Gender = "Male";
        }
        else if (ch == 2){
            s1.Gender = "Female";
        }
        else s1.Gender = "Other";
        System.out.print("Enter Your Age:- ");
        s1.Age = scan.nextInt();
        scan.close();
        System.out.println("Account Creation Successful..");
        while (true){
            if (handler() == 0){
                break;
            }
        
        }
    }
}
