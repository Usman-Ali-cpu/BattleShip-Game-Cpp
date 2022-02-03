import java.util.Scanner;

public class MainApp {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Hunter myhunter = new Hunter("Maha Deva", "Brown");
        Soldier[] threeSoldier = { new RedSoldier(), new RedSoldier(), new GreenSoldier() };
        Board myboard = new Board("superDot", myhunter, threeSoldier);
        System.out.println("Use Keyboard up, down, left, right arrow keys to move the hunter");
        myhunter.setX(sc.nextInt());
        myhunter.setY(sc.nextInt());
        myhunter.move(myhunter);
        myhunter.hunt(myboard);
        threeSoldier[2].hunt();

    }

}
