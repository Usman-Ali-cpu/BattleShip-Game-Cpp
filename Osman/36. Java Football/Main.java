import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String team1;
        String team2;
        String team3;
        int win1, win2, win3;
        System.out.println("What is the name of the first team?");
        team1 = input.nextLine();
        do {
            System.out.println("How many games did the " + team1 + " win?");
            win1 = input.nextInt();
        } while (win1 < 10 && win1 < 0);

        System.out.println("What is the name of the second team?");
        input.nextLine();
        team2 = input.nextLine();
        do {
            System.out.println("How many games did the " + team2 + " win?");
            win2 = input.nextInt();
        } while (win2 < 10 && win2 < 0);

        System.out.println("What is the name of the third team?");
        input.nextLine();
        team3 = input.nextLine();
        do {
            System.out.println("How many games did the " + team3 + " win?");
            win3 = input.nextInt();
        } while (win3 < 10 && win3 < 0);
        input.nextLine();
        if (win1 > win2 && win1 > win3) {
            System.out.println(team1 + " won the league with " + win1 + " wins ");
        } else if (win2 > win1 && win2 > win3) {
            System.out.println(team2 + " won the league with " + win2 + " wins ");
        } else if (win3 > win2 && win3 > win1) {
            System.out.println(team3 + " won the league with " + win3 + " wins ");
        } else {
            int max = win1;
            if (win2 > max) {
                max = win2;
            }
            if (win3 > max) {
                max = win3;
            }
            if (win1 == max && win2 == max) {
                System.out.println(team1 + " and " + team2 + " are tied. Who won the playoff?");
                String won = input.nextLine();
                System.out.println(won + " won the league in a playoff");
                return;
            } else if (win2 == max && win3 == max) {
                System.out.println(team2 + " and " + team3 + " are tied. Who won the playoff?");
                String won = input.nextLine();
                System.out.println(won + " won the league in a playoff");
                return;
            } else if (win1 == max && win3 == max) {
                System.out.println(team1 + " and " + team3 + " are tied. Who won the playoff?");
                String won = input.nextLine();
                System.out.println(won + " won the league in a playoff");
                return;
            }
        }
    }
}