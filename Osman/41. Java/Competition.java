import java.time.Year;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Competition {
    class TopFinisher {
        public String initals;
        public String minutes;
    }

    public String competitionName;
    public String distance;
    public int numberOFRunners;
    public Year year;
    public boolean infoInclude;
    public List<TopFinisher> topFinisher = new ArrayList<>();

    public Competition(String raceInfoStr, boolean infoInclude) {
        this.infoInclude = infoInclude;

        StringTokenizer st = new StringTokenizer(raceInfoStr, " ");
        String[] strr = raceInfoStr.split(" ");
        int index;
        for (index = 0; index < strr.length; index++) {
            if (strr[index].equals("5k") || strr[index].equals("10k") || strr[index].equals("15k")) {
                break;
            }
        }

        String name = st.nextToken() + " ";
        String n = "";
        for (int i = 0; i < index; i++) {
            name += n + " ";
            n = st.nextToken();
        }

        // while (!n.equals("5k") || !n.equals("10k") || !n.equals("15k")) {
        // name += n;
        // n = st.nextToken();
        // }

        String dis = n;

        String y = st.nextToken();
        String yea = "";
        for (int i = 1; i < y.length() - 1; i++) {
            yea += y.charAt(i);
        }
        String runner = st.nextToken();
        this.competitionName = name;
        this.distance = dis;
        // System.out.println(runner);
        this.numberOFRunners = Integer.parseInt(runner);
        this.year = Year.parse(yea);

        if (infoInclude) {
            for (int k = 0; k < 3; k++) {

                String top1 = st.nextToken();

                String t1 = "";
                for (int i = 1; i < top1.length() - 1; i++) {
                    t1 += top1.charAt(i);
                }
                StringTokenizer st1 = new StringTokenizer(t1, ":");
                TopFinisher ftop1 = new TopFinisher();
                ftop1.initals = st1.nextToken();
                ftop1.minutes = st1.nextToken();
                topFinisher.add(ftop1);
            }
        }
    }

    public boolean equals(Competition o) {
        if (this == o)
            return true;
        if (o == null)
            return false;
        if (this.getClass() != o.getClass())
            return false;
        Competition com = (Competition) o;
        return year == com.year && (competitionName.equals(com.competitionName) && distance.equals(com.distance));
    }

    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + year.hashCode();
        hash = 31 * hash + (competitionName == null ? 0 : competitionName.hashCode());
        hash = 31 * hash + (distance == null ? 0 : distance.hashCode());
        return hash;
    }

    // Blue Devils Invitational 5k (2009) 124 (a.k.s:32) (b.c:33) (n.w:33)
    public String renderInLogFileFormat() {
        String render = competitionName + " ";
        render += distance + " ";
        render += "(" + year + ")" + " ";
        render += numberOFRunners + " ";
        if (this.infoInclude) {
            for (int i = 0; i < 3; i++) {
                render += "(" + topFinisher.get(i).initals + ":" + topFinisher.get(i).minutes + ") ";
            }
        }
        return render;

    }

    @Override
    public String toString() {
        String result = competitionName + " " + distance + " (" + year + ") ";
        if (!topFinisher.isEmpty()) {
            result = result + "runners: " + numberOFRunners + " top time: " + topFinisher.get(0).minutes + "mins";
        }
        return result;
    }

}