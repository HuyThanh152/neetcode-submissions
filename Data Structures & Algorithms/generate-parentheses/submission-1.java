class Solution {
    public List<String> res = new ArrayList<>();
    StringBuilder curr = new StringBuilder() ;
    void backtrack(int open, int close){
        if (open == 0 && close == 0){
            res.add(curr.toString());
            return;
        }
        if(open > 0){
            curr.append('(');
            backtrack(open-1, close);
            curr.deleteCharAt(curr.length() - 1);
        }
        if(close > open){
            curr.append(')');
            backtrack(open, close-1);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
    public List<String> generateParenthesis(int n) {
        backtrack(n, n);
        return res;
    }
}
