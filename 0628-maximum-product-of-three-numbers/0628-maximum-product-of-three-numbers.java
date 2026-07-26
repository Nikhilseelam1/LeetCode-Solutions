class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int sum=0;
        sum=nums[n-1]*nums[n-2]*nums[n-3];
        int maxi=0;
        int c=0;
        if(nums[0]<0){
            c++;
            maxi=nums[0];
        }
        if(nums[1]<0){
            c++;
            maxi=maxi*nums[1];
        }
        if(c==1){
            maxi=Math.max(sum,maxi*nums[n-1]*nums[n-2]);
        }
        if(c==2){
            maxi=Math.max(sum,maxi*nums[n-1]);
        }
        maxi=Math.max(maxi,sum);
        return maxi;
    }
}