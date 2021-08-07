public class StudentClass {
    public static String[] arrName;

    public StudentClass() {

    }

    public String getQuery(String studentData, String query) {

        String[] names = studentData.split(" ");
        arrName = names;
        char c = query.charAt(0);
        int q = Integer.parseInt(String.valueOf(c));
        String output = "";
        switch (q) {
            case 1: {
                char start = query.charAt(2);

                for (String name : names) {
                    if (name.toLowerCase().charAt(0) == start) {
                        output += name + "\n";
                    }
                }
            }
                break;
            case 2: {
                String blood = query.substring(2, query.length() - 3);
                // String checkBlood = query.substring(query.lastIndexOf(','), query.length());
                String checkBlood;
                if (query.charAt(query.length() - 3) != ',') {
                    checkBlood = query.substring(query.length() - 3, query.length());
                } else {
                    checkBlood = query.substring(query.length() - 2, query.length());
                }

                String[] arrBlood = blood.split(" ");
                for (int i = 0; i < arrBlood.length; i++) {
                    if (arrBlood[i].equals(checkBlood)) {
                        output += names[i] + "\n";
                    }
                }

            }
                break;
            case 3: {
                int marks = Integer.parseInt(query.substring(2, query.length()));
                int count = 0;
                for (String name : names) {
                    if (marks <= Integer.parseInt(name)) {
                        count++;
                    }
                }
                output = count + " students scored " + marks + " above";
            }
                break;
            case 4: {
                double sum = 0;
                for (String name : names) {
                    int num = Integer.parseInt(name);
                    sum += num;

                }
                double avr = sum / names.length;
                output = String.format("%.2f", avr);
                // output += avr;
            }
                break;
            case 5: {
                double sum = 0;
                for (String name : names) {
                    double num = Double.parseDouble(name);
                    sum += num;
                }
                double avr = sum / names.length;
                output = String.format("%.2f", avr);
                // output += avr;
            }
                break;

            default:
                break;
        }

        return output;

    }

}
