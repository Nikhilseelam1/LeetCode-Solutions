class Solution {

    int MOD = 1_000_000_007;
    int[][] score;
    int[][] ways;
    boolean[][] vis;

    class Pair {
        int score;
        int ways;

        Pair(int s, int w) {
            score = s;
            ways = w;
        }
    }

    Pair dfs(int i, int j, List<String> board) {

        if (i < 0 || j < 0)
            return new Pair(Integer.MIN_VALUE, 0);

        if (board.get(i).charAt(j) == 'X')
            return new Pair(Integer.MIN_VALUE, 0);

        if (vis[i][j])
            return new Pair(score[i][j], ways[i][j]);

        vis[i][j] = true;

        if (i == 0 && j == 0) {
            score[i][j] = 0;
            ways[i][j] = 1;
            return new Pair(0, 1);
        }

        Pair up = dfs(i - 1, j, board);
        Pair left = dfs(i, j - 1, board);
        Pair diag = dfs(i - 1, j - 1, board);

        int best = Math.max(up.score, Math.max(left.score, diag.score));

        if (best == Integer.MIN_VALUE) {
            score[i][j] = Integer.MIN_VALUE;
            ways[i][j] = 0;
            return new Pair(score[i][j], ways[i][j]);
        }

        long cnt = 0;

        if (up.score == best)
            cnt += up.ways;

        if (left.score == best)
            cnt += left.ways;

        if (diag.score == best)
            cnt += diag.ways;

        char ch = board.get(i).charAt(j);
        int val = (ch >= '0' && ch <= '9') ? ch - '0' : 0;

        score[i][j] = best + val;
        ways[i][j] = (int)(cnt % MOD);

        return new Pair(score[i][j], ways[i][j]);
    }

    public int[] pathsWithMaxScore(List<String> board) {

        int n = board.size();

        score = new int[n][n];
        ways = new int[n][n];
        vis = new boolean[n][n];

        Pair ans = dfs(n - 1, n - 1, board);

        if (ans.score == Integer.MIN_VALUE)
            return new int[]{0, 0};

        return new int[]{ans.score, ans.ways};
    }
}