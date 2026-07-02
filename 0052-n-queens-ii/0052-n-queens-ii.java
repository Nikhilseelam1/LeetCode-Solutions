class Solution {
    public boolean check(char [][]board,int r,int c,int n){
        for(int i=0;i<n;i++){
            if(board[r][i] == 'Q') return false;
        }
        for(int i=0;i<n;i++){
            if(board[i][c] == 'Q') return false;
        }
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        for (int i = r, j = c; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        for (int i = r, j = c; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        for (int i = r, j = c; i < n && j < n; i++, j++)
            if (board[i][j] == 'Q') return false;
                return true;
    }
    public void back(List<List<String>> ans,char [][] board,int i,int n){
        if(i==n){
            List<String> l = new ArrayList<>();
            for (char[] row : board) {
                l.add(new String(row));
            }
            ans.add(new ArrayList<>(l));
        }else{
            for(int j=0;j<n;j++){
                if(board[i][j]!='Q' && check(board,i,j,n)){
                    board[i][j]='Q';
                    back(ans,board,i+1,n);
                    board[i][j]='.';
                }
            }
        }
    }
    public int totalNQueens(int n) {
        List<List<String>>ans=new ArrayList<>();
        char[][] board = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }        
        back(ans,board,0,n);
        return ans.size();
    }
}