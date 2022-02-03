public class ElectricGuitar extends Guitar {
    public ElectricGuitar() {
        size = "undefined";
        color = "undefined";

    }

    public void electicStrum() {
        System.out.println("I am electric strum");
    }

    @Override
    String getType() {
        // TODO Auto-generated method stub
        return null;
    }

}