import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Main program input name of two students and it will add 3 quizes score to
        // each student scores and
        // then print name od students and the averages of thier quizes
        String name1 = "John Williamson"; // first student name
        String name2 = "Alast Cock"; // second student name
        QuizCalculator student1 = new QuizCalculator(name1); // call object for first student
        QuizCalculator student2 = new QuizCalculator(name2); // call object for second student
        student1.addScore(70); // add score of first Quiz
        student1.addScore(85); // add score of Second Quiz
        student1.addScore(90); // add score of third Quiz

        student2.addScore(65); // add score of first Quiz
        student2.addScore(75); // add score of Second Quiz
        student2.addScore(80); // add score of third Quiz
        System.out.println(student1.toString()); // it will print string from to string having frist student name and
                                                 // averages
                                                 // of 3 quizes
        System.out.println(student2.toString()); // it will print string from to string having second student name and
                                                 // averages
                                                 // of 3 quizes

    }

}
