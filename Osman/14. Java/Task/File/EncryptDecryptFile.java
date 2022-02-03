// import java.io.File;
// import java.io.FileReader;
// import java.io.FileWriter;
// import java.io.IOException;

// public class EncryptDecryptFile {

//     public String encrypt(String str) {
//         String newstr = "";
//         for (int i = str.length() - 1; i >= 0; i--) {
//             newstr += str.charAt(i);
//         }
//         return newstr;
//     }

//     public String decrypt(String str) {
//         String newstr = "";
//         for (int i = str.length() - 1; i >= 0; i--) {
//             newstr += str.charAt(i);
//         }
//         return newstr;
//     }

//     public void writeDecryptionFile(String message) {
//         try {
//             String strf = "decryption.txt";
//             File myObj = new File(strf);
//             if (myObj.createNewFile()) {
//                 System.out.println("File created: " + myObj.getName());
//             } else {
//                 System.out.println("File already exists.");
//             }
//             FileWriter writer = new FileWriter(strf);
//             String m = encrypt(message);
//             writer.write(m);
//             writer.close();

//         } catch (IOException e) {
//             System.out.println("An error occurred.");
//             e.printStackTrace();
//         }

//     }

//     public String readEncryptionFile() {
//         String out = "";
//         try {
//             FileReader reader = new FileReader("decryption.txt");
//             int character;

//             while ((character = reader.read()) != -1) {
//                 out += (char) character;
//             }
//             reader.close();
//         } catch (IOException e) {
//             e.printStackTrace();
//         }
//         String m = decrypt(out);
//         return m;

//     }
// }
