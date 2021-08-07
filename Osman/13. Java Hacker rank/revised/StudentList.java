import java.util.ArrayList;

public class StudentList<T> {
    ArrayList<T> listOfStd = new ArrayList<T>();

    public void addElement(T std) {
        listOfStd.add(std);
    }

    public void removeElement(T std) {
        listOfStd.remove(std);
    }

    public T getElement(int i) {
        return listOfStd.get(i);
    }

    public String beginsWith(String s) {
        StudentClass std = new StudentClass();
        String studentData = "";
        for (T st : listOfStd) {
            studentData += st + " ";
        }
        String query = "1," + s;
        String out = std.getQuery(studentData, query);
        return out;
    }

    public String bloodGroupOf(String[] arrblood, String q) {
        StudentClass std = new StudentClass();
        String query = "2,";
        for (int i = 0; i < arrblood.length; i++) {
            if (i < arrblood.length - 1) {
                query += arrblood[i] + " ";
            } else {
                query += arrblood[i] + ",";
            }
        }
        query += q;
        String studentData = "";
        for (T st : listOfStd) {
            studentData += st + " ";
        }
        String out = std.getQuery(studentData, query);
        return out;
    }

    public String thresholdScore(int score) {
        String query = "3," + score;
        String studentData = "";
        for (T st : listOfStd) {
            studentData += st + " ";
        }
        StudentClass std = new StudentClass();
        String out = std.getQuery(studentData, query);
        return out;
    }

}
