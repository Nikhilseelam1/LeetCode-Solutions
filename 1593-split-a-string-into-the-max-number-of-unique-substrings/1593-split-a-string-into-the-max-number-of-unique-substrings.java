class Solution {
    int ans;
    void rec(int i,String s,HashSet<String>st){
        if(i==s.length()){
            ans=Math.max(ans,st.size());
            return ;
        }else{
            String x="";
            for(int j=i;j<s.length();j++){
                x+=s.charAt(j);
                if(st.contains(x)){
                    continue;
                }else{
                    st.add(x);
                    rec(j+1,s,st);
                    st.remove(x);
                    // x="";
                }
            }
        }
    }
    public int maxUniqueSplit(String s) {
        int n=s.length();
        ans=0;
        HashSet<String>st=new HashSet<>();
        rec(0,s,st);
        return ans;
    }
}