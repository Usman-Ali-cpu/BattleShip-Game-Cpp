public class Score {
    int homeGoal;
    int awayGoal;

    public Score(int homeGoal, int awayGoal) {
        if (homeGoal < 0 || awayGoal < 0) {
            this.homeGoal = 0;
            this.awayGoal = 0;
        }
        this.homeGoal = homeGoal;
        this.awayGoal = awayGoal;
    }

    public int getHomeGoal() {
        return homeGoal;
    }

    public int getAwayGoal() {
        return awayGoal;
    }

}
