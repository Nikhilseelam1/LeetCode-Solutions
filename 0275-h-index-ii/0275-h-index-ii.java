class Solution {
    public int hIndex(int[] c) {
        int n=c.length;
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(c[mid]>=n-mid){
                high=mid-1;
                ans=n-mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
}