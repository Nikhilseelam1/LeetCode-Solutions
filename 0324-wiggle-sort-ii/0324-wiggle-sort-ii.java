class Solution {
    public void wiggleSort(int[] nums) {
        int n=nums.length;
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
        for(int it:nums) pq.offer(it);
        for(int i=1;i<n;i+=2){
            nums[i]=pq.poll();
        }
        for(int i=0;i<n;i+=2){
            nums[i]=pq.poll();
        }
        return ;
    }
}