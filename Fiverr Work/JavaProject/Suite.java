public class Suite extends Room {

        int m2Bedroom;
        int  m2LivingRoom;
        int price;
        
        Suite() {
            super();
            this.m2Bedroom = 0;
            this.m2LivingRoom = 0;
            this.price = 0;
            type = "suite";
        }

        Suite(int bed, int live, int price, int n) {
            super(n);
            this.m2Bedroom = bed;
            this.m2LivingRoom = live;
            this.price = price;
            type = "suite";
        }
        
        public void PrintRoom() {
            System.out.println("Room Number : " + number);
            System.out.println("Room Type : " + type);
            System.out.println("Room Price : " + price);
            System.out.println("Bed Room dimension : " + m2Bedroom);
            System.out.println("Living Room dimension : " + m2LivingRoom);
            System.out.println("\n");
        }
}
