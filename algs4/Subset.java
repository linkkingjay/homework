public class Subset {
    public static void main(String[] args) {
        int k;
        String[] s;
        RandomizedQueue<String> rq = new RandomizedQueue<String>();

        k = Integer.parseInt(args[0]);
        s = StdIn.readStrings();

        for (int i = 0; i < s.length; i++) {
            rq.enqueue(s[i]);
        }

        while (k-- != 0) {
            StdOut.println(rq.sample());
        }
    }
}
