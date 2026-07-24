class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer>st=new HashSet<>();
        st.add(nums[0]);
        int ans=0;
        int n=nums.length;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(st.contains(nums[i])){
                int c=(prev+1 - nums[i]);
                ans+=c;
                st.add(c+nums[i]);
                prev=c+nums[i];
            }else{
                st.add(nums[i]);
                prev=nums[i];
            }
        }
        return ans;
    }
}