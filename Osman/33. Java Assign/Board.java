
import java.util.Random;

public class Board {
    int x;
    int y;
    String type;
    char[][] arr;
    Hunter bHunter;
    Soldier[] threeSoldiers;

    public Board() {
        x = 250;
        y = 360;
        arr = new char[x][y];
        for (int i = 0; i < 100; i++) {
            Random rand = new Random();
            int a = rand.nextInt(249 - 0) + 0;
            int b = rand.nextInt(359 - 0) + 0;

            while (arr[a][b] == '.' || arr[a][b] == ',') {
                a = rand.nextInt(249 - 0) + 0;
                b = rand.nextInt(359 - 0) + 0;

            }
            arr[a][b] = '.';
        }
        bHunter = new Hunter();
        threeSoldiers = new Soldier[3];
        System.out.println("Board is ready and three soldiers, and hunter is positioned in the board");
    }

    public Board(String typedot, Hunter hunt, Soldier[] threeSoldier) {
        x = 250;
        y = 360;
        arr = new char[x][y];
        for (int i = 0; i < 100; i++) {
            Random rand = new Random();
            int a = rand.nextInt(249 - 0) + 0;
            int b = rand.nextInt(359 - 0) + 0;

            while (arr[a][b] == '.' || arr[a][b] == ',') {
                a = rand.nextInt(249 - 0) + 0;
                b = rand.nextInt(359 - 0) + 0;

            }
            arr[a][b] = '.';
        }
        bHunter = new Hunter();
        threeSoldiers = new Soldier[3];
        type = typedot;
        System.out.println("Board is ready and three soldiers, and hunter is positioned in the board");
    }

    public void huntIndex(int i, int j) {
        arr[i][j] = ' ';
    }

    public String getType() {
        return type;
    }

}
