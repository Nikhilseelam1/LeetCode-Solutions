import java.util.*;
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n=nums.length;
        int sum=0;
        int ans=0;
        HashMap<Integer,Integer> mp=new HashMap<>(); 
        mp.put(0,1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int t=sum-k;
            if(mp.containsKey(t)){
                ans+=mp.get(t);
            }
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}