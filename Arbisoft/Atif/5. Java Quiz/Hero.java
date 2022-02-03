public class Hero {

    private String name;
    private int age;

    Hero(String n, int a){
        this.name = n;
        this.age = a;
    }
    public int getAge() {
        return age;
    }
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "Hero {Name : " + this.name + ", Age : " + this.getAge() + " }; ";
    }
}
