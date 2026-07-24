class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int n=piles.length;
        int i=n-2;
        int ans=0;
        int j=0;
        while(i>j){
            ans+=piles[i];
            i-=2;
            j++;
        }
        return ans;
    }
}