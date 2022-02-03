public class Game {
    int players;
    String genre;
    String name;

    public Game() {
        this.genre = "";
        this.name = "";
        this.players = 0;
    }

    public Game(int p, String gen, String name) {
        this.genre = gen;
        this.name = name;
        this.players = p;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public void setTitle(String name) {
        this.name = name;
    }

    public void setPlayers(int players) {
        this.players = players;
    }

    public String getGenre() {
        return genre;
    }

    public String getTitle() {
        return name;
    }

    public int getPlayers() {
        return players;
    }

    public void play() {
        System.out.println("Playing Game");
    }

    public void play(int n) {
        System.out.println("Playing with my " + n + " friends!");
    }

    @Override
    public String toString() {

        return "{Title : " + getTitle() + ", Genre: " + getGenre() + ", Players: " + getPlayers() + "}";
    }

    public void print() {
        System.out.println("Game Title : " + getTitle());
        System.out.println("Game Genre : " + getGenre());
        System.out.println("No. of Players : " + getPlayers() + "\n");
    }

}