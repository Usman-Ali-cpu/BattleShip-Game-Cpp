public class Traveller {
    int customer_ID;
    String customer_name;
    String passport_number;
    String email_address;

    public Traveller(int customer_ID, String customer_name, String passport_number, String email_address) {
        this.customer_ID = customer_ID;
        this.customer_name = customer_name;
        this.passport_number = passport_number;
        this.email_address = email_address;
    }

    public int getCustomer_ID() {
        return customer_ID;
    }

    public void setCustomer_ID(int customer_ID) {
        this.customer_ID = customer_ID;
    }

    public String getCustomer_name() {
        return customer_name;
    }

    public void setCustomer_name(String customer_name) {
        this.customer_name = customer_name;
    }

    public String getPassport_number() {
        return passport_number;
    }

    public void setPassport_number(String passport_number) {
        this.passport_number = passport_number;
    }

    public String getEmail_address() {
        return email_address;
    }

    public void setEmail_address(String email_address) {
        this.email_address = email_address;
    }

    boolean isValid() {
        if (passport_number.length() != 6) {
            return false;
        }

        for (int i = 0; i < passport_number.length() - 1; i++) {
            if (!Character.isDigit(passport_number.charAt(i))) {
                return false;
            }

        }
        if (passport_number.charAt(passport_number.length() - 1) != 'T' && passport_number
                .charAt(passport_number.length() - 1) != 'Q') {
            return false;

        }
        return true;

    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return customer_ID + ",\t" + customer_name + ",\t" + passport_number + ",\t" + email_address;
    }

}
