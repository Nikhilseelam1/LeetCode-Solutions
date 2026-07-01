class Solution {
    public int firstMissingPositive(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;i++){
            while(nums[i]<=n && nums[i]>0 && nums[i] != nums[nums[i]-1]){
                int t=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=t;
            }
        }
        int x=1;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n) continue; 
            if(nums[i]!=x) return x;
            x++;
        }
        return x;
    }
}