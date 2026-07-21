class Solution {
    public int[][] intervalIntersection(int[][] f_l, int[][] s_l) {
        List<List<Integer>>list=new ArrayList<>();
        int n=f_l.length;
        int m=s_l.length;

        for(int i=0;i<n;i++){
            int x=f_l[i][0];
            int y=f_l[i][1];
            for(int j=0;j<m;j++){
                int x1=s_l[j][0];
                int x2=s_l[j][1];
                if(y>=x1){
                    if(x<=x2){
    list.add(new ArrayList<>(Arrays.asList(Math.max(x,x1),Math.min(y,x2))));
                    }else if(x==x2){
                        list.add(new ArrayList<>(Arrays.asList(x,x)));
                    }
                }
            }
        }
        int [][] l=new int [list.size()][2];
        for(int i=0;i<list.size();i++){
                int x=list.get(i).get(0);
                int x1=list.get(i).get(1);
                l[i][0]=x;
                l[i][1]=x1;
        }
        return l;
    }
}