public class WeeklyPay {

    double hourlyRate;
    int numberOfHours;

    public WeeklyPay() {

    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }

    public void setNumberOfHours(int numberOfHours) {
        this.numberOfHours = numberOfHours;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    public int getNumberOfHours() {
        return numberOfHours;
    }

    public double calculatePayCheck() {
        double pay = getHourlyRate() * getNumberOfHours();
        return calculatePayCheck();

    }

}
