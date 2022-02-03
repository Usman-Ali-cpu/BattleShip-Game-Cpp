import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Driver {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter Number of classes : ");
        int noclass = in.nextInt();
        List<Student>[] stArr = new List[noclass];
        for (int i = 0; i < noclass; i++) {
            stArr[i] = new ArrayList<>();
        }
        int numStd = 0;
        for (int i = 0; i < noclass; i++) {
            System.out.print("Enter the number of students in class " + (i + 1) + ": ");
            numStd = in.nextInt();
            System.out.println("Stdudent : " + numStd);
            in.nextLine();
            for (int j = 0; j < numStd; j++) {
                String name = in.nextLine();
                Student st = new Student();
                String[] names = name.split(" ");
                st.setFirstname(names[0]);
                st.setLastname(names[1]);
                String email = generateEmail(names[0], names[1]);
                st.setEmail(email);
                stArr[i].add(st);
            }
        }
        for (int i = 0; i < noclass; i++) {
            System.out.println("For class # " + (i + 1));
            for (int j = 0; j < stArr[i].size(); j++) {
                System.out.print("Enter grades for : " + stArr[i].get(j).getFirstname() + " "
                        + stArr[i].get(j).getLastname() + ": ");
                double grades = in.nextInt();
                in.nextLine();
                stArr[i].get(j).setGrade(grades);
            }
        }
        for (int i = 0; i < noclass; i++) {
            stArr[i] = sort(stArr[i]);
        }
        printData(stArr);

        in.close();

    }

    public static String generateEmail(String firstname, String lastname) {
        String email = firstname.toLowerCase().charAt(0) + lastname.toLowerCase() + "@" + "ritaj.birzeit.edu";
        return email;
    }

    public static void printData(List<Student>[] stArr) {
        for (int i = 0; i < stArr.length; i++) {
            System.out.println("\nFor class # " + (i + 1) + " ->");
            double sum = 0;
            for (int j = 0; j < stArr[i].size(); j++) {
                System.out.println(stArr[i].get(j).toString());
                sum += stArr[i].get(j).getGrade();
            }
            double avr = sum / stArr[i].size();
            System.out.println("AVG of class # " + (i + 1) + ":  " + String.format("%.2f", avr) + "%");
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

    public static boolean checkif(Student st1, Student st2) {
        String alphabet = "abcbdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; i++) {
            if (checkChar(alphabet.charAt(i), st1.getName()) < checkChar(alphabet.charAt(i), st2.getName())) {
                return true;
            } else {
                continue;
            }

        }
        return false;
    }

    public static List<Student> sort(List<Student> st) {
        for (int i = 0; i < st.size(); i++) {

            for (int j = 0; j < i; j++) {
                if (checkif(st.get(i), st.get(j))) {
                    Student temp = st.get(i);
                    st.set(i, st.get(j));
                    st.set(j, temp);
                }
            }
        }
        return st;

    }
}
