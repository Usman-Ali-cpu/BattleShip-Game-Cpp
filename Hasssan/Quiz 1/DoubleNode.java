public class DoubleNode {
    private double data;
    private DoubleNode link;

    public DoubleNode(double data, DoubleNode link) {
        this.data = data;
        this.link = link;
    }

    public double getData() {
        return data;
    }

    public DoubleNode getLink() {
        return link;
    }

    public void setData(double data) {
        this.data = data;
    }

    public void setLink(DoubleNode link) {
        this.link = link;
    }
}
