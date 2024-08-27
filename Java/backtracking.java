class backtracking {
    public static void printPermutation(String str, String Perm, int idx) {
        if (str.length() == 0) {
            System.out.println(Perm);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            char currChar = str.charAt(i);
            String newStr = str.substring(0, i) + str.substring(i+1);
            printPermutation(newStr, Perm + currChar, idx+1);
        }
    }
    public static void main(String[] args) {
        String str = "ABC";
        printPermutation(str, "", 0);
    }
}