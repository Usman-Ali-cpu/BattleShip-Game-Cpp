public class Game {
    private String name;
    private String genre;
    private String rating;
    private int nop;
    private String description;

    public String getDescription() {
        return description;
    }

    public String getGenre() {
        return genre;
    }

    public String getName() {
        return name;
    }

    public int getNop() {
        return nop;
    }

    public String getRating() {
        return rating;
    }

    public boolean setGenre(String genre) {
        if (genre.isBlank()) {
            return false;
        }
        if (genre.equalsIgnoreCase("Puzzle")) {
            this.genre = genre;
            return true;
        }
        if (genre.equalsIgnoreCase("Shooter")) {
            this.genre = genre;
            return true;
        }
        if (genre.equalsIgnoreCase("Arcade")) {
            this.genre = genre;
            return true;
        }
        return false;

    }

    public boolean setDescription(String description) {
        if (description.isBlank()) {
            return false;
        }
        this.description = description;
        return true;
    }

    public Boolean setName(String name) {
        if (name.isBlank()) {
            return false;
        }
        this.name = name;
        return true;
    }

    public boolean setNop(int nop) {
        if (nop >= 1 && nop <= 10) {
            this.nop = nop;
            return true;
        }
        return false;
    }

    public boolean setRating(String rating) {
        if (rating.isBlank()) {
            return false;
        }
        if (rating.equalsIgnoreCase("M")) {
            this.rating = rating;
            return true;
        }
        if (rating.equalsIgnoreCase("E")) {
            this.rating = rating;
            return true;

        }
        if (rating.equalsIgnoreCase("T")) {
            this.rating = rating;
            return true;

        }
        return false;
    }

    @Override
    public String toString() {
        String str = "Game name = " + getName() + " genre = " + getGenre() + ", rating = " + getRating()
                + ", numPlayers = " + getNop();
        str += "\nDescription = " + getDescription();
        return str;
    }

}