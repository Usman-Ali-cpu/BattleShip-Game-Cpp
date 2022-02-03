import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] strArr = new String[4];
        for (int i = 0; i < 4; i++) {
            System.out.println("Enter String : ");
            strArr[i] = in.nextLine();
            int len = strArr[i].split(" ").length;
            while (len <= 1) {
                System.out.println("String should contain more than one word!");
                strArr[i] = in.nextLine();
                len = strArr[i].split(" ").length;
            }
        }
        System.out.println("Output");
        for (int i = 0; i < 4; i++) {
            String str = reverseWords(strArr[i]);
            System.out.println(str);
        }
        in.close();
    }

    public static String reverseWords(String str) {
        String[] words = str.split(" ");
        String reversedString = "";
        for (int i = words.length - 1; i >= 0; i--) {
            String word = words[i];
            reversedString += word + " ";
        }
        return reversedString;
    }
}