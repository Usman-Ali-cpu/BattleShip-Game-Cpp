import java.util.ArrayList;
import java.util.List;

public class Hobby {
    String name;
    String catagory;
    List<Object> list;

    public Hobby() {
        name = "not set";
        catagory = "not set";
        this.list = new ArrayList<>();
    }

    public boolean setCatagory(String catagory) {
        if (catagory.isBlank()) {
            return false;
        }
        if (catagory.equalsIgnoreCase("Gaming")) {
            this.catagory = catagory;
            return true;
        }
        if (catagory.equalsIgnoreCase("Fishing")) {
            this.catagory = catagory;
            return true;
        }
        if (catagory.equalsIgnoreCase("Sewing")) {
            this.catagory = catagory;
            return true;
        }
        if (catagory.equalsIgnoreCase("Crafting")) {
            this.catagory = catagory;
            return true;
        }
        return false;
    }

    public boolean setName(String name) {
        if (name.isBlank()) {
            return false;
        }
        this.name = name;
        return true;
    }

    public String getCatagory() {

        return catagory;
    }

    public String getName() {
        return name;
    }

    public void addReference(Object ref) {
        list.add(ref);
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        String str = "Hobby: name = " + this.name + ", catagory = " + this.catagory + ".\n";
        for (Object o : this.list) {
            str += o.toString();
        }
        return str;
    }

}