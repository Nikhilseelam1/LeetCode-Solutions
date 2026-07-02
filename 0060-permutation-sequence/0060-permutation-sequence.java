class Solution {
    List<List<Integer>>list=new ArrayList<>();
    void back(List<Integer>l,List<Integer>nums,boolean [] used){
        if(l.size() == nums.size()){
            list.add(new ArrayList<>(l));
            return ;
        }else{
            for(int i=0;i<nums.size();i++){
                if(used[i]) continue;
                used[i]=true;
                l.add(nums.get(i));
                back(l,nums,used);
                l.remove(l.size()-1);
                used[i]=false;
            }
        }
    }
    public String getPermutation(int n, int k) {
        List<Integer>l=new ArrayList<>();
        List<Integer>nums=new ArrayList<>();
        boolean [] used=new boolean [n];
        for(int i=1;i<=n;i++){
            nums.add(i);
        }
        back(l,nums,used);
        List<Integer>lis=list.get(k-1);
        String s="";
        for(int i=0;i<lis.size();i++){
            s+=Integer.toString(lis.get(i));
        }
        return s;
    }
}