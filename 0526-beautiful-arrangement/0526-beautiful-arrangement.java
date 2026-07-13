class Solution {
    int n1;
    int rec(int i,boolean []used,List<Integer>list){
        int ans=0;
        if(i==n1+1){
            return (list.size()==n1?1:0);
        }else{
            for(int j=1;j<=n1;j++){
                if(used[j]==true) continue;
                if(j%i==0 || i%j==0){
                    list.add(j);
                    used[j]=true;
                    ans+=rec(i+1,used,list);
                    used[j]=false;
                    list.remove(list.size()-1);
                }
            }
        }
        return ans;
    }
    public int countArrangement(int n) {
        boolean []used=new boolean[n+1];
        List<Integer>list=new ArrayList<>();
        n1=n;
        return rec(1,used,list);
    }
}