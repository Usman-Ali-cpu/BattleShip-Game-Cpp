import java.util.ArrayList;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * This class implements a hash set using separate chaining.
 */
public class VerticleHashSet {
    ArrayList<Object>[] al;
    private Node[] buckets;
    private int currentSize;

    /**
     * Constructs a hash table.
     * 
     * @param bucketsLength the length of the buckets array
     */
    public VerticleHashSet(int bucketsLength) {
        al = new ArrayList[bucketsLength];

        for (int i = 0; i < bucketsLength; i++) {
            al[i] = new ArrayList<Object>();
        }
        buckets = new Node[bucketsLength];
        currentSize = 0;
    }

    /**
     * Tests for set membership.
     * 
     * @param x an object
     * @return true if x is an element of this set
     */
    public boolean contains(Object x) {
        int h = x.hashCode();
        if (h < 0) {
            h = -h;
        }
        h = Hash.CyclicShift(Integer.toString(h)) % buckets.length;

        for (int i = 0; i < al[h].size(); i++) {
            if (al[h].get(i).equals(x)) {
                return true;
            }
        }
        return false;

        // Node current = buckets[h];
        // while (current != null) {
        // if (current.data.equals(x)) {
        // return true;
        // }
        // current = current.next;
        // }
        // return false;
    }

    /**
     * Adds an element to this set.
     * 
     * @param x an object
     * @return true if x is a new object, false if x was already in the set
     */
    public boolean add(Object x) {
        int h = x.hashCode();

        if (h < 0) {
            h = -h;
        }
        h = Hash.CyclicShift(Integer.toString(h)) % buckets.length;
        al[h].add(x);
        return true;

        // Node current = buckets[h];
        // while (current != null) {
        // if (current.data.equals(x)) {
        // return false;
        // }
        // // Already in the set
        // current = current.next;
        // }
        // Node newNode = new Node();
        // newNode.data = x;
        // newNode.next = buckets[h];
        // buckets[h] = newNode;
        // currentSize++;
        // return true;
    }

    public void display() {
        for (int i = 0; i < al.length; i++) {
            for (Object o : al[i]) {
                System.out.print(o);
            }
            System.out.println(",");

        }
    }

    /**
     * Removes an object from this set.
     * 
     * @param x an object
     * @return true if x was removed from this set, false if x was not an element of
     *         this set
     */
    public boolean remove(Object x) {
        int h = x.hashCode();
        if (h < 0) {
            h = -h;
        }
        h = Hash.CyclicShift(Integer.toString(h)) % buckets.length;

        for (int i = 0; i < al[h].size(); i++) {
            if (al[h].get(i).equals(x)) {
                al[h].remove(x);
                return true;
            }
        }
        return false;

        // Node current = buckets[h];
        // Node previous = null;
        // while (current != null) {
        // if (current.data.equals(x)) {
        // if (previous == null) {
        // buckets[h] = current.next;
        // } else {
        // previous.next = current.next;
        // }
        // currentSize--;
        // return true;
        // }
        // previous = current;
        // current = current.next;
        // }
        // return false;
    }

    /**
     * Returns an iterator that traverses the elements of this set.
     * 
     * @return a hash set iterator
     */
    public Iterator iterator() {
        return new HashSetIterator();
    }

    /**
     * Gets the number of elements in this set.
     * 
     * @return the number of elements
     */
    public int size() {
        return currentSize;
    }

    class Node {
        public Object data;
        public Node next;
    }

    class HashSetIterator implements Iterator {
        int size;
        int current;

        /**
         * Constructs a hash set iterator that points to the first element of the hash
         * set.
         */
        public HashSetIterator() {
            size = al.length;
            current = 0;
        }

        public boolean hasNext() {
            if (current < size) {
                current++;
                return true;
            }
            return false;
        }

        public ArrayList<Object> next() {
            ArrayList<Object> s = new ArrayList<>();
            if (current < size) {
                return al[current];
            }
            return s;

        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}