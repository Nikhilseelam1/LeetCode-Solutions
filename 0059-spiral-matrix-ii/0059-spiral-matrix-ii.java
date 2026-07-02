class Solution {
    public int[][] generateMatrix(int n) {
        int [][] mat=new int[n][n];
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;
        int c=1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                mat[left][i]=c++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                // ans.push_back(mat[i][right]);
                mat[i][right]=c++;
            }
            right--;
            if(top<=bottom)
            {
            for(int i=right;i>=left;i--)
            {
                // ans.push_back(mat[bottom][i]);
                mat[bottom][i]=c++;
            }
            }
            bottom--;
            if(left<=right){
            for(int i=bottom;i>=top;i--){
                // ans.push_back(mat[i][left]);
                mat[i][left]=c++;

            }}
            left++;
        }
        return mat;
    }
}