import java.util.ArrayList;

public class Movie {
    String title;
    String genre;
    int minutes;
    ArrayList<String> actors;

    public Movie() {
        title = "Not given";
        genre = "None";
        minutes = 0;
        actors = new ArrayList<>();
    }

    public Movie(String title, String genre, int min) {
        this.title = title;
        this.genre = genre;
        this.minutes = min;
        actors = new ArrayList<>();
    }

    public void setActors(ArrayList<String> actors) {
        this.actors = actors;
    }

    public boolean setGenre(String genre) {
        if (genre.equalsIgnoreCase("action")) {
            this.genre = genre;
            return true;
        }
        if (genre.equalsIgnoreCase("drama")) {
            this.genre = genre;
            return true;
        }
        if (genre.equalsIgnoreCase("romance")) {
            this.genre = genre;
            return true;
        }
        if (genre.equalsIgnoreCase("science fiction")) {
            this.genre = genre;
            return true;
        }
        return false;
    }

    public boolean setMinutes(int minutes) {
        if (minutes >= 60 && minutes <= 210) {
            this.minutes = minutes;
            return true;

        }
        return false;
    }

    public boolean addActor(String actor) {

        String[] arrStr = actor.split(" ");

        for (String s : this.actors) {
            if (s.equalsIgnoreCase(actor)) {
                return false;
            }
        }
        if (arrStr.length != 2) {
            return false;
        }
        int flen = arrStr[0].length() - 1;
        if (arrStr[0].charAt(flen) != ',') {
            return false;

        }
        actors.add(actor);
        return true;
    }

    public boolean setTitle(String title) {
        if (title.equals("") || title.equals(" ")) {
            return true;
        }
        if (title.length() < 4 || title.length() > 50) {
            return false;
        }
        this.title = title;
        return true;
    }

    public ArrayList<String> getActors() {
        return actors;
    }

    public String getGenre() {
        return genre;
    }

    public int getMinutes() {
        return minutes;
    }

    public String getTitle() {
        return title;
    }

    @Override
    public String toString() {
        String str = "Title = " + title + "\n";
        str += "Actors:\n";
        for (int i = 0; i < actors.size(); i++) {
            str += "\t" + actors.get(i) + "\n";
        }
        str += "Genre = " + this.genre + "\n";
        str += "Minutes = " + this.minutes + "\n";

        return str;
    }

}