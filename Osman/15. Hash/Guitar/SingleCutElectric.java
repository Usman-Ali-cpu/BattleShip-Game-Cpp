public class SingleCutElectric extends ElectricGuitar {
    public SingleCutElectric() {
        size = "undefined";
        color = "undefined";
        System.out.println("I am creating quitar type SingleCutElectric");
    }

    public SingleCutElectric(String s, String c) {
        size = s;
        color = c;
        System.out.println("I am creating quitar type SingleCutElectric");
    }
    public String getType(){
        return "SingleCut Electric";

    }
    

}
