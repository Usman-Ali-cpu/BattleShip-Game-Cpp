import java.util.Scanner;

public class StudentTester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Student[] arrSt = new Student[2];
        for (int i = 0; i < arrSt.length; i++) {
            System.out.println("Please enter the student's name");
            String name = in.nextLine();
            System.out.println("Please enter class for " + name);
            String stclass = in.nextLine();
            System.out.println("Please enter gpa for " + name);
            double stgpa = in.nextDouble();
            in.nextLine();
            arrSt[i] = new Student(name, stclass, stgpa);
        }
        in.close();
        for (int i = 0; i < arrSt.length; i++) {
            System.out.println(arrSt[i].toString());
        }

    }

}
