import java.util.Scanner;

public class StudentTester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Please enter the student's name");
        String name = in.nextLine();
        System.out.println("Please enter class for " + name);
        String stclass = in.nextLine();
        System.out.println("Please enter gpa for " + name);
        double stgpa = in.nextDouble();
        in.nextLine();
        Student std = new Student();
        std.setGpa(stgpa);
        std.setName(name);
        std.setStudent_class(stclass);
        System.out.println(std.toString());
        in.close();

    }

}
