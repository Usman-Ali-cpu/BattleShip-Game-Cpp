import java.util.*;

public class League {
    List<Team> teams;

    public League() {
        teams = new ArrayList<Team>();
    }

    public void addGame(Team t) {
        for (Team a_t : teams) {
            if (a_t == t) {
                a_t.addWin();
            }
        }
    }

    public void addTeam(Team t) {
        for (Team a_t : teams) {
            if (a_t.getName().equalsIgnoreCase(t.getName())) {
                return;
            }
        }
        teams.add(t);
    }

    @Override
    public String toString() {
        String str = "";
        for (Team t : teams) {
            str += t.toString() + "\n";
        }
        return str;
    }

    public String orderedToString() {
        for(int i=0; i<teams.size(); i++){
            for(int j =i ; j<teams.size(); j++){
                if(teams[i].getPoint() < teams[j].getPoint()){
                    Team temp = teams[i];
                    teams[i] = teams[j];
                    teams[j] = temp;
                }
            }
        }
        String str = "";
        for (Team t : teams) {
            str += t.toString() + "\n";
        }
        return str;
    }

}
