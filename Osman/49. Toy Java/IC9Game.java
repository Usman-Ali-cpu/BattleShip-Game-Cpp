public class IC9Game {
    String name;
    int[] rating;
    int NUM_RATING = 4;

    public IC9Game() {
        rating = new int[NUM_RATING];
        for (int i = 0; i < NUM_RATING; i++) {
            rating[i] = 0;
        }

    }

    public Boolean addrating(int rate, int index) {
        if (index < NUM_RATING && index >= 0) {
            this.rating[index] = rate;
            return true;
        }
        return false;
    }

    public String getAverage() {
        float sum = 0;
        for (int i = 0; i < NUM_RATING; i++) {
            sum += rating[i];
        }
        sum /= 4;
        return String.format("%.3f", sum);
    }

    public String getName() {
        return this.name;
    }

    public boolean setName(String a_name) {
        if (a_name.equals("")) {
            return false;
        }
        this.name = a_name;
        return true;
    }

    public int[] getRatings() {
        return this.rating;
    }

    public Boolean setRating(int[] rates) {
        if (rates.length == rating.length) {
            this.rating = rates;
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String ratingStr = "";
        for (int i = 0; i < NUM_RATING; i++) {
            if (i < (NUM_RATING - 1)) {
                ratingStr += rating[i] + ", ";
            } else {
                ratingStr += rating[i] + ". ";
            }
        }
        return "name = " + this.name + ", " + "ratings = " + ratingStr + "Average rating is: " + getAverage() + ".";
    }

}