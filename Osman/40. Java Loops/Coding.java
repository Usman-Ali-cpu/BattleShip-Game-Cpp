public class Coding {

    public static void main(String[] args) {
        // Given a string, return true if the first instance of "x" in the string is
        // immediately followed by another "x".
        // "******** DoubleX ********");
        doubleX("axxbb");
        doubleX("axaxax");
        doubleX("xxxxx");
        // System.out.println(doubleX("xaxxx"));
        // "********** ****** *********\n");

        // Given a string, return a version where all the "x" have been removed. Except
        // an "x" at the very start or end should not be removed.
        // "********* StringX ***********");
        stringX("xxHxix");
        stringX("abxxxcd");
        stringX("xabxxxcdx");
        // System.out.println(stringX(""));
        // "********** ******* *********\n";

        // Suppose the string "yak" is unlucky. Given a string, return a version where
        // all the "yak" are removed, but the "a" can be any char. The "yak" strings
        // will not overlap.
        // "********* StringYak *********";
        // stringYak("Yakpak");
        // stringYak("pakyak");
        // stringYak("yak123ya");
        System.out.println(stringYak("pakyak"));

        // "********** ******** *********\n";

        // Given 2 strings, a and b, return the number of the positions where they
        // contain the same length 2 substring. So "xxcaazz" and "xxbaaz" yields 3,
        // since the "xx", "aa", and "az" substrings appear in the same place in both
        // strings
        // "********* StringMatch **********";
        stringMatch("xxcaazz", "xxbaaz");
        stringMatch("abc", "abc");
        stringMatch("abc", "axc");
        // "********** ********* *********\n";

        // count the number of "xx" in the given string. We'll say that overlapping is
        // allowed, so "xxx" contains 2 "xx".
        // "********** CountXX ************";
        countXX("abcxx");
        countXX("xxx");
        countXX("xxxx");
        // S// ystem.out.println(countXX(""));
        // "********* ********* *********\n";

        // Given a string, return a string made of the chars at indexes 0,1, 4,5, 8,9
        // ... so "kittens" yields "kien".
        // "********** AltPairs **********";
        // System.out.println(altPairs("kitten"));
        // System.out.println(altPairs("Chocolate"));
        // System.out.println(altPairs("CodingHorror"));
        // System.out.println(altPairs("yak"));
        // "********** ********* *********";

    }

    public static boolean doubleX(String s) {
        ///int i = 0;
        int index = s.indexOf("x", 0);
        if(index< s.length()){
            if (s.charAt(index + 1) == 'x') {
                return true;
            }
        }
        return false;
    }

    public static String stringX(String s) {
        String x = "";
        int i = 1;
        if (s.isEmpty()) {
            return "";
        }
        x += s.charAt(0);

        if (s.length() <= 1) {
            return x;
        }
        while (i < s.length() - 1) {
            if (s.charAt(i) != 'x') {
                x += s.charAt(i);
            }
            i++;
        }
        x += s.charAt(s.length() - 1);
        return x;
    }

    public static String stringYak(String str) {
        int i = 0;
        String y = "";
        StringBuilder s = new StringBuilder(str);
        while (i < s.length() - 3) {
            String x = s.substring(i, i + 3);
            if (x.equals("yak") || x.equals("YAK") || x.equals("Yak")) {
                s.delete(i, i + 3);
            }
            i++;
        }
        if (s.length() >= 3) {
            String sub = s.substring(s.length() - 3, s.length());
            if (sub.equals("yak") || sub.equals("YAK") || sub.equals("Yak")) {
                s.delete(s.length() - 3, s.length());
            }

        }

        return s.toString();
    }

    public static int stringMatch(String x, String y) {
        int length = x.length();
        if (y.length() < length) {
            length = y.length();
        }
        int count = 0;
        int i = 0;
        while (i < length - 1) {
            if (x.subSequence(i, i + 2).toString().equals(y.subSequence(i, i + 2).toString())) {
                count++;
            }
            i++;
        }
        return count;
    }

    public static int countXX(String x) {
        if (x.isEmpty()) {
            return 0;
        }
        int count = 0;
        int i = 0;

        do {
            if (x.subSequence(i, i + 2).toString().equals("xx")) {
                count++;
            }
            i++;
        } while (i < x.length() - 1);

        return count;
    }

    public static String altPairs(String s) {
        String x = "";
        int i = 0;
        while (i < s.length() - 1) {
            x += s.substring(i, i + 2);
            i += 4;
        }
        if (s.length() % 4 == 1) {
            x += s.charAt(s.length() - 1);
        }
        return x;

    }

}