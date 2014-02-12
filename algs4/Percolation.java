public class Percolation {
    private int N;
    private boolean[] open;
    private WeightedQuickUnionUF wquf;

    public Percolation(int N) {
        this.N = N;
        wquf = new WeightedQuickUnionUF((N + 1) * (N + 1));
        for (int i = 1, j = 1; j <= N; j++)
            wquf.union(0, i * N + j);

        open = new boolean[(N + 1) * (N + 1)];
        for (int i = 1; i <= N * N; i++)
            open[i] = false;
        open[0] = true;
    }
    
    public void open(int i, int j) {
        if (i < 1 || i > N)
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j < 1 || j > N)
            throw new IndexOutOfBoundsException("column index j out of bounds");

        open[i * N + j] = true;
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int d = 0; d < 4; d++) {
            int m = i + dir[d][0];
            int n = j + dir[d][1];
            if (m > 0 && m <= N && n > 0 && n <= N && isOpen(m, n))
                wquf.union(N * i + j, N * m + n);
        }
    }

    public boolean isOpen(int i, int j) {
        if (i < 1 || i > N)
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j < 1 || j > N)
            throw new IndexOutOfBoundsException("column index j out of bounds");
        return open[i * N + j];
    }

    public boolean isFull(int i, int j) {
        if (i < 1 || i > N)
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j < 1 || j > N)
            throw new IndexOutOfBoundsException("column index j out of bounds");
        return isOpen(i, j) && wquf.connected(0, N * i + j);
    }

    public boolean percolates() {
        for (int i = N, j = 1; j <= N; j++)
            if (isFull(i, j))
                return true;
        return false;
    }
}
