// import java.utils.*;
class Solution {
    public int threeSumClosest(int[] nums, int t) {
        int n=nums.length;
        Arrays.sort(nums);
        int di=Integer.MAX_VALUE;
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                int diff=Math.abs(t-sum);
                if(di>diff){
                    di=diff;
                    ans=sum;
                }
                if(sum<t){
                    left++;
                }else if(sum>t){
                    right--;
                }else{
                    ans=sum;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
}