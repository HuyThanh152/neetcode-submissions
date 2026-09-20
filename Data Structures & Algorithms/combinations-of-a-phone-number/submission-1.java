class Solution {
    List<String> res = new ArrayList<>();
    StringBuilder curr = new StringBuilder() ;
    List<String> pad = List.of(
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
);
    void backtrack(String s, int idx){
        if (idx == s.length()){
            res.add(curr.toString());
            return;
        }
        int tmp = s.charAt(idx) - '0';
        for (char p : pad.get(tmp).toCharArray()){
            curr.append(p);
            backtrack(s, idx+1);
            curr.deleteCharAt(curr.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
       if(digits.length() == 0) return res;
        backtrack(digits, 0);
        return res;
    }
}
