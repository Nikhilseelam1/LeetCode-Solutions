class Solution {
    public int minimizeSum(int[] nums) {
        int n = nums.length;
        if (n <4) return 0;

        int[] small = {Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE};
        int[] large = {Integer.MIN_VALUE, Integer.MIN_VALUE, Integer.MIN_VALUE};

        for (int x:nums) {
            for (int i = 0; i < 3; i++) {
                if (x < small[i]) {
                    for (int j = 2; j > i; j--) {
                        small[j] = small[j - 1];
                    }
                    small[i] = x;
                    break;
                }
            }
            for (int i = 0; i < 3; i++) {
                if (x > large[i]) {
                    for (int j = 2; j > i; j--) {
                        large[j] = large[j - 1];
                    }
                    large[i] = x;
                    break;
                }
            }
        }
        for(int i=0;i<3;i++) System.out.println(large[i]);
        for(int i=0;i<3;i++) System.out.println(small[i]);
        // return 1;
        return Math.min(large[1]-small[1],Math.min(large[0]-small[2],large[2]-small[0]));
    }
}