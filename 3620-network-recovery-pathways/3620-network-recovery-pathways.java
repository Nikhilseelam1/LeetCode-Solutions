class Solution {
    public boolean check(int mid,List<List<int[]>>adj,long k,boolean [] online){
        PriorityQueue<int[]>pq=new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.offer(new int[]{0,0});
        long[] dist = new long[online.length];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        while(!pq.isEmpty()){
            int []it=pq.poll();
            int node=it[1];
            int w=it[0];
            if(node==online.length-1) return true;
            if(w>dist[node]) continue;
            if(w>k) continue;
            for(int i=0;i<adj.get(node).size();i++){
                int []x=adj.get(node).get(i);
                int no=x[0];
                int w_=x[1];
                if(online[no] && w+w_<dist[no] && w+w_<=k && w_>=mid){
                    dist[no]=w+w_;
                    pq.offer(new int[]{w+w_,no});
                }
            }
        }
        return false;
    }
    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        List<List<int[]>> adj=new ArrayList<>();
        int low=Integer.MAX_VALUE;
        int high=Integer.MIN_VALUE;
        if(edges.length==0) return -1;
        int n=0;
        for(int []it:edges){
            n=Math.max(n,it[0]);
            n=Math.max(n,it[1]);
            low=Math.min(low,it[2]);
            high=Math.max(high,it[2]);
        }
        for(int i=0;i<=n;i++){
            adj.add(new ArrayList<>());
        }
        for(int []it:edges){
            adj.get(it[0]).add(new int[]{it[1],it[2]});
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,adj,k,online)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
}