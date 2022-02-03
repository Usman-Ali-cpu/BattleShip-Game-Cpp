import java.util.Date;

public class Test {

    public static void main(String[] args) {
        Date taken1 = new Date(2020, 9, 1);
        Date due1 = new Date(2020, 10, 1);
        Book b1 = new Book("Attitude is Everything", "34857");
        Loan loan1 = new Loan(taken1, due1, b1);
        Student st = new Student("James", "Clark", "james@gmail", loan1, 2021, true);
        System.out.println(st.toString());
        Date taken = new Date(2020, 9, 1);
        Date due = new Date(2020, 10, 1);
        Book b = new Book("Attitude is Everything", "34857");
        Loan loan = new Loan(taken, due, b);
        Teacher tea = new Teacher("Sir john", "william", "john@gmail.com", loan, 123, "Master");
        System.out.println(tea.toString());

    }

}
