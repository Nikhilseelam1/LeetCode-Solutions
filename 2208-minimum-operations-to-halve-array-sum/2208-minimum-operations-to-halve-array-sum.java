class Solution {
    public int halveArray(int[] nums) {
    PriorityQueue<Double>pq=new PriorityQueue<Double>((a,b)->Double.compare(b,a));
        Double sum=0.0;
        for(int it:nums){
            double i=it;
            pq.offer(i);
            sum+=i;
        }
        Double ans=sum/2;
        int c=0;
        while(!pq.isEmpty()){
            Double x=pq.poll();
            x=x/2.0;
            sum-=x;
            pq.offer(x);
            c++;
            if(sum<=ans) break;
        }
        return c;
    }
}