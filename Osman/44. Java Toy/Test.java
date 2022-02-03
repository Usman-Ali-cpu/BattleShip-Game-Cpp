import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println(
                "Welcome to the Music Recommender. You will be asked to input your name, age, and listening style");
        System.out.println("Based on your inputs, I will select music for you");
        System.out.println("What is your full Name : ");
        String name = input.nextLine();
        while (name.equals("") || !name.contains(" ")) {
            System.out.println("Your name cannot be blank and must be your full name.");
            name = input.nextLine();
        }
        System.out.println(name + " how old you are? ");
        int old = input.nextInt();
        while (old > 100 || old < 0) {
            if (old > 100) {
                System.out.println("Sorry, we don't have a selection for you. Please enter another age.");
            }
            if (old < 0) {
                System.out.println("Sorry, you cannot have a negative age.");
            }
            System.out.println(name + " how old you are? ");
            old = input.nextInt();
        }
        if (old < 5) {
            System.out.println("Play nursery  Rhymes");
            System.out.println("Thank you for using Music Recommender.");
            System.exit(0);
        }

        input.nextLine();
        System.out.println(
                name + ", please enter the genre of music you like to listen to. (Rock, Rap, Country, Jazz, or Swing)");
        String type = input.nextLine();
        while (!type.equals("Rock") && !type.equals("Rap") && !type.equals("Country") && !type.equals("Jazz")
                && !type.equals("Swing")) {
            System.out.println("Your genre must be Rock, Rap, Country Jazz or Swing");
            type = input.nextLine();
        }
        if (type.equals("Rock")) {
            System.out.println("Play Metallica");

        }
        if (type.equals("Rap")) {
            System.out.println("Play Jay-Z");
        }
        if (type.equals("Country")) {
            System.out.println("Play Alabama");
        }
        if (type.equals("Jazz")) {
            System.out.println("Play John Coltrane");
        }
        if (type.equals("Swing")) {
            System.out.println("Play John Coltrane");
        }
        System.out.println("Thank you for using Music Recommender.");
        input.close();
    }

}
