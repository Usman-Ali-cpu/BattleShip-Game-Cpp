public class ClassicAcoustic extends AcousticGuitar {

    public ClassicAcoustic() {
        size = "undefined";
        color = "undefined";
        System.out.println("I am creating quitar type ClassicAcoustic");
    }

    public ClassicAcoustic(String s, String c) {
        size = s;
        color = c;
        System.out.println("I am creating quitar type ClassicAcoustic");
    }
    public String getType(){
        return "Classic Acoustic ";

    }
    
    

}
