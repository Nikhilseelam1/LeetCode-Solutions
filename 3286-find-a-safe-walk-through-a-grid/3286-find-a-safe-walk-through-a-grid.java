class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int h) {
        int n=grid.size();
        int m=grid.get(0).size();
PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        if(grid.get(0).get(0) == 0) q.offer(new int[]{h,0,0});
        else q.offer(new int[]{h-1,0,0});
         int []rows={0,1,0,-1};
        int []cols={1,0,-1,0};
        int [][] vis=new int [n][m];
        vis[0][0]=1;
        while(!q.isEmpty()){
            int [] it=q.poll();
            int h_=it[0];
            int r=it[1];
            int c=it[2];
            System.out.print(r);
            System.out.println(c);
            System.out.println(h_);
            if(h_<=0) continue;
            if(r==n-1 && c==m-1){
                if(h_>0) return true;
                continue;
            }
            for(int i=0;i<4;i++){
                int ri=r+rows[i];
                int cj=c+cols[i];
                if(ri<n && cj<m && cj>=0 && ri>=0 && vis[ri][cj]!=1){
                    vis[ri][cj]=1;
                    q.offer(new int []{ (grid.get(ri).get(cj)==0) ? h_ :h_-1,ri,cj});
                }
            }
        }
        return false;
    }
}