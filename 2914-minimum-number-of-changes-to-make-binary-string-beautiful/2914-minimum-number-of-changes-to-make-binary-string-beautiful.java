class Solution {
    public int minChanges(String s) {
        int n=s.length();
        int z=0,o=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '0'){
                z++;
            }else o++;
            if(i%2==1){
                c+=Math.min(z,o);
                z=0;o=0;
            }
        }
        return c;
        
    }
}