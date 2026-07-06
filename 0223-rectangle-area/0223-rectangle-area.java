class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int maxi=Math.max(ax1,bx1);
        int mini=Math.min(ax2,bx2);
        int maxi1=Math.max(ay1,by1);
        int mini1=Math.min(ay2,by2);
        int overlapWidth = Math.max(0, mini - maxi);
        int overlapHeight = Math.max(0, mini1 - maxi1);
        int rem = overlapWidth * overlapHeight;
        int x=Math.abs(ax2-ax1) * Math.abs(ay2-ay1);
        int x1=Math.abs(bx2-bx1) * Math.abs(by2-by1);
        System.out.println(x);
        System.out.println(x1);
        if(bx1>=ax2 || bx2<=ax1) rem=0;
        if (by1 >= ay2 || by2 <= ay1) rem = 0;
        int ans=(x+x1) - rem;
        return ans;
    }
}