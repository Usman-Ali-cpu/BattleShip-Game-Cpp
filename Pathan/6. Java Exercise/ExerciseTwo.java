public class ExerciseTwo {
    public static void main(String[] args) {
        System.out.println(getStr(
                "Other enteries include a historic district in charlottesville Virginia cut-flower greenhouse complex"));
    }

    // N/3 + 3^2
    public static String getStr(String line) {
        String str[] = line.split(" "); // array with all words from the line
        int arrl = str.length;
        String getStr = "";
        if (arrl % 3 == 0) {
            for (int i = 0; i < arrl; i += 3) { // loop from 0 to length of array N/3 + 3^2
                String w[] = { str[i], str[i + 1], str[i + 2] }; // array with every three word
                // finding shortest word and storing in array
                for (int k = 0; k < 3; k++) {
                    for (int l = k + 1; l < 3; l++) {
                        String ks = w[k];
                        int kl = ks.length();
                        String ls = w[l];
                        int ll = ls.length();
                        if (kl >= ll) {
                            String temp = w[k];
                            w[k] = w[l];
                            w[l] = temp;
                        }
                    }
                }
                getStr += w[0] + " ";
            }
        }
        return getStr;
    }
}
