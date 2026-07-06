class Solution {
    public int removeCoveredIntervals(int[][] in) {
        Arrays.sort(in,(a,b)->{
            if(a[0]==b[0]) return Integer.compare(b[1],a[1]);
            return Integer.compare(a[0],b[0]);
    });
        int n=in.length;
        int x1=in[0][0];
        int y1=in[0][1];
        int c=n;
        for(int i=1;i<n;i++){
            int x=in[i][0];
            int y=in[i][1];
            if(x1<=x && y1>=y){
                c--;
                continue;
            }else{
                x1=x;
                y1=y;

            }
        }
        return c;
    }
}