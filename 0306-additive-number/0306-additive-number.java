import java.math.BigInteger;
class Solution {
    boolean f=false;
    public boolean check(String s,List<String>list){
            String x=list.get(list.size()-1);
            String x1=list.get(list.size()-2);
            String y1=list.get(list.size()-3);
            if((x.charAt(0)=='0' && x.length()>1) || (x1.charAt(0)=='0' && x1.length()>1) || (y1.charAt(0)=='0' && y1.length()>1)) return false;
            BigInteger a = new BigInteger(y1);
            BigInteger b = new BigInteger(x1);
            BigInteger c = new BigInteger(x);

    return a.add(b).equals(c);
    }
    public void rec(int i,String s,List<String>list){
        if(list.size()>=3){
            if(check(s,list)!=true) return ;
        }
        if(i==s.length()){
            if(list.size()>=3 && check(s,list)==true) f=true;
            return ;
        }else{
            for(int j=i;j<s.length();j++){
                String s1=s.substring(i,j+1);
                list.add(s1);
                rec(j+1,s,list);
                list.remove(list.size()-1);
            }
        }
    }
    public boolean isAdditiveNumber(String num) {
        List<String>list=new ArrayList<>();
        rec(0,num,list);
        return f;
    }
}