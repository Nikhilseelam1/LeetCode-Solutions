class Solution {
    public int maxDigitRange(int[] nums) {
        int n=nums.length;
        List<int []>list=new ArrayList<>();
        int max=0;
        for(int i=0;i<n;i++){
            String s=Integer.toString(nums[i]);
            int maxi=0;
            int mini=Integer.MAX_VALUE;
            for(int j=0;j<s.length();j++){
                maxi=Math.max(maxi,s.charAt(j)-'0');
                mini=Math.min(mini,s.charAt(j)-'0');
            }
            max=Math.max(max,maxi-mini);
            list.add(new int[]{nums[i],maxi-mini});
        }
        int ans=0;
        for(int i=0;i<list.size();i++){
            int []arr=list.get(i);
            if(max==arr[1]){
                ans+=arr[0];
            }
        }
        return ans;
    }
}