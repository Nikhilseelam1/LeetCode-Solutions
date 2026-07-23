class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n=nums.length;
        if(n==1) return 1;
        if(n==2) return 2;
        int x = (int) (Math.log(n) / Math.log(2));
        // System.out.println(x);
        x++;
        int ans = 1 << x;
        return ans;
    }
}