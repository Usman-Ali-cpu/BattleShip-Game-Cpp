import java.util.ArrayList;
import java.util.List;

public class StudentList {
    List<StudentClass> listOfIntergers = new ArrayList<StudentClass>();

    void addElement(StudentClass std) {
        listOfIntergers.add(std);
    }

    void removeElement(StudentClass std) {
        listOfIntergers.remove(std);
    }

    StudentClass getElement(int i) {
        return listOfIntergers.get(i);
    }
    

}
