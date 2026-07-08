class SegmentTree {
    static final long MOD = 1_000_000_007L;
    class Node {
        long value;   // Concatenated non-zero number (mod MOD)
        long sum;     // Sum of non-zero digits
        int digits;   // Number of non-zero digits

        Node() {}

        Node(long value, long sum, int digits) {
            this.value = value;
            this.sum = sum;
            this.digits = digits;
        }
    }

    Node[] tree;
    long[] pow10;
    int n;

    SegmentTree(String s) {
        n = s.length();

        tree = new Node[4 * n];
        for (int i = 0; i < 4 * n; i++)
            tree[i] = new Node();

        pow10 = new long[n + 1];
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        build(0, 0, n - 1, s);
    }

    private void build(int node, int start, int end, String s) {

        if (start == end) {
            int d = s.charAt(start) - '0';

            if (d == 0) {
                tree[node].value = 0;
                tree[node].sum = 0;
                tree[node].digits = 0;
            } else {
                tree[node].value = d;
                tree[node].sum = d;
                tree[node].digits = 1;
            }
            return;
        }

        int mid = start + ((end - start) >> 1);
        int lchild = 2 * node + 1;
        int rchild = 2 * node + 2;

        build(lchild, start, mid, s);
        build(rchild, mid + 1, end, s);

        merge(tree[node], tree[lchild], tree[rchild]);
    }

    private void merge(Node parent, Node left, Node right) {

        parent.value =
                (left.value * pow10[right.digits] + right.value) % MOD;

        parent.sum = left.sum + right.sum;
        parent.digits = left.digits + right.digits;
    }

    private Node query(int node, int start, int end, int l, int r) {

        if (r < start || l > end)
            return new Node(0, 0, 0);

        if (l <= start && end <= r)
            return new Node(tree[node].value, tree[node].sum, tree[node].digits);

        int mid = start + ((end - start) >> 1);
        int lchild = 2 * node + 1;
        int rchild = 2 * node + 2;

        Node left = query(lchild, start, mid, l, r);
        Node right = query(rchild, mid + 1, end, l, r);

        Node ans = new Node();
        merge(ans, left, right);

        return ans;
    }

    public long query(int l, int r) {
        Node res = query(0, 0, n - 1, l, r);
        return (res.value * (res.sum % MOD)) % MOD;
    }
}

class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {
        SegmentTree sg = new SegmentTree(s);
        int n = queries.length;
        int[] res = new int[n];
        int i = 0;

        for (int[] q : queries) {
            int l = q[0], r = q[1];
            long val = sg.query(l, r);
            res[i++] = (int) val;
        }

        return res;
    }
}