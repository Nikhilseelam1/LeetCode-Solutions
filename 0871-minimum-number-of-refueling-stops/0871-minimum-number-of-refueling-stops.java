class Solution {
    public int minRefuelStops(int target, int s, int[][] stations) {
    PriorityQueue<Integer>pq=new PriorityQueue<Integer>((a,b)->Integer.compare(b,a));
        int reach=s;
        if(reach>=target) return 0;
        int n=stations.length;
        if(n==0 && target>reach) return -1;
        int ans=0;
        for(int []station:stations){
            if(station[0]>reach){
                while(!pq.isEmpty())
                {
                    ans++;
                    reach+=pq.poll();
                    if(reach>=station[0]) break;
                }
                if(reach>=target) return ans;
                if(reach<station[0]) return -1;
            }
            pq.offer(station[1]);
        }
        while(!pq.isEmpty()){
            if(reach>=target) return ans;
            ans++;
            reach+=pq.poll();
        }
        return (reach>=target ? ans:-1);
    }
}