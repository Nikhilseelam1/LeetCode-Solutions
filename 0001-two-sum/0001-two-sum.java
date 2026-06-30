import java.util.*;
class Solution {
    public int[] twoSum(int[] nums, int t) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            int x=t-nums[i];
            if(mp.containsKey(x)){
                return new int[]{mp.get(x),i};
            }
            mp.put(nums[i],i);
        }
        return new int[]{};
    }
}