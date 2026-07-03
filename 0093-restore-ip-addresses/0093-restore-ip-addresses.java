class Solution {
    int n;
    public boolean  check(String s){
        int m=s.length();
        int i=0;
        if(s.charAt(0) == '0' && m>1) return false;
        int res=0;
        while(i<m){
            int r=s.charAt(i)-'0';
            res=res*10+r;
            i++;
        }
        return res<=255;
    }
    public void back(int i,List<String>list,String s,List<String>l,int c){
        if(c==4){
            if(i<n) return ;
            String s1="";
            for(int j=0;j<l.size()-1;j++){
                s1+=l.get(j);
            }
            String x=l.get(l.size()-1);
            s1+=x.substring(0,x.length()-1);
            list.add(s1);
        }else{
            for(int j=i;j<n;j++){
                String s1=s.substring(i,j+1);
                if(check(s1)){
                    s1+='.';
                    l.add(s1);
                    back(j+1,list,s,l,c+1);
                    l.remove(l.size()-1);
                }else{
                    return ;
                }
            }
        }
    }
    public List<String> restoreIpAddresses(String s) {
        n=s.length();
        List<String>list=new ArrayList<>();
        List<String>l=new ArrayList<>();
        back(0,list,s,l,0);
        return list;
    }
}