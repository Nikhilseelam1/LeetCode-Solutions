class Solution {
    public int findMinArrowShots(int[][] p) {
        int n=p.length;
        Arrays.sort(p,(a,b)-> Integer.compare(a[1],b[1]));
                int maxi=p[0][1];
        int c=1;
        for(int i=1;i<n;i++){
            int x=p[i][0];
            int y=p[i][1];
            System.out.println(maxi + " " + x);
            // System.out.println(x);
            if(x>maxi){
                maxi=y;
                c=c+1;
            }
        }
        return c;
    }
}