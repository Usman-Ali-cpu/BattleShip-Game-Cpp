import java.util.ArrayList;
import java.util.List;

public class ScoreList<T extends Number> {
    ArrayList<Number> listOfStd = new ArrayList<Number>();

    public void addElement(Number std) {
        listOfStd.add(std);
    }

    public void removeElement(Number std) {
        listOfStd.remove(std);
    }

    public Number getElement(int i) {
        return listOfStd.get(i);
    }

    public double averageValues() {
        String query = "4";
        String studentData = "";
        for (Number st : listOfStd) {
            studentData += st + " ";
        }
        StudentClass std = new StudentClass();
        String out = std.getQuery(studentData, query);
        double re = Double.parseDouble(out);
        return re;
    }

    // @Override
    public int intValue() {

        // TODO Auto-generated method stub
        return 0;
    }

    // @Override
    public long longValue() {
        // TODO Auto-generated method stub
        return 0;
    }

    // @Override
    public float floatValue() {
        // TODO Auto-generated method stub
        return 0;
    }

    // @Override
    public double doubleValue() {
        // TODO Auto-generated method stub
        return 0;
    }

}
