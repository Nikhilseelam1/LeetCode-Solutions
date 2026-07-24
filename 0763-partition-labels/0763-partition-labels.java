class Solution {
    public List<Integer> partitionLabels(String s) {
        int []freq=new int[26];
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s.charAt(i) - 'a']++;
        }
        String ans="";
        List<Integer>list=new ArrayList<>();
        HashSet<Character>st=new HashSet<>();
        for(int i=0;i<n;i++)
        {
            ans+=s.charAt(i);
            st.add(s.charAt(i));
            freq[s.charAt(i) - 'a']--;
            int j=0;
            for(char ch:st){
                if(freq[ch-'a'] > 0) break;
                if(j==st.size()-1){
                    st.clear();
                    list.add(ans.length());
                    ans="";
                    break;
                }
                j++;
            }
        } 
        return list;  
    }
}