import java.util.Scanner;

public class ValidPalindrome {

    public static boolean isPalindrome(String s) {
        s = s.toLowerCase(); // Convert the input to lowercase
        // Rest of the palindrome checking logic remains the same
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
    

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        scanner.close();
        boolean ans = isPalindrome(s);
        if (ans) {
            System.out.println("Success");
        } else {
            System.out.println("Failure");
        }
    }
}
