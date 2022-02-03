import java.io.*;
import java.util.Random;
import java.util.Scanner;

// Write your code below.
//
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Solution {
    // public static String filepath = System.getenv("OUTPUT_PATH").substring(0,
    // System.getenv("OUTPUT_PATH").lastIndexOf("\\") + 1);
    public static String filepath = "";

    private static String generateString() {
        char[] chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890".toCharArray();
        StringBuilder generatedString = new StringBuilder(20);
        Random random = new Random();
        for (int i = 0; i < 40; i++) {
            char c = chars[random.nextInt(chars.length)];
            generatedString.append(c);
        }
        return generatedString.toString();
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String message = sc.nextLine();

        try {
            EncryptDecryptFile f = new EncryptDecryptFile();

            String encryptFilename = Solution.filepath + "EncryptionFile.txt";
            String generatedString = generateString();
            BufferedWriter writer = new BufferedWriter(new FileWriter(encryptFilename));
            writer.write(generatedString);
            writer.close();

            if (f.readEncryptionFile().equals(generatedString)) {
                f.writeDecryptionFile(message);

                String decryptFilename = Solution.filepath + "DecryptionFile.txt";
                BufferedReader reader = new BufferedReader(new FileReader(decryptFilename));
                String messageFromFile = reader.readLine();
                reader.close();

                System.out.println(messageFromFile);
            }
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }

    }

}

class EncryptDecryptFile {

    public String encrypt(String str) {
        String newstr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            newstr += str.charAt(i);
        }
        return newstr;
    }

    public String decrypt(String str) {
        String newstr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            newstr += str.charAt(i);
        }
        return newstr;
    }

    public void writeDecryptionFile(String message) {
        try {
            String strf = Solution.filepath + "DecryptionFile.txt";
            File myObj = new File(strf);
            if (myObj.createNewFile()) {
                // System.out.println("File created: " + myObj.getName());
            } else {
                // System.out.println("File already exists.");
            }
            FileWriter writer = new FileWriter(strf);
            String m = message;
            writer.write(m);
            writer.close();

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    public String readEncryptionFile() {
        String out = "";
        try {
            String ftr = Solution.filepath + "EncryptionFile.txt";
            FileReader reader = new FileReader(ftr);
            int character;

            while ((character = reader.read()) != -1) {
                out += (char) character;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        String m = out;
        return m;

    }
}
