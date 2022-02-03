import java.util.*;

public class Array {
    public static void main(String[] args) {

    }

    public static String getMostCommon(Object[] arr) {
        String[] stringArray = Arrays.copyOf(arr, arr.length, String[].class);

        int occur = 0;
        int max = 0;
        String str = "";
        for (int i = 0; i < stringArray.length; i++) {
            String s = stringArray[i];
            for (int j = 0; j < stringArray.length; j++) {
                if (s.equalsIgnoreCase(stringArray[i])) {
                    occur++;

                }
            }
            if (occur > max) {
                max = occur;
                str = s;
            }
            if (occur == max) {
                str = "it's a tie";
            }
            occur = 0;
        }
        return str;
    }

    class Pair<T1, T2> {
        private final T1 key;
        private final T2 value;

        public Pair(T1 first, T2 second) {
            this.key = first;
            this.value = second;
        }

        public T1 getKey() {
            return key;
        }

        public T2 getValue() {
            return value;
        }
    }

    public static Pair<Integer, Integer> chkPair(int A[], int x) {
        int size = A.length;
        Pair<Integer, Integer> pair = new Pair<Integer, Integer>(0, 0);
        for (int i = 0; i < (size - 1); i++) {
            for (int j = (i + 1); j < size; j++) {
                if (A[i] * A[j] == x) {
                    pair = new Pair(A[i], A[j]);
                }
            }
        }
        return pair;
    }

}