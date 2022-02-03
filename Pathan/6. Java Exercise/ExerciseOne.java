public class ExerciseOne {

    public static void main(String[] args) {
        System.out.println(checkString("google", "elgoog"));
        System.out.println(checkString("data", "ata"));

    }

    // N
    public static int checkString(String str, String str2) {
        String reverse = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reverse += str.charAt(i);
        }
        // N+ N = 2N
        if (reverse.equalsIgnoreCase(str2)) {
            return 1;
        }
        return 0;
    }

}