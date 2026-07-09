class dsu{
    int []par;
    dsu(int n){
        par=new int[n];
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    public int parent(int u){
        if(par[u]==u) return par[u];
        return par[u]=parent(par[u]);
    }
    public void find(int u,int v){
        int up=parent(u);
        int vp=parent(v);
        if(up==vp) return ;
        par[up]=vp;
    }
}
class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] q) {
        dsu d=new dsu(n);
        // dsu d(n);
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])<=maxDiff){
                d.find(i,i-1);
            }
        }
        boolean []ans=new boolean[q.length];
        for(int i=0;i<q.length;i++){
            int l=q[i][0];
            int r=q[i][1];
            if(d.parent(l) == d.parent(r)){
                ans[i]=true;
            }
        }
        return ans;
    }
}