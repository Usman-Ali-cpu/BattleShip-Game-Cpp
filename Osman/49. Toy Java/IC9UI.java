import java.util.Scanner;

public class IC9UI {
    static Scanner input = new Scanner(System.in);
    static int NUM_GAMES = 3;

    public static void main(String[] args) {
        IC9Game[] gamelist = new IC9Game[NUM_GAMES];
        for (int i = 0; i < NUM_GAMES; i++) {
            gamelist[i] = getInformation();
        }
        printResults(gamelist);

    }

    public static IC9Game getInformation() {
        IC9Game game1 = new IC9Game();
        System.out.println("Please enter the name for this game");
        String gameName1 = input.nextLine();
        while (gameName1.equals("")) {
            System.out.println("Game name cannot be blank");
            System.out.println("Please enter the name for this game");
            gameName1 = input.nextLine();
        }
        game1.setName(gameName1);
        int num;
        int i = 0;
        for (int j = 0; j < 4; j++) {
            System.out.println("Please enter rating " + (j + 1));
            num = input.nextInt();
            while (num > 5 || num < 0) {
                System.out.println("Rating must be between 0 and 5, inclusively.");
                System.out.println("Please enter rating " + (j + 1));
                num = input.nextInt();
            }
            game1.addrating(num, j);
        }
        input.nextLine();
        return game1;
    }

    public static void printResults(IC9Game[] games) {
        for (int i = 0; i < NUM_GAMES; i++) {
            System.out.println(games[i].toString());
        }
    }
}
