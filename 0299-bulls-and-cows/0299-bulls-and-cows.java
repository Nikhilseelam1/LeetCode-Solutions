class Solution {
    public String getHint(String s, String g) {
        int n=s.length();
        int c=0;
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++){
            int x=s.charAt(i)-'0';
            if(s.charAt(i)==g.charAt(i)) c++;
            mp.put(x,mp.getOrDefault(x,0)+1);
        }
        int c1=0;
        for(int i=0;i<n;i++){
            int x=g.charAt(i)-'0';
            if(mp.containsKey(x)){
                mp.put(x, mp.get(x) - 1);
                if (mp.get(x) == 0) {
                    mp.remove(x);
                }
                c1++;
            }
        }
        String ans="";
                System.out.println(c1);
                        System.out.println(c);
        ans+=Integer.toString(c) + "A" + Integer.toString(c1-c) + "B";
        return ans;
    }
}