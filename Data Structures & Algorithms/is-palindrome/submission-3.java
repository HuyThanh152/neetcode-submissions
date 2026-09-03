class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();
        String tmp = "";
        for (int i = 0; i < n; i++){
            if (Character.isDigit(s.charAt(i)) || Character.isLetter(s.charAt(i))){
                tmp += Character.toLowerCase(s.charAt(i)); 
            }
        }
        int len = tmp.length();
        for (int i = 0; i < len/2; i++)
            if(tmp.charAt(i) != tmp.charAt(len - i -1)) return false;
        return true;
    }
}
