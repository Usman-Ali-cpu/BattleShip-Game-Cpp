public class DoubleLinkedList {
    private DoubleNode top;

    DoubleLinkedList() {
        top = null;
    }

    public void addToStart(double data) {
        DoubleNode newNode = new DoubleNode(data, top);
        top = newNode;
    }

    public void moveToFront(int pos) {

        DoubleNode previous = top;
        DoubleNode temp = top;

        int i = 0;
        while (temp != null || i <= pos) {
            if (i == pos) {
                // Found the item
                previous.setLink(temp.getLink());
                temp.setLink(top);
                top = temp;
                DoubleNode curprev = top, last = top;
                if (last.getLink() != null) {
                    last = curprev;
                    curprev = previous;
                }
                return;
            }

            try {
                previous = temp;
                temp = temp.getLink();
                throw new Exception();

            } catch (Exception e) {
                System.out.println(e.getMessage());

                // TODO: handle exception
            }

        }
    }

}