import java.util.Scanner;

public class StudentTester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Student st = new Student();
        System.out.println("Please enter the student's name");
        String name = in.nextLine();
        System.out.println("Please enter class for " + name);
        String stclass = in.nextLine();
        System.out.println("Please enter gpa for " + name);
        double stgpa = in.nextDouble();
        st.setGpa(stgpa);
        st.setName(name);
        st.setStudent_class(stclass);
        System.out.println(st.toString());
        in.close();
    }

}
