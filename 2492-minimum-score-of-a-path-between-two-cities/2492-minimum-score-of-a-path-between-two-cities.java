class Solution {
    public int minScore(int n, int[][] roads) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < roads.length; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u,w});
        }
        Queue<Integer>q=new LinkedList<>();
        q.offer(1);
        boolean []vis=new boolean[n+1];
        vis[1]=true;
        int ans=Integer.MAX_VALUE;
        while(!q.isEmpty()){
            int node=q.poll();
            for(int i=0;i<graph.get(node).size();i++){
                int []ed=graph.get(node).get(i);
                int no=ed[0];
                int mini=ed[1];
                ans=Math.min(ans,mini);
                if(vis[no]!=true){
                    vis[no]=true;
                    q.offer(no);
                }
            }
        }
        return ans;
    }
}