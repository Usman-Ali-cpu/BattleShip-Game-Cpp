import java.util.Scanner;

public class GameUI {
    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);

        Game[] games = new Game[3];
        for (int i = 0; i < 3; i++) {
            games[i] = getInfo();
        }
        printInfo(games);

    }

    public static Game getInfo() {
        Game g = new Game();
        System.out.println("Please enter the name of your game.");

        String name = in.nextLine();
        while (!g.setName(name)) {
            System.out.println("You must enter a name.\nPlease enter the name of your game.");
            name = in.nextLine();
        }

        System.out.println("Please enter the genre for Red Dead.");
        String genre = in.nextLine();
        while (!g.setGenre(genre)) {
            System.out.println(
                    "Invalid genre. Valid choices are 'Puzzle', 'Shooter', or 'Arcade' \nPlease enter the genre for Red Dead.");
            genre = in.nextLine();
        }

        System.out.println("Please enter the rating for Red Dead.");
        String rating = in.nextLine();
        while (!g.setRating(rating)) {
            System.out.println(
                    "Invalid rating. Valid choices are 'E', 'T', or 'M'\nPlease enter the rating for Red Dead.");
            System.out.println("Please enter the rating for Red Dead.");
            rating = in.nextLine();
        }
        System.out.println("Please enter the number of players for Red Dead.");
        int nop = in.nextInt();
        in.nextLine();
        while (!g.setNop(nop)) {
            System.out.println(
                    "Invalid number of players. This must be between 1 and 10.\nPlease enter the number of players for Red Dead.");
            nop = in.nextInt();
            in.nextLine();
        }
        System.out.println("Please enter the description for Red Dead.");
        String descrip = in.nextLine();
        while (!g.setDescription(descrip)) {
            System.out.println("You must enter a description.");
            System.out.println("Please enter the description for Red Dead.");
            descrip = in.nextLine();
        }
        return g;
    }

    public static void printInfo(Game[] gs) {
        System.out.println();
        for (int i = 0; i < 3; i++) {
            System.out.println(gs[i].toString());
        }
    }

}
