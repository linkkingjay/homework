public class PercolationStats {
    private int T;
    private double[] ret;

    public PercolationStats(int N, int T) {
        if (N <= 0 || T <= 0)
            throw new IllegalArgumentException("N or T is less than 0");
        this.T = T;
        ret = new double[T];

        for (int i = 0; i < T; i++) {
            Percolation p = new Percolation(N);
            double count = 0;
            while (!p.percolates()) {
                int x, y;
                do {
                    x = StdRandom.uniform(1, N + 1);
                    y = StdRandom.uniform(1, N + 1);
                } while (p.isOpen(x, y));
                p.open(x, y);
                count++;
            }
            ret[i] = count / (N * N);
        }
    }

    public double mean() {
        return StdStats.mean(ret);
    }

    public double stddev() {
        return StdStats.stddev(ret);
    }

    public double confidenceLo() {
        return mean() - 1.96 * stddev() / Math.sqrt(T);
    }

    public double confidenceHi() {
        return mean() + 1.96 * stddev() / Math.sqrt(T);
    }

    public static void main(String[] args) {
        int N, T;
        N = Integer.parseInt(args[0]);
        T = Integer.parseInt(args[1]);
        PercolationStats p = new PercolationStats(N, T);
        StdOut.printf("mean\t\t\t= ");
        StdOut.println(p.mean());
        StdOut.printf("stddev\t\t\t= %.17f\n", p.stddev());
        StdOut.printf("95%% confidence interval = %.17f %.17f\n",
                p.confidenceLo(), p.confidenceHi());
    }
}
