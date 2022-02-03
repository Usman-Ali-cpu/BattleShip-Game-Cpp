public class Loin extends Animal {

    public Loin(String eyeColor, int weight, int age) {
        super(eyeColor, weight, age);
    }

    public double calculateFoodCost() {
        return age * weight;
    }

    public boolean isLoin() {
        return true;
    }

}
