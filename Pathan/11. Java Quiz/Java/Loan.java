import java.util.Date;

public class Loan {
    Date dateTaken;
    Date duaDate;
    Book book;

    public Loan(Date dateTaken, Date duaDate, Book book) {
        this.dateTaken = dateTaken;
        this.duaDate = duaDate;
        this.book = book;
    }

    public Loan(Date dateTaken, Date duaDate) {
        this.dateTaken = dateTaken;
        this.duaDate = duaDate;
    }

    public Date getDateTaken() {
        return dateTaken;
    }

    public void setDateTaken(Date dateTaken) {
        this.dateTaken = dateTaken;
    }

    public Date getDuaDate() {
        return duaDate;
    }

    public void setDuaDate(Date duaDate) {
        this.duaDate = duaDate;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return book.toString() + ", Taken Date=" + dateTaken.toString() + ", Due Date=" + duaDate.toString();
    }

    public Book getBook() {
        return book;
    }

    public void setBook(Book book) {
        this.book = book;
    }

}
