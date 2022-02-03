import java.util.Scanner;

public class Question4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // a) Inputs
        String[] names = new String[4];
        int[] absent = new int[4];

        for (int i = 0; i < 4; i++) {
            System.out.print("Enter name of " + i + 1 + " member : ");
            if (i > 0) {

                input.nextLine();
            }
            names[i] = input.nextLine();
            System.out.print("Enter number of absents: ");
            absent[i] = input.nextInt();

        }
        int x = 0;
        int y = 0;
        int z = 0;
        int k = 0;

        // c) Display Result
        for (int i = 0; i < 4; i++) {
            if (absent[i] == 1) {
                System.out.println("Salary of " + names[i] + " is : " + salary(2500, x));
            }
            if (absent[i] == 2) {
                System.out.println("Salary of " + names[i] + " is : " + salary(2500, x, y));
            }
            if (absent[i] == 3) {
                System.out.println("Salary of " + names[i] + " is : " + salary(2500, x, y, z));
            }
            if (absent[i] == 4) {
                System.out.println("Salary of " + names[i] + " is : " + salary(2500, x, y, z, k));
            }
        }
        input.close();

        // d)
        // Logic Behind Code
        /*
         * Program will take input, It will ask for names of four members and choice of
         * memeber which is (1 or 2 or 3 or 4 ) which is unique for each memeber. Then
         * it will call method according to number of absent which is 1 2 3 4 If value
         * in absent is 1, then it will call method salary with two arguments which is
         * overloaded, It will return result of subtract x from basesalary. If absent is
         * 2, then it will call method salary with three arguments which is overloaded,
         * It will return result of subtract sum of x,y from basesalary, if absent is 3
         * then it will call method salary with four arguments which is overloaded, It
         * will return result of subtract sum of x,y,z from basesalary. if absent is 4
         * then it will call method salary with five arguments which is overloaded, It
         * will return result of subtract sum of x,y,z,k from basesalary.
         * 
         */

    }

    // b) Methods

    // 1)
    public static double salary(double basesalary, int x) {
        x = 200;
        double sal = basesalary - x;
        return sal;

    }

    // 2)
    public static double salary(double basesalary, int x, int y) {
        x = 200;
        y = 300;
        double sal = basesalary - (x + y);
        return sal;

    }

    // 3)
    public static double salary(double basesalary, int x, int y, int z) {
        x = 200;
        y = 300;
        z = 400;
        double sal = basesalary - (x + y + z);
        return sal;
    }

    // 4)
    public static double salary(double basesalary, int x, int y, int z, int k) {
        x = 200;
        y = 300;
        z = 400;
        k = 500;
        double sal = basesalary - (x + y + z + k);
        return sal;

    }

}
