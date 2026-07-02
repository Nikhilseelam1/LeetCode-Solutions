class Solution {
    public void back(List<List<Integer>>list,List<Integer>l,boolean [] used,int [] nums){
        if(l.size()==nums.length){
            list.add(new ArrayList<>(l));
        }else{
            for(int i=0;i<nums.length;i++){
                if(used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
                used[i]=true;
                l.add(nums[i]);
                back(list,l,used,nums);
                used[i]=false;
                l.remove(l.size()-1);
            }
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> list=new ArrayList<>();
        Arrays.sort(nums);
        back(list,new ArrayList<>(),new boolean[nums.length],nums);

        return list;
    }
}