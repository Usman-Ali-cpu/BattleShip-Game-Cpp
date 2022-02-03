public class Team {
    String name;
    String location;
    int point;

    public Team(String name, String location) {
        this.name = name;
        this.location = location;
        point = 0;
    }

    public void addWin() {
        point += 3;

    }

    public void addDraw() {
        point += 1;

    }

    public String getName() {
        return name;
    }

    public String getLocation() {
        return location;
    }

    public int getPoint() {
        return point;
    }

    @Override
    public String toString() {
        return "<" + getName() + "> from <" + getLocation() + "> currently has <" + getPoint() + " points";
    }

    @Override
    public boolean equals(Object obj) {
        // TODO Auto-generated method stub
        if (((Team) obj).getPoint() == this.getPoint()) {
            return true;
        }
        return false;
    }

}