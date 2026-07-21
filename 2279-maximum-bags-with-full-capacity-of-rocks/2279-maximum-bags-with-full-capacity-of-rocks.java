class Solution {
    public int maximumBags(int[] cap, int[] roc, int add) {
        // Arrays.sort(cap);
        // Arrays.sort(roc);
        int c=0;
        int n=cap.length;
        for(int i=0;i<n;i++){
            cap[i]=cap[i]-roc[i];
        }
        Arrays.sort(cap);
        for(int i=0;i<n;i++){
            if(cap[i]>0 && add>0){
                int min=Math.min(add,cap[i]);
                cap[i]-=min;
                add-=min;
            }
            if(cap[i]<=0) c++;
        }
        return c;
    }
}