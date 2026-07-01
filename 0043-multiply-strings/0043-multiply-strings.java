class Solution {
    public String multiply(String num1, String num2) {
        int n=num1.length();
        int m=num2.length();
        int []arr=new int[n+m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int p1=i+j;
                int p2=i+j+1;
                int mul=(num1.charAt(i)-'0') * (num2.charAt(j)-'0');
                int sum=mul+arr[p2];
                arr[p2]=sum%10;
                arr[p1]+=sum/10;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int p : arr) if(!(sb.length() == 0 && p == 0)) sb.append(p);
        return sb.length() == 0 ? "0" : sb.toString();
        // return "";
    }
}