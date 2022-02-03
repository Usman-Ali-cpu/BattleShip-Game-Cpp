public class TestGame {

    public static void main(String[] args) {
        Game game1 = new Game(); // creating object by calling default constructor
        game1.setTitle("Call of Duty"); // set title to game
        game1.setGenre("Action"); // setting genre of game
        game1.setPlayers(3); // setting number of players can play
        game1.print(); // print data

        Game gm2 = new Game(3, "Puzzle", "Mines"); // creating object by calling parameterize constructor
        gm2.print(); // printing data of game

        // demonstrating play methods
        gm2.play();
        gm2.play(2);
    }

}
