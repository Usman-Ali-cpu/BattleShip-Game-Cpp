import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MovieDriver {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        List<Movie> list = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            Movie m = new Movie();
            getTitle(m);
            getActors(m);
            getGenre(m);
            getMinutes(m);
            list.add(m);
        }
        printMovieList(list);

    }

    public static void getTitle(Movie m) {
        System.out.println("Please enter thr title for the movie");
        String title = in.nextLine();
        while (!m.setTitle(title)) {
            System.out.println("Invalid movie title. It must be between 4 and 50 characters.");
            System.out.println("Please enter thr title for the movie");
            title = in.nextLine();
        }
    }

    public static void getActors(Movie m) {
        String actor;
        String choice;
        do {

            System.out.println("Please enter the actor(s) for " + m.getTitle());
            actor = in.nextLine();
            while (!m.addActor(actor)) {
                System.out.println("You must enter actors in the following format: last, first");
                System.out.println("Please enter the actor(s) for " + m.getTitle());
                actor = in.nextLine();
            }
            System.out.println("Do you want to enter another actor?");
            choice = in.nextLine();
        } while (choice.equalsIgnoreCase("y"));
    }

    public static void getGenre(Movie m) {
        String genre;
        System.out.println("Please enter the genre for " + m.getTitle());
        genre = in.nextLine();
        while (!m.setGenre(genre)) {
            System.out.println("Genre must be Action, Drama, Romance or Science Fiction");
            System.out.println("Please enter the genre for " + m.getTitle());
            genre = in.nextLine();
        }
    }

    public static void getMinutes(Movie m) {
        int minutes;
        System.out.println("Please enter the time for " + m.getTitle());
        minutes = in.nextInt();
        in.nextLine();
        while (!m.setMinutes(minutes)) {
            System.out.println("The running time must be 60 minutes to 210 minutes.");
            System.out.println("Please enter the time for " + m.getTitle());
            minutes = in.nextInt();
            in.nextLine();
        }
    }

    public static void printMovieList(List<Movie> li) {
        for (Movie m : li) {
            System.out.println(m.toString());
        }
    }

}