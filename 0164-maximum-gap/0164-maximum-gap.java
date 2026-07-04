class Solution {
    public void radix(int [] nums,int exp){
        int n=nums.length;
        int []count=new int[10];
        int []output=new int[n];
        for(int i=0;i<n;i++){
            int d=(nums[i]/exp)%10;
            count[d]++;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            int d=(nums[i]/exp)%10;
            output[count[d]-1]=nums[i];
            count[d]--;
        }
        for(int i=0;i<n;i++){
            nums[i]=output[i];
        }
    }
    public int maximumGap(int[] nums) {
        int n=nums.length;
        int maxi=0;
        for(int it:nums){
            maxi=Math.max(maxi,it);
        }
        for(int i=1;maxi/i > 0 ;i=i*10){
            radix(nums,i);
        }
        int ans=0;
        for(int it:nums){
            System.out.println(it);
        }
        for(int i=1;i<n;i++){ 
            ans=Math.max(ans,nums[i]-nums[i-1]);
        }

        return ans;
    }
}