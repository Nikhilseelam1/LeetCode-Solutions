class Solution {
    public int[][] merge(int[][] inter) {
        int n=inter.length;
        List<List<Integer>>list=new ArrayList<>();
        Arrays.sort(inter, (a, b) -> Integer.compare(a[0], b[0]));
        list.add(new ArrayList<>(Arrays.asList(inter[0][0], inter[0][1])));
        for(int i=1;i<n;i++){
            List<Integer>li=list.get(list.size()-1);
            int val=li.get(1);
            if(inter[i][0]<=val){
                list.get(list.size()-1).set(1,Math.max(val,inter[i][1]));
            }else{
                list.add(new ArrayList<>(Arrays.asList(inter[i][0],inter[i][1])));
            }
        }
        int [][]ans=new int [list.size()][2];
        for(int j=0;j<list.size();j++){
            for(int i=0;i<2;i++){
                ans[j][i]=list.get(j).get(i);
            }
        }
        return ans;
    }
}