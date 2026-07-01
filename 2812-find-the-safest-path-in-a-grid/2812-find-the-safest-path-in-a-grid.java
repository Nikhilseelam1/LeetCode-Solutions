import java.util.*;
class Solution {
    int[] rows={0,1,0,-1};
    int[] cols={1,0,-1,0};
    int [][] safety;
    int n;
    public void bfs(List<List<Integer>> grid){
        PriorityQueue<int[]>pq=new PriorityQueue<>
        ((a,b)-> Integer.compare(a[0],b[0]));
        boolean [][] vis=new boolean [n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid.get(i).get(j)==1){
                    safety[i][j]=0;
                    vis[i][j]=true;
                    pq.offer(new int[]{0,i,j});
                }
            }
        }
        while(!pq.isEmpty()){
            int []it =pq.peek();
            pq.poll();
            int r=it[1];
            int c=it[2];
            int w=it[0];
            for(int i=0;i<4;i++){
                int ri=r+rows[i];
                int cj=c+cols[i];
                if(ri<n && cj<n && cj>=0 && ri>=0 && !vis[ri][cj]){
                    vis[ri][cj]=true;
                    safety[ri][cj]=w+Math.abs(r-ri) + Math.abs(c-cj);
                    pq.offer( new int[]{safety[ri][cj],ri,cj});
                }
            }
        }
    }
    public boolean bfs2(int mid){
        int [][] safety1=new int[n][n];
        for(int i=0;i<n;i++){
            safety1[i]=safety[i].clone();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(safety1[i][j]<mid){
                    safety1[i][j]=-1;
                }
            }
        }
        Queue<int []>q=new LinkedList<>();
        if(safety1[0][0]!=-1) q.offer(new int []{0,0});
        boolean [][] vis=new boolean [n][n];
        while(!q.isEmpty()){
            int []it=q.peek();
            q.poll();
            int r=it[0];
            int c=it[1];
            if(r==n-1 && c==n-1) return true;
            for(int i=0;i<4;i++){
                int ri=r+rows[i];
                int cj=c+cols[i];
                if(ri<n && cj<n && cj>=0 && ri>=0 && !vis[ri][cj] && safety1[ri][cj]!=-1){
                    vis[ri][cj]=true;
                    q.offer(new int[]{ri,cj});
                }
            }
        }
        return false;
    }
    public int maximumSafenessFactor(List<List<Integer>> grid) {
       n=grid.size();
        safety=new int [n][n];
        bfs(grid);
        int mini=Integer.MAX_VALUE;
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi=Math.max(maxi,safety[i][j]);
                mini=Math.min(mini,safety[i][j]);
            }
        }
        int ans=0;
        while(mini<=maxi){
            int mid=mini + (maxi-mini)/2;
            if(bfs2(mid)){
                ans=mid;
                mini=mid+1;
            }else{
                maxi=mid-1;
            }
        }
        return ans;
    }
}