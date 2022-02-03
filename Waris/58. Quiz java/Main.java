public class Main {
    public static void main(String[] args) {
        Zoo zoo = new Zoo("Lahore Zoo");
        Animal a = new Fish("Blue", 20, 10, "Sexy");
        Animal b = new Loin("Green", 20, 10);
        Animal c = new Loin("Bo", 10, 10);
        Animal d = new Loin("kd", 20, 10);
        Animal e = new Loin("jdwk", 10, 12);
        zoo.addAnimal(a);
        zoo.addAnimal(b);
        zoo.addAnimal(c);
        zoo.addAnimal(d);
        zoo.addAnimal(e);
        System.out.println("Count of Loin Less or equal to n is : " + zoo.countLoin(300));
    }

}