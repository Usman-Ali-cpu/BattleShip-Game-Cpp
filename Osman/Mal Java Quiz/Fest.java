
public class Fest{
    try{
        Month m1 = new Month("Septober");
        Month m2 = new Moth(100);
    }
     catch (Exception e) {
        System.out.println(e.getMessage());
    }



    public class Month{
        private int monthNumber;
        public Month(int m) throws InvalidMonthNumberException{
            if(m<1 || m> 12){
                throw InvalidMonthNumberException(m);

            }
            else {
                monthNumber = m;
            }

        }

    }

}