class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int i=0;
        int n=nums.length;
        int j=n-1;
        int maxi=0;
        while(i<j){
            maxi=Math.max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
}