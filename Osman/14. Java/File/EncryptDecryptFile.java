import java.util.Random;

public class EncryptDecryptFile {

    public String encrypt(String str) {
        Random random = new Random();
        String newstr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            newstr += str.charAt(i);
        }
        return newstr;
    }

    public String decrypt(String str) {
        String newstr = "";
        Random random = new Random();
        for (int i = str.length() - 1; i >= 0; i--) {
            newstr += str.charAt(i);
        }
        return newstr;
    }

    public void writeDecryptionFile(String message) {
        Scanner sc = new Scanner(System.in);
        try {
            String encryptFilename = "decryption.txt";
            File myObj = new File(encryptFilename);
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
            BufferedWriter writer = new BufferedWriter(new FileWriter(encryptFilename));
            // FileWriter writer = new FileWriter(encryptFilename);
            String m = encrypt(message);
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
            String decryptFilename = "decryption.txt";
            BufferedReader reader = new BufferedReader(new FileReader(decryptFilename));
            FileReader reader = new FileReader(decryptFilename);
            int character;

            while ((character = reader.read()) != -1) {
                out += (char) character;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        String m = decrypt(out);
        return m;

    }
}
