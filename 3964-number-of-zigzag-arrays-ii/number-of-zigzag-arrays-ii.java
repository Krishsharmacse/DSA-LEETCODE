class Solution {
    static final int MOD = 1000000007;

    public int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;

        if (n == 1) return k;
        if (n == 2) return (int) (((long) k * (k - 1)) % MOD);

        int size = 2 * k;

        long[][] initial = new long[size][1];

        for (int v = 1; v <= k; v++) {
            initial[v - 1][0] = k - v;       // last movement was down
            initial[k + v - 1][0] = v - 1;   // last movement was up
        }

        long[][] T = new long[size][size];

        for (int v = 1; v <= k; v++) {

            // Previous direction up, now go down
            for (int u = 1; u < v; u++) {
                T[k + v - 1][u - 1] = 1;
            }

            // Previous direction down, now go up
            for (int u = v + 1; u <= k; u++) {
                T[v - 1][k + u - 1] = 1;
            }
        }

        long[][] Tn = power(T, n - 2);
        long[][] ans = multiply(Tn, initial);

        long total = 0;
        for (int i = 0; i < size; i++) {
            total = (total + ans[i][0]) % MOD;
        }

        return (int) total;
    }

    private long[][] multiply(long[][] A, long[][] B) {
        int rows = A.length;
        int cols = B[0].length;
        int common = A[0].length;

        long[][] C = new long[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                long sum = 0;
                for (int x = 0; x < common; x++) {
                    sum = (sum + A[i][x] * B[x][j]) % MOD;
                }
                C[i][j] = sum;
            }
        }

        return C;
    }

    private long[][] power(long[][] base, long exp) {
        int n = base.length;
        long[][] res = new long[n][n];

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }
}