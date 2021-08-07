public class Encryptor {


    public static String encryptMessage(String name) throws InvalidMessageException {
        String out = "";
        try {
            if (Validator.validate(name)) {
                name = name.toLowerCase();
                for (int i = name.length() - 1; i >= 0; i--) {
                    out += name.charAt(i);
                }
            } else {
                throw new InvalidMessageException();
            }

        } catch (Exception e) {
            System.out.print(e.getMessage());
        }

        return out;
    }

}
