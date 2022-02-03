public class Fish extends Animal {
    String bodyType;

    public Fish(String eyeColor, int weight, int age, String bodyType) {
        super(eyeColor, weight, age);
        this.bodyType = bodyType;
    }

    public String getBodyType() {
        return bodyType;
    }

    public void setBodyType(String bodyType) {
        this.bodyType = bodyType;
    }

    public boolean isLoin() {
        return false;
    }

    public double calculateFoodCost() {
        double cost = age * weight;
        return cost;
    }

}
