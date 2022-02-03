public class Game {
    Team home;
    Team away;
    Score score;

    public Game(Team home, Team away, Score score) {
        this.home = home;
        this.away = away;
        this.score = score;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        if (score.getAwayGoal() > score.getHomeGoal()) {
            return "<" + home.getName() + "> <" + home.getPoint() + "> - <" + away.getName() + "> <" + away.getName()
                    + "; Result: <" + away.getName() + "> Won;";
        }
        if (score.getAwayGoal() < score.getHomeGoal()) {
            return "<" + home.getName() + "> <" + home.getPoint() + "> - <" + away.getName() + "> <" + home.getName()
                    + "; Result: <" + home.getName() + "> Won;";
        }
        return "<" + home.getName() + "> <" + home.getPoint() + "> - <" + away.getName() + "> <" + home.getName()
                + "; Result: Draw";
    }

}
