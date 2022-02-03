public class Main {

    public static void main(String[] args) {
        Game g = new Game();
        String homeTeam, visitorTeam;
        homeTeam = g.getName("home");
        visitorTeam = g.getName("visitor");
        while (g.currentQuarter < 4) {
            g.askQuarter();
            if (g.currentQuarter >= 4) {
                break;
            }
            g.askWinner(homeTeam, visitorTeam);
        }
        int homescore = g.getTotal1();
        int visitorScore = g.getTotal2();
        if (homescore > visitorScore) {
            System.out.println(homeTeam + " defeated " + visitorTeam + " by a score of " + homescore + " to "
                    + visitorScore + ".");
        } else {
            System.out.println(visitorTeam + " defeated " + homeTeam + " by a score of " + visitorScore + " to "
                    + homescore + ".");

        }

    }

}
