class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m=grid.length;
        int n=grid[0].length;
        int s=m*n;
        int x=k%s;
        int []arr=new int[s];
        for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        arr[x] = grid[i][j];
        x = (x + 1) % s;
    }
}
    for(int it:arr) System.out.println(it);
    List<List<Integer>>list=new ArrayList<>();
    int index = 0;
    for (int i = 0; i < m; i++) {
        List<Integer> row = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            row.add(arr[index++]);
        }
        list.add(row);
    }
    return list;
    }
}