import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int size;

    public Deque() {
        size = 0;
        first = new Node();
        last = new Node();

        first.prev = null;
        first.next = last;

        last.prev = first;
        last.next = null;
    }

    public boolean isEmpty() {
        return first.next == last;
    }

    public int size() {
        return size;
    }

    public void addFirst(Item item) {
        if (item == null) {
            throw new NullPointerException("try to add a null item");
        }
        Node newNode = new Node();
        newNode.item = item;
        newNode.next = first.next;
        newNode.prev = first;
        first.next.prev = newNode;
        first.next = newNode;
        size++;
    }

    public void addLast(Item item) {
        if (item == null) {
            throw new NullPointerException("try to add a null item");
        }

        Node newNode = new Node();
        newNode.item = item;
        newNode.next = last;
        newNode.prev = last.prev;
        last.prev.next = newNode;
        last.prev = newNode;
        size++;
    }

    public Item removeFirst() {
        if (this.isEmpty()) {
            throw new NoSuchElementException();
        }

        Item firstItem = first.next.item;
        first.next.next.prev = first;
        first.next = first.next.next;
        size--;
        return firstItem;
    }

    public Item removeLast() {
        if (this.isEmpty()) {
            throw new NoSuchElementException();
        }

        Item lastItem = last.prev.item;
        last.prev.prev.next = last;
        last.prev = last.prev.prev;
        size--;
        return lastItem;
    }

    public Iterator<Item> iterator() {
        return  new DequeIterator();
    }

    private class Node {
        private Item item;
        private Node next;
        private Node prev;
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = first.next;

        public boolean hasNext() {
            return current != last;
        }
        public void remove() {
            throw new UnsupportedOperationException();
        }
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public static void main(String[] args) {
        Deque<String> dq = new Deque<String>();

        assert dq.isEmpty();
        assert dq.size() == 0;

        dq.addFirst("first");
        assert dq.size() == 1;
        dq.addLast("last");
        assert dq.size() == 2;

        assert dq.removeLast().equals("last");
        assert dq.size() == 1;
        assert dq.removeFirst().equals("first");
        assert dq.size() == 0;

        dq.addFirst("first");
        assert dq.size() == 1;
        dq.addLast("last");
        assert dq.size() == 2;

        assert dq.removeLast().equals("last");
        assert dq.size() == 1;
        assert dq.removeFirst().equals("first");
        assert dq.size() == 0;


        dq.addFirst("l");
        dq.addFirst("i");
        dq.addFirst("n");
        dq.addFirst("k");
        StringBuilder s = new StringBuilder();
        for (String item : dq) {
            s.append(item);
        }
        assert s.toString().compareTo("knil") == 0;

        dq = new Deque<String>();
        dq.addLast("l");
        dq.addLast("i");
        dq.addLast("n");
        dq.addLast("k");
        s = new StringBuilder();
        for (String item : dq) {
            s.append(item);
        }
        assert s.toString().compareTo("link") == 0;
    }
}
