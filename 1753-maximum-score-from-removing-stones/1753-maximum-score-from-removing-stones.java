class Solution {
    public int maximumScore(int a, int b, int c) {
PriorityQueue<Integer>pq=new PriorityQueue<>((a1,b1)-> Integer.compare(b1,a1));
        pq.offer(a);
        pq.offer(b);
        pq.offer(c);
        int ans=0;
        while(pq.size()>2){
            int x=pq.poll();
            int x1=pq.poll();
            if(x==0 || x1==0){
                pq.poll();
                pq.poll();
                break;
            }
            ans++;
            x--;
            x1--;
            pq.offer(x);pq.offer(x1);
        }
        return ans;
    }
}