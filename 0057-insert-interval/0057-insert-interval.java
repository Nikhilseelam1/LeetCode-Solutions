class Solution {
    public int[][] insert(int[][] it, int[] n_i) {
        // int n=it.length;
        List<int[]> list = new ArrayList<>(Arrays.asList(it));
        list.add(new int[]{ n_i[0],n_i[1]});
        list.sort((a,b)-> Integer.compare(a[0],b[0]));
        List<int[]>l=new ArrayList<>();
        l.add(new int[]{list.get(0)[0],list.get(0)[1]});
        for(int i=1;i<list.size();i++){
            int []x=l.get(l.size()-1);
            int x1=x[0];
            int x2=x[1];
            int []y=list.get(i);
            int y1=y[0];
            int y2=y[1];
            if(x2>=y1 && x1<=y1){
                l.get(l.size()-1)[1]=Math.max(x2,y2);
            }else{
                l.add(y);
            }
        }
        return l.toArray(new int[l.size()][]);
    }
}