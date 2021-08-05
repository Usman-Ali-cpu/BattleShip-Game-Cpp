public class Main{

    public static void main(String [] args){

        int temp = 180;
        while(temp != 80){
            if(temp > 90){
                System.out.print("To hoot");
                temp = temp - (temp >150? 100: 20);
            }else {
                if(temp< 70){
                    System.out.println("too cold");
                    temp = temp - (temp >50? 30: 20);
                }
            }
        }
        if(temp == 80){
            System.out.println("Just riht");
        }
        

    }

}