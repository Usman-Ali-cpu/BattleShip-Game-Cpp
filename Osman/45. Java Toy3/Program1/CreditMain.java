public class CreditMain {
    public static void main(String[] args) {
        CreditCheck cc = new CreditCheck();
        CreditCheck cc2 = new CreditCheck();
        CreditCheck cc3 = new CreditCheck();
        cc.getInfo();
        cc2.getInfo();
        cc3.getInfo();
        if (Boolean.TRUE.equals(cc.getApproval())) {
            cc.printApproval();
        } else {
            cc.printDisapproval();
        }
        if (Boolean.TRUE.equals(cc2.getApproval())) {
            cc2.printApproval();
        } else {
            cc2.printDisapproval();
        }
        if (Boolean.TRUE.equals(cc3.getApproval())) {
            cc3.printApproval();
        } else {
            cc3.printDisapproval();
        }
    }
}
