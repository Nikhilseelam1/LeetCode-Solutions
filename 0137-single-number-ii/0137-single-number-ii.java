class Solution {
    public int singleNumber(int[] nums) {
        int ans=0;
        int n=nums.length;
        for(int b=0;b<32;b++){
            int c=0;
            for(int i=0;i<n;i++){
                if((nums[i] & (1<<b))!=0){
                    c++;
                }
            }
            if(c%3 != 0){
                    ans= (ans | (1<<b));
            }
        }
        return ans;
    }
}