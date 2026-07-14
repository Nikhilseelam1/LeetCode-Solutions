class Solution {
    public String optimalDivision(int[] nums) {
        if(nums.length == 1){
            return Integer.toString(nums[0]);
        }
        if(nums.length==2){
            return Integer.toString(nums[0]) + '/' + Integer.toString(nums[1]);
        }
        String ans="";
        int n=nums.length;
        ans=Integer.toString(nums[0]) + '/' + '(';
        for(int i=1;i<n;i++){
            if(i==n-1){
                ans+=Integer.toString(nums[i]) + ')';
                break;
            }
            ans+=Integer.toString(nums[i]) + '/';
        }
        return ans;
    }
}