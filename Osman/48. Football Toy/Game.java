import java.util.Scanner;

public class Game {
    final int numQuarter = 4;
    public int currentQuarter;
    public int[] scores1;
    public int[] scores2;
    Scanner in;

    public Game() {
        scores1 = new int[numQuarter];
        scores2 = new int[numQuarter];
        in = new Scanner(System.in);
        currentQuarter = 0;
    }

    public Boolean askQuarter() {
        System.out.println(
                "You are currently in quarter" + (currentQuarter + 1) + ". Do you want to change the quarter? (Y/N)");
        String str = in.nextLine();
        if (str.equalsIgnoreCase("Y")) {
            currentQuarter++;
            return true;
        }
        return false;
    }

    public String askWinner(String t1, String t2) {
        System.out.println("Which team scored? (" + t1 + " or " + t2 + ")");
        String str = in.nextLine();
        while (!str.equalsIgnoreCase(t1) && !str.equalsIgnoreCase(t2)) {
            System.out.println("You must enter either " + t1 + " or " + t2 + ".");
            System.out.println("Which team scored? (" + t1 + " or " + t2 + ")");
            str = in.nextLine();
        }
        if (str.equalsIgnoreCase(t1)) {
            System.out.println("Please enter the score for " + t1);
            int score = in.nextInt();
            in.nextLine();
            while (score != 1 && score != 2 && score != 3 && score != 6) {
                System.out.println("Invalid score. You must enter a 1, 2, 3 or 6 for the socre.");
                System.out.println("Please enter the score for " + t1);
                score = in.nextInt();
                in.nextLine();

            }
            if (score == 1) {
                if (currentQuarter > 1) {
                    if (scores1[currentQuarter - 1] != 6) {
                        System.out.println("You can only kick an extra point after you score a touchdown.");
                        System.out.println("Please enter the score for " + t1);
                        score = in.nextInt();
                        in.nextLine();
                    }
                }
                if ((currentQuarter + 1) == 1) {
                    System.out.println("You can only kick an extra point after you score a touchdown.");
                    System.out.println("Please enter the score for " + t1);
                    score = in.nextInt();
                    in.nextLine();
                }
            }
            scores1[currentQuarter] = score;
            return t1;
        }
        System.out.println("Please enter the score for " + t2);
        int score = in.nextInt();
        in.nextLine();
        while (score != 1 && score != 2 && score != 3 && score != 6) {
            System.out.println("Invalid score. You must enter a 1, 2, 3 or 6 for the socre.");
            System.out.println("Please enter the score for " + t2);
            score = in.nextInt();
            in.nextLine();
        }
        if (score == 1) {
            if (currentQuarter > 1) {
                if (scores1[currentQuarter - 1] != 6) {
                    System.out.println("You can only kick an extra point after you score a touchdown.");
                    System.out.println("Please enter the score for " + t2);
                    score = in.nextInt();
                    in.nextLine();
                }
            }
            if ((currentQuarter + 1) == 1) {
                System.out.println("You can only kick an extra point after you score a touchdown.");
                System.out.println("Please enter the score for " + t2);
                score = in.nextInt();
                in.nextLine();
            }
        }
        scores2[currentQuarter] = score;
        return t2;
    }

    public String getName(String team) {
        System.out.println("Please enter the name for the " + team + " team.");
        String name = in.nextLine();
        while (name.equals("")) {
            System.out.println("You must enter a name for the home team.");
            System.out.println("Please enter the name for the " + team + " team.");
            name = in.nextLine();
        }
        return name;
    }

    public int getTotal1() {
        int sum = 6;
        for (int i = 0; i < numQuarter; i++) {
            sum += scores1[i];
        }
        return sum;
    }

    public int getTotal2() {
        int sum = 0;
        for (int i = 0; i < numQuarter; i++) {
            sum += scores2[i];
        }
        return sum;
    }

}