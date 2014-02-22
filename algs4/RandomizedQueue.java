import java.util.Iterator;
import java.util.NoSuchElementException;
public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] q;
    private int head, tail, size, capicity;

    public RandomizedQueue() {
        capicity = 2;
        size = 0;
        head = 0;
        tail = 0;
        q = (Item[]) new Object[2];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void enqueue(Item item) {
        if (item == null) {
            throw new NullPointerException();
        }

        q[head] = item;
        if (++size == capicity) {
            capicity *= 2;
            Item[] temp = (Item[]) new Object[capicity];
            for (int i = 0, j = tail; i < size; i++, j++) {
                temp[i] = q[j % (capicity / 2)];
            }
            q = temp;
            tail = 0;
            head = size;
        } else {
            head++;
            head %= capicity;
        }
    }

    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        Item item = q[tail];
        q[tail] = null;
        tail++;
        if (--size > 0 && size == capicity / 4) {
            capicity /= 2;
            Item[] temp = (Item[]) new Object[capicity];
            for (int i = 0, j = tail; i < size; i++, j++) {
                temp[i] = q[j % (capicity * 2)];
            }
            q = temp;
            tail = 0;
            head = size;
        }
        tail %= capicity;

        return item;
    }

    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        int random = (StdRandom.uniform(size()) + tail) % capicity;
        return q[random];
    }

    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int current = tail;

        public boolean hasNext() {
            return current != head;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            Item item = q[current];
            current++;
            current %= capicity;
            return item;
        }
    }

    public static void main(String[] args) {
        RandomizedQueue<String> a = new RandomizedQueue<String>();

        assert a.size() == 0;
        assert a.isEmpty();

        a.enqueue("hello");
        assert a.size() == 1;
        assert !a.isEmpty();
        assert a.sample().toString().compareTo("hello") == 0;

        assert a.dequeue().equals("hello");
        assert a.size() == 0;
        assert a.isEmpty();

        a.enqueue("l");
        assert a.size() == 1;
        a.enqueue("i");
        assert a.size() == 2;
        a.enqueue("n");
        assert a.size() == 3;
        a.enqueue("k");
        assert a.size() == 4;
        StringBuilder s = new StringBuilder();
        for (String item : a) {
            s.append(item);
        }
        StdOut.println(s.toString());
        assert s.toString().compareTo("link") == 0;

        assert a.dequeue().equals("l");
        assert a.dequeue().equals("i");
        assert a.dequeue().equals("n");
        assert a.dequeue().equals("k");
    }
}
