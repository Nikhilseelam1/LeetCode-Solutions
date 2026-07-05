class node{
    node []arr;
    boolean isend;
    node(){
        isend=false;
        arr=new node[26];
    }
};
class trie{
    node root;    
    trie(){
        root=new node();
    }
    public void insert(String s){
        node temp=root;
        for(char ch:s.toCharArray()){
            int ind=ch-'a';
            if((temp.arr[ind]) == null){
                temp.arr[ind]=new node();
            }
            temp=temp.arr[ind];
        }
        temp.isend=true;
    }
    public boolean dfs(int i,String s,node root){
        if(root==null) return false;
        if(i==s.length()) return root.isend;
        char ch=s.charAt(i);
        if(ch!='.'){
            return dfs(i+1,s,root.arr[ch-'a']);
        }
        for(int ii=0;ii<26;ii++){
            if(root.arr[ii]!=null && dfs(i+1,s,root.arr[ii])){
                return true;
            }
        }
        return false;
    }
    public boolean search(String s){
        return dfs(0,s,root);
    }
};
class WordDictionary {
    trie t;
    public WordDictionary() {
        t=new trie();
    }
    
    public void addWord(String word) {
        t.insert(word);
    }
    
    public boolean search(String word) {
        return t.search(word);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */