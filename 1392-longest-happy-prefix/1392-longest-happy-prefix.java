class Solution {
    public String longestPrefix(String s) {
        int n=s.length();
        int i=1;
        int []arr=new int[n];
        int len=0;
        while(i<n){
            if(s.charAt(i) == s.charAt(len)){
                len++;
                arr[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=arr[len-1];
                }else{
                    arr[i]=0;
                    i++;
                }
            }
        }
        // for(int it:arr){
        //     System.out.println(it);
        // }
        if(arr[n-1]==0) return "";
        int x=arr[n-1];
        // System.out.println(x);
        String ans="";
        for(int j=n-x;j<n;j++){
            ans+=s.charAt(j);
        }
        return ans;
    }
}