import java.lang.annotation.Annotation;
import java.util.ArrayList;
import java.util.List;

public class Zoo {
    String name;
    List<Animal> li;

    public Zoo(String name) {
        this.name = name;
        li = new ArrayList<>();
    }

    boolean addAnimal(Animal a) {
        li.add(a);
        if (li.contains(a)) {
            return true;
        }
        return false;
    }

    int countLoin(double n) {
        int count = 0;
        for (int i = 0; i < li.size(); i++) {
            if (li.get(i).isLoin()) {
                if (li.get(i).calculateFoodCost() <= n) {
                    count++;
                }
            }
        }
        return count;
    }

}
