package Java;
// import java.util.Scanner;

import java.io.StringBufferInputStream;

public class string_ops{
    public static void main(String[] args){
        /*
         * 1. String
            -->String is an immutable class which means a constant and cannot be changed once created 
            and if wish to change , we need to create an new object and even the functionality it provides 
            like toupper, tolower, etc all these return a new object , its not modify the original object.
            It is automatically thread safe.
            :::: String Declaration ::::
            Syntax -->
            String str= "geeks";
                    or
            String str= new String("geeks")
        */
        // 1.Using String Literal
        String s1 = "Hello";
        System.out.println("Using Literal String is :: " + s1);
        /*
         * 2.Using new Keyword
         * String s = new String(“Welcome”);
        In such a case, JVM will create a new string object in normal (non-pool) heap memory 
        and the literal “Welcome” will be placed in the string constant pool. 
        The variable s will refer to the object in the heap (non-pool)
         */
        String s2 = new String("hello");
        System.out.println("Using new varial, String is :: " + s2);

        /*
         * 2. StringBuffer
            StringBuffer is a peer class of String, it is mutable in nature and it is thread safe class ,
            we can use it when we have multi threaded environment and shared object of string buffer i.e,
            used by mutiple thread. As it is thread safe so there is extra overhead,
            so it is mainly used for multithreaded program.
            Syntax:     StringBuffer demoString = new StringBuffer("GeeksforGeeks");
         */
        StringBuffer demostring = new StringBuffer("THis is String Buffer __Mutable__");
        System.out.println(demostring);

    }
}