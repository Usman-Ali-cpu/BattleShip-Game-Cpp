public class Book {
    String title;
    String ISBN;

    public Book(String title, String iSBN) {
        this.title = title;
        ISBN = iSBN;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String iSBN) {
        ISBN = iSBN;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "title=" + getTitle() + ", ISBN=" + getISBN() + "\n";
    }

}
