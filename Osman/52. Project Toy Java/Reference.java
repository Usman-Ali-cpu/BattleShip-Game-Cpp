public class Reference {
    String title;
    String Location;
    String Type;

    public Boolean setType(String type) {

        if (type.isBlank()) {
            return false;
        }
        if (type.equalsIgnoreCase("Book")) {
            this.Type = type;
            return true;

        }
        if (type.equalsIgnoreCase("Magazine")) {
            this.Type = type;
            return true;

        }
        if (type.equalsIgnoreCase("Internet")) {
            this.Type = type;
            return true;
        }
        return false;
    }

    public boolean setLocation(String location) {
        if (location.isBlank()) {
            return false;
        }
        Location = location;
        return true;
    }

    public boolean setTitle(String title) {
        if (title.isBlank()) {
            return false;
        }
        this.title = title;
        return true;
    }

    public String getLocation() {
        return Location;
    }

    public String getTitle() {
        return title;
    }

    public String getType() {
        return Type;
    }

    @Override
    public String toString() {
        String str = "Title - " + getTitle() + " Location - " + getLocation() + " Type - " + getType() + "\n";
        return str;
    }
}
