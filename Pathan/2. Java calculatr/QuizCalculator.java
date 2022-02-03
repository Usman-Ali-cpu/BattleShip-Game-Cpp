public class QuizCalculator {
    String studentName; // varaible of type string to store name of student
    int totalQuiz; // varaible of type int to store count of quizes
    double sumScoreQuiz; // varaible of type double to store sum of scores of quizes

    // constructor takes name of student as a argument and
    // initialize the name of student by name
    public QuizCalculator(String name) {
        studentName = name; // set name
        totalQuiz = 0; // set total number of quizes to zero
        sumScoreQuiz = 0; // set total score to zero
    }

    // method takes score as a argument and add score in total score
    public void addScore(double score) {
        sumScoreQuiz += score; // add score to sum of scores
        totalQuiz++; // increment count of quizes too
    }

    // method returns average of all quizes,
    public double getAverage() {
        return sumScoreQuiz / totalQuiz; // average is get by dividing sum by total number of quizes
    }

    @Override
    // override of toString , it return required String of class data
    public String toString() {
        return studentName + " quiz average: " + String.format("%6.2f", getAverage()); // return string having username
                                                                                       // and averages of quizes
    }

}