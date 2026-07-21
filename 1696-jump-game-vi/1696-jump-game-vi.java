class Solution {
    int k1;
    int []dp;
    int n1;
    public int maxResult(int[] nums, int k) {
        k1=k;
        n1=nums.length;
        dp=new int [n1];
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        dp[0]=nums[0];
        pq.offer(new int[]{nums[0],0});
        for(int i=1;i<n1;i++){
            while(!pq.isEmpty() && pq.peek()[1]<i-k){
                pq.poll();
            }
            if(!pq.isEmpty()){
                int x=pq.peek()[0];
                dp[i]=nums[i]+x;
                pq.offer(new int[]{dp[i],i});
            }
        }
        return dp[n1-1];
    }
}