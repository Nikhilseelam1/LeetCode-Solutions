class Solution {
    public int maxPalindromes(String s, int k) {
    int n = s.length();
    int ans = 0;

    for (int i = 0; i <= n - k;) {

        if (isPalindrome(s, i, i + k - 1)) {
            ans++;
            i += k;
        }
        else if (i + k < n && isPalindrome(s, i, i + k)) {
            ans++;
            i += k + 1;
        }
        else {
            i++;
        }
    }

    return ans;
}

private boolean isPalindrome(String s, int l, int r) {
    while (l < r) {
        if (s.charAt(l++) != s.charAt(r--))
            return false;
    }
    return true;
}
}