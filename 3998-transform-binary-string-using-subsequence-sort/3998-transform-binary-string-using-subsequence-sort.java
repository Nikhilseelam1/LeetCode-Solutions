class Solution {
    public boolean[] transformStr(String s, String[] strs) {
        int n=s.length();
        int n1=0;
        int n0=0;
        boolean ans[]=new boolean [strs.length];
        int c=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='0') n0++;
            else n1++;
        }
        for(int i=0;i<strs.length;i++)
        {
            StringBuilder make=new StringBuilder("");
            StringBuilder curr=new StringBuilder("");
            int t0=0;
            int t1=0;
            String st=strs[i];
            for(int j=0;j<n;j++)
            {
                if(st.charAt(j)!=s.charAt(j)){
                    make.append(s.charAt(j));
                    curr.append(st.charAt(j));
                }
                if(st.charAt(j) == '0') t0++;
                if(st.charAt(j) =='1') t1++;
            }
            if(t0>n0 || t1>n1){
                ans[c]=false;
                c++;
                continue;
            }
            int d0=n0-t0;
            int d1=n1-t1;
            int j=0;
            // System.out.println(d0 + " " + d1);
            while(j<curr.length()){
                if(curr.charAt(j)=='?'){
                    if(d0>0){
                        curr.setCharAt(j,'0');
                        d0--;
                    }else{
                        curr.setCharAt(j,'1');
                        d1--;
                    }
                }
                j++;
            }
            // System.out.println(curr);
            int x1=0;
            int x2=0;
            boolean f=false;
            for(int k=0;k<make.length();k++){
                if(make.charAt(k)=='0') x1++;
                if(curr.charAt(k)=='0') x2++;
                if(x1>x2){
                    f=true;
                    break;
                }
            }
            if(f==true){
                ans[c]=false;
            }else{
                ans[c]=true;
            }
            c++;
        }
        return ans;
    }
}