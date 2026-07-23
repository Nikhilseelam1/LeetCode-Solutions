class Solution {
   
    public int minCost(int[][] grid) {

    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[2], b[2]));
    pq.offer(new int[]{0, 0, 0});

    int n = grid.length;
    int m = grid[0].length;

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    boolean[][] vis = new boolean[n][m];

    while (!pq.isEmpty()) {

        int[] curr = pq.poll();

        int r = curr[0];
        int c = curr[1];
        int cost = curr[2];

        if (r == n - 1 && c == m - 1)
            return cost;

        if (vis[r][c])
            continue;

        vis[r][c] = true;

        if (grid[r][c] == 1) {

            if (r + dx[2] >= 0 && r + dx[2] < n && c + dy[2] >= 0 && c + dy[2] < m)
                pq.offer(new int[]{r + dx[2], c + dy[2], cost});

            if (r + dx[0] >= 0 && r + dx[0] < n && c + dy[0] >= 0 && c + dy[0] < m)
                pq.offer(new int[]{r + dx[0], c + dy[0], cost + 1});

            if (r + dx[1] >= 0 && r + dx[1] < n && c + dy[1] >= 0 && c + dy[1] < m)
                pq.offer(new int[]{r + dx[1], c + dy[1], cost + 1});

            if (r + dx[3] >= 0 && r + dx[3] < n && c + dy[3] >= 0 && c + dy[3] < m)
                pq.offer(new int[]{r + dx[3], c + dy[3], cost + 1});

        } else if (grid[r][c] == 2) {

            if (r + dx[2] >= 0 && r + dx[2] < n && c + dy[2] >= 0 && c + dy[2] < m)
                pq.offer(new int[]{r + dx[2], c + dy[2], cost + 1});

            if (r + dx[0] >= 0 && r + dx[0] < n && c + dy[0] >= 0 && c + dy[0] < m)
                pq.offer(new int[]{r + dx[0], c + dy[0], cost + 1});

            if (r + dx[1] >= 0 && r + dx[1] < n && c + dy[1] >= 0 && c + dy[1] < m)
                pq.offer(new int[]{r + dx[1], c + dy[1], cost + 1});

            if (r + dx[3] >= 0 && r + dx[3] < n && c + dy[3] >= 0 && c + dy[3] < m)
                pq.offer(new int[]{r + dx[3], c + dy[3], cost});

        } else if (grid[r][c] == 3) {

            if (r + dx[2] >= 0 && r + dx[2] < n && c + dy[2] >= 0 && c + dy[2] < m)
                pq.offer(new int[]{r + dx[2], c + dy[2], cost + 1});

            if (r + dx[0] >= 0 && r + dx[0] < n && c + dy[0] >= 0 && c + dy[0] < m)
                pq.offer(new int[]{r + dx[0], c + dy[0], cost + 1});

            if (r + dx[1] >= 0 && r + dx[1] < n && c + dy[1] >= 0 && c + dy[1] < m)
                pq.offer(new int[]{r + dx[1], c + dy[1], cost});

            if (r + dx[3] >= 0 && r + dx[3] < n && c + dy[3] >= 0 && c + dy[3] < m)
                pq.offer(new int[]{r + dx[3], c + dy[3], cost + 1});

        } else {

            if (r + dx[2] >= 0 && r + dx[2] < n && c + dy[2] >= 0 && c + dy[2] < m)
                pq.offer(new int[]{r + dx[2], c + dy[2], cost + 1});

            if (r + dx[0] >= 0 && r + dx[0] < n && c + dy[0] >= 0 && c + dy[0] < m)
                pq.offer(new int[]{r + dx[0], c + dy[0], cost});

            if (r + dx[1] >= 0 && r + dx[1] < n && c + dy[1] >= 0 && c + dy[1] < m)
                pq.offer(new int[]{r + dx[1], c + dy[1], cost + 1});

            if (r + dx[3] >= 0 && r + dx[3] < n && c + dy[3] >= 0 && c + dy[3] < m)
                pq.offer(new int[]{r + dx[3], c + dy[3], cost + 1});
        }
    }

    return 0;
    }
}