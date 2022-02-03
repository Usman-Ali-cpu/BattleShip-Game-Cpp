public class FlamencoAcoustic extends AcousticGuitar {

    public FlamencoAcoustic() {
        size = "undefined";
        color = "undefined";
        System.out.println("I am creating quitar type FlamencoAcoustic");
    }

    public FlamencoAcoustic(String s, String c) {
        size = s;
        color = c;
        System.out.println("I am creating quitar type FlamencoAcoustic");
    }
    public String getType(){
        return "Flamenco Acoustic ";

    }

}
