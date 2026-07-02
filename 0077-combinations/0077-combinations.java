class Solution {
    public void back(List<List<Integer>>list,List<Integer>l,List<Integer>nums,int k,boolean [] used,int g){
        if(l.size()==k){
            list.add(new ArrayList<>(l));
            return ;
        }else{
            for(int i=g;i<nums.size();i++){
                l.add(nums.get(i));
                back(list,l,nums,k,used,i+1);
                l.remove(l.size()-1);
            }
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> list=new ArrayList<>();
        List<Integer>l=new ArrayList<>();
        List<Integer>nums=new ArrayList<>();
        boolean [] used=new boolean[n];
        for(int i=1;i<=n;i++){
            nums.add(i);
        }
        back(list,l,nums,k,used,0);
        return list;
    }
}