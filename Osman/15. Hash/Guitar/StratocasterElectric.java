public class StratocasterElectric extends ElectricGuitar {
    public StratocasterElectric() {
        size = "undefined";
        color = "undefined";
        System.out.println("I am creating quitar type StratocasterElectric");
    }

    public StratocasterElectric(String s, String c) {
        size = s;
        color = c;
        System.out.println("I am creating quitar type StratocasterElectric");
    }
    public String getType(){
        return "Stratocaster Electric";

    }

}
