
import java.util.Scanner;

public class Driver {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // scanner for taking input
        System.out.print("Enter Number of classes : ");
        int noclass = in.nextInt(); // input for number of classes
        Student[][] stArr = new Student[noclass][]; // 2d array of type student

        int numStd = 0;
        for (int i = 0; i < noclass; i++) { // loop for each class
            System.out.print("Enter the number of students in class " + (i + 1) + ": ");
            numStd = in.nextInt(); // input number of students in the class
            System.out.println("Stdudent : " + numStd);
            stArr[i] = new Student[numStd]; // initialize array
            in.nextLine();
            for (int j = 0; j < numStd; j++) {
                String name = in.nextLine(); // input name
                Student st = new Student(); // create object of student
                String[] names = name.split(" ");
                st.setFirstname(names[0]); // setting first name
                st.setLastname(names[1]); // setting last name
                String email = generateEmail(names[0], names[1]); // getting email from generator
                st.setEmail(email); // setting email
                stArr[i][j] = st; // adding student object to array
            }
        }
        for (int i = 0; i < noclass; i++) { // loop through each class
            System.out.println("For class # " + (i + 1));
            for (int j = 0; j < stArr[i].length; j++) {
                System.out.print(
                        "Enter grades for : " + stArr[i][j].getFirstname() + " " + stArr[i][j].getLastname() + ": ");
                double grades = in.nextInt(); // input grade for each student in class
                in.nextLine();
                stArr[i][j].setGrade(grades); // setting grade to student
            }
        }
        for (int i = 0; i < noclass; i++) {
            stArr[i] = sort(stArr[i]); // calling sort function
        }
        printData(stArr); // print data of all class

        in.close(); // close input scanner

    }

    public static String generateEmail(String firstname, String lastname) { // it return email after generation
        String email = firstname.toLowerCase().charAt(0) + lastname.toLowerCase() + "@" + "ritaj.birzeit.edu";
        return email;
    }

    // print all the data of each class
    public static void printData(Student[][] stArr) {
        for (int i = 0; i < stArr.length; i++) { // loop for each class
            System.out.println("\nFor class # " + (i + 1) + " ->");
            double sum = 0;
            for (int j = 0; j < stArr[i].length; j++) { // loop for each student
                System.out.println(stArr[i][j].toString());
                sum += stArr[i][j].getGrade();
            }
            double avr = sum / stArr[i].length;
            System.out.println("AVG of class # " + (i + 1) + ":  " + String.format("%.2f", avr) + "%");// printing
                                                                                                       // average
        }
    }

    public static int checkChar(char c, String name) {
        int f = 0;

        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == c) {
                f++;
            }
        }
        return f;

    }

    public static boolean checkif(Student st1, Student st2) { // check if the students need to swap on the basis of
                                                              // alphabets or not
        String alphabet = "abcbdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; i++) { // loop through each character in the alphabets
            if (checkChar(alphabet.charAt(i), st1.getName()) < checkChar(alphabet.charAt(i), st2.getName())) {
                return true; // if number of character is less than other student then return true
            } else {
                continue; // else do nothing
            }

        }
        return false;
    }

    public static Student[] sort(Student[] st) {
        for (int i = 0; i < st.length; i++) {

            for (int j = 0; j < i; j++) {
                if (checkif(st[i], st[j])) {
                    // three step to swaps
                    Student temp = st[i];
                    st[i] = st[j];
                    st[j] = temp;
                }
            }
        }
        return st;

    }
}
