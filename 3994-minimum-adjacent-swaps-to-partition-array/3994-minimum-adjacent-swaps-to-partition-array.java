class Solution {
    public int minAdjacentSwaps(int[] nums, int a, int b) {
        long inversions = 0;
        long MOD = 1_000_000_007L;

        long seen0 = 0;
        long seen1 = 0;
        long seen2 = 0;

        for (int num : nums) {

            if (num < a) {           
                inversions += seen1 + seen2;
                seen0++;
            }
            else if (num <= b) {     
                inversions += seen2;
                seen1++;
            }
            else {                   
                seen2++;
            }

            inversions %= MOD;
        }

        return (int)(inversions % MOD);
    }
}