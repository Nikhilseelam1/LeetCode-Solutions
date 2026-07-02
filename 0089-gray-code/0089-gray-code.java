import java.util.*;

class Solution {
    long total;
    HashSet<Integer> vis = new HashSet<>();
    public int value(String s) {
        int res = 0;
        int p = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '1')
                res += p;
            p *= 2;
        }
        return res;
    }
    public void back(List<Integer> list, String s) {
        if (list.size() == total)
            return;
        for (int i = 0; i < s.length(); i++) {
            StringBuilder sb = new StringBuilder(s);
            if (sb.charAt(i) == '0')
                sb.setCharAt(i, '1');
            else
                sb.setCharAt(i, '0');
            int val = value(sb.toString());
            if (!vis.contains(val)) {
                vis.add(val);
                list.add(val);
                back(list, sb.toString());
                if (list.size() == total)
                    return;
                vis.remove(val);
                list.remove(list.size() - 1);
            }
        }
    }
    public List<Integer> grayCode(int n) {
        total = 1L << n;
        List<Integer> list = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
            sb.append('0');
        list.add(0);
        vis.add(0);
        back(list, sb.toString());
        return list;
    }
}