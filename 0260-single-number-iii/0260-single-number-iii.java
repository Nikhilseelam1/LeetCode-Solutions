class Solution {
    public int[] singleNumber(int[] nums) {
        int n=nums.length;
        int xor=0;
        for(int it:nums) xor^=it;
        int ans1=0,ans=0;
        int x=(xor & ~(xor-1));
        System.out.println(x);
        for(int i=0;i<n;i++){
            if((x & nums[i])!=0){
                ans=ans^nums[i];
            }else{
                ans1=ans1^nums[i];
            }
        }
        return new int[]{ans,ans1};
    }
}