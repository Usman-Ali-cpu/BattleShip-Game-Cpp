import java.util.Scanner;

public class Question3b {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String[] names = new String[5];
        int[] marks = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter name of " + (i + 1) + " student : ");
            if (i > 0) {
                input.nextLine();
            }
            names[i] = input.nextLine();
            System.out.print("Enter Marks: ");
            marks[i] = input.nextInt();
        }

        displayResult(names, marks);
        input.close();
    }

    public static void displayResult(String[] names, int[] marks) {
        for (int i = 0; i < 5; i++) {
            String grade;

            if (marks[i] <= 100 && marks[i] >= 80) {
                grade = "A";
                System.out.println("Grade of " + names[i] + " is : " + grade);
            } else if (marks[i] <= 79 && marks[i] >= 75) {
                grade = "B+";
                System.out.println("Grade of " + names[i] + " is : " + grade);
            } else if (marks[i] <= 74 && marks[i] >= 70) {
                grade = "B";
                System.out.println("Grade of " + names[i] + " is : " + grade);
            } else if (marks[i] <= 69 && marks[i] >= 65) {
                grade = "C+";
                System.out.println("Grade of " + names[i] + " is : " + grade);
            } else if (marks[i] <= 64 && marks[i] >= 60) {
                grade = "C";
                System.out.println("Grade of " + names[i] + " is : " + grade);
            } else {
                grade = "resit";
                System.out.println("Student " + names[i] + " is marked for " + grade);
            }

        }

    }

}
