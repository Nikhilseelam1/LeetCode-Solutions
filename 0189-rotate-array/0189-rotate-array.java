class Solution {
    public void rev(int i,int j,int [] nums){
        int n=nums.length;
        if(i>=n || j<0 || j>=n || i<0) return ;
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n=nums.length;
                k=k%n;

        rev(0,n-k-1,nums);
        rev(n-k,n-1,nums);
        rev(0,n-1,nums);
    }
}