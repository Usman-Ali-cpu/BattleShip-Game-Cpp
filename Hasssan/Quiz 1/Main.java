import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        extractInfo("file.txt");

    }

    public static void extractInfo(String filename) {
        try {
            File file = new File(filename); // creates a new file instance
            FileReader fr = new FileReader(file); // reads the file
            BufferedReader br = new BufferedReader(fr); // creates a buffering character input stream
            StringBuffer sb = new StringBuffer(); // constructs a string buffer with no characters
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line); // appends line to string buffer
                sb.append("\n"); // line feed
            }
            fr.close();
            String out = "";

            String[] lines = sb.toString().split("\n");
            String[] output = new String[lines.length];
            int count = 0;
            for (String li : lines) {
                String[] entries = li.split(" ");
                if (entries[0].length() < entries[2].length()) {
                    out = entries[0];
                } else {
                    out = entries[2];
                }
                int sum = 0;
                sum += Integer.parseInt(entries[3]);
                sum += Integer.parseInt(entries[5]);
                sum += Integer.parseInt(entries[7]);
                out += " " + sum;
                output[count] = out;
                count++;
            }
            for (int i = 0; i < output.length; i++) {
                System.out.println(output[i]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static int[] countCharKey(char[][] array, char key) {
        int[] intarray = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            int sum = 0;
            for (int j = 0; j < array[i].length; j++) {
                if (array[i][j] == key) {
                    sum++;
                }

            }
            intarray[i] = sum;
        }
        return intarray;
    }

}
