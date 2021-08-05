public class Lab3_Alhindi {

    public static void main(String[] args){
        Hero[] heroes = new Hero[6];
        heroes[0] = new Hero("Spiderman", 17);
        heroes[1] = new Hero("Superman", 23);
        heroes[2] = new Hero("Batman", 24);
        heroes[3] = new Hero("Thor", 25);
        heroes[4] = new Hero("Hulk", 27);
        heroes[5] = new Hero("Iron Man", 34);
        System.out.println("=== All heroes :");
        printHeroes(heroes);
        System.out.println("\n=== Heroes over 25 :");
        printHeroes(heroes, 25);
        System.out.println("\n=== Heroes between 18 and 26 :");
        printHeroes(heroes, 18, 26);
        
    }

    public static void printHeroes(Hero [] hero){
        for(int i=0; i< hero.length; i++){
            System.out.println(hero[i].toString());
        }
    }
    public static void printHeroes(Hero [] hero, int minage){
        for(int i=0; i< hero.length; i++){
            if(hero[i].getAge() >= minage){
                System.out.println(hero[i].toString());
            }
        }
    }
    public static void printHeroes(Hero [] hero, int minage, int maxage){
        for(int i=0; i< hero.length; i++){
            if(hero[i].getAge() >= minage && hero[i].getAge() <= maxage){
                System.out.println(hero[i].toString());
            }
        }
    }
    

    
    
}
