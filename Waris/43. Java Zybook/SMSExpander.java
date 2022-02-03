import java.util.Scanner;

public class SMSExpander {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = getText(in);
        System.out.println();
        String result = expandAbbreviation(str);
        System.out.println();
        printExpanded(result);
        // Type your code here.

    }

    public static String getText(Scanner console) {
        System.out.println("Enter the text to decode: ");
        String text = console.nextLine();
        return text;
    }

    public static String expandAbbreviation(String userString) {

        int count = 0;
        if (userString.toLowerCase().contains("bff")) {
            userString = userString.replace("BFF", "best friend forever");
            System.out.println("Replacing \"BFF\" with \"best friend forever\"");
            count++;
        }
        if (userString.toLowerCase().contains("bte")) {
            userString = userString.replace("BTE", "blow the exam");
            System.out.println("Replacing \"BTE\" with \"blow the exam\"");
            count++;
        }

        if (userString.toLowerCase().contains("idk")) {
            userString = userString.replace("IDK", "I don't know");
            System.out.println("Replacing \"IDK\" with \"I don't know\"");
            count++;
        }
        if (userString.toLowerCase().contains("stt")) {
            userString = userString.replace("STT", "spill the tea");
            System.out.println("Replacing \"STT\" with \"spill the tea\"");
            count++;
        }
        if (count < 1) {
            System.out.println("Could not find any SMS abbreviations I know to expand.");
        }
        return userString;

    }

    public static void printExpanded(String result) {
        System.out.println("Expanded: " + result);
    }
}