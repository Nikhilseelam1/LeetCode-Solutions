class Solution {

    class TrieNode {
        TrieNode[] child = new TrieNode[26];
        String word;
    }

    TrieNode root = new TrieNode();

    public void insert(String word) {
        TrieNode curr = root;

        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (curr.child[idx] == null) {
                curr.child[idx] = new TrieNode();
            }
            curr = curr.child[idx];
        }

        curr.word = word;
    }

    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};

    public void dfs(char[][] board, int r, int c, TrieNode node, List<String> ans) {

        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length)
            return;

        char ch = board[r][c];

        if (ch == '#')
            return;

        TrieNode next = node.child[ch - 'a'];

        if (next == null)
            return;

        if (next.word != null) {
            ans.add(next.word);
            next.word = null;    
        }

        board[r][c] = '#';

        for (int k = 0; k < 4; k++) {
            dfs(board, r + dr[k], c + dc[k], next, ans);
        }

        board[r][c] = ch;
    }

    public List<String> findWords(char[][] board, String[] words) {

        for (String word : words) {
            insert(word);
        }

        List<String> ans = new ArrayList<>();

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
}