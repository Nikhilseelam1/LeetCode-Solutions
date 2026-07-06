class Solution {
    Map<Integer, String> ones = Map.of(
        1, "One",
        2, "Two",
        3, "Three",
        4, "Four",
        5, "Five",
        6, "Six",
        7, "Seven",
        8, "Eight",
        9, "Nine"
    );

    Map<Integer, String> teens = Map.of(
        10, "Ten",
        11, "Eleven",
        12, "Twelve",
        13, "Thirteen",
        14, "Fourteen",
        15, "Fifteen",
        16, "Sixteen",
        17, "Seventeen",
        18, "Eighteen",
        19, "Nineteen"
    );

    Map<Integer, String> tens = Map.of(
        2, "Twenty",
        3, "Thirty",
        4, "Forty",
        5, "Fifty",
        6, "Sixty",
        7, "Seventy",
        8, "Eighty",
        9, "Ninety"
    );
    public String rec(int num){
        if(num<10){
            return ones.get(num);
        }
        if(num<20){
            return teens.get(num);
        }
        if(num<100){
            return tens.get(num/10)  +  (num%10 == 0?"":" " + ones.get(num%10));
        }
        if(num<1000){
            return rec(num/100) + " " +  "Hundred"  + (num%100==0?"":" " + rec(num%100));
        }
        if(num<1000000){
            return rec(num/1000) + " " +  "Thousand"  + (num%1000==0?"":" "  + rec(num%1000));
        }
        if(num<1000000000){
            return rec(num/1000000) + " " +  "Million"   +  (num%1000000==0?"":" " + rec(num%1000000));
        }
        return rec(num/1000000000) + " " + "Billion" + (num%1000000000==0?"":" " + rec(num%1000000000));
    }
    public String numberToWords(int num) {
        if(num==0) return "Zero";
        return rec(num);
    }
}