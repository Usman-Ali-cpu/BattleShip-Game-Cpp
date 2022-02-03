import java.util.Scanner;

public class StudentTester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Student[] arrSt = new Student[2];
        System.out.println("Please enter the student's name");
        String name = in.nextLine();
        System.out.println("Please enter class for " + name);
        String stclass = in.nextLine();
        System.out.println("Please enter gpa for " + name);
        double stgpa = in.nextDouble();
        in.nextLine();

        Student st1 = new Student();
        System.out.println(st1.toString());
        st1.setGpa(stgpa);
        st1.setName(name);
        st1.setStudent_class(stclass);
        System.out.println("Please enter the student's name");
        String name2 = in.nextLine();
        System.out.println("Please enter class for " + name2);
        String stclass2 = in.nextLine();
        System.out.println("Please enter gpa for " + name2);
        double stgpa2 = in.nextDouble();
        in.nextLine();
        Student st2 = new Student();
        st2.setGpa(stgpa2);
        st2.setName(name2);
        st2.setStudent_class(stclass2);
        in.close();
        arrSt[0] = st1;
        arrSt[1] = st2;
        for (int i = 0; i < arrSt.length; i++) {
            System.out.println(arrSt[i].toString());
        }

    }

}
