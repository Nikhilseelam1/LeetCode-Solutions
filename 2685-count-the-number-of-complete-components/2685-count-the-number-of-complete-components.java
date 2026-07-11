class Solution {
    List<List<Integer>>list;
    boolean []vis;
    int ds;
    int no;
    public void dfs(int node){
        vis[node]=true;
        no++;
        ds+=(int)list.get(node).size();
        for(int i=0;i<list.get(node).size();i++){
            int u=list.get(node).get(i);
            if(vis[u]==false){
                dfs(u);
            }
        }
        return ;
    }
    public int countCompleteComponents(int n, int[][] edges) {
        list=new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(new ArrayList<>());
        }
        for(int []row:edges){
            int u=row[0];
            int v=row[1];
            list.get(u).add(v);
            list.get(v).add(u);
        }
        vis=new boolean[n];
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ds=0;
                no=0;
                dfs(i);
                int x=no*(no-1)/2;
                int e=ds/2;
                if(x==e) c++;
            }
        }
        return c;
    }
}