class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int i=0;
        while(i<n){
            if(nums[i]==0) break;
            i++;
        }
        int j=i;
        while(i<n){
            if(nums[i]!=0){
                int t=nums[i];
                nums[i]=nums[j];
                nums[j]=t;
                j++;
            }
            i++;
        }
    }
}