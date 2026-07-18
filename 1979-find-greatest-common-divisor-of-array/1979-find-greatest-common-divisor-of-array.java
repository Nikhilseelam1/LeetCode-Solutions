class Solution {
    int gcd(int a,int b){
        while(b!=0){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    public int findGCD(int[] nums) {
        Arrays.sort(nums);
        int ans=gcd(nums[0],nums[nums.length-1]);
        return ans;
    }
}