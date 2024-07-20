import Java.lib.algs4.StdIn;
import Java.lib.algs4.StdOut;
import Java.lib.algs4.StdRandom;

public class RandomWord {
    public static void main(String[] args){
        String champion = "";
        int count = 0;
        while (!StdIn.isEmpty()) {
            count++;
            String word = StdIn.readString();
            if (Math.random() < 1.0 / count) {
                champion = word;
            }
        }
        System.out.println(champion);
    }
}
