class Solution {
public:
vector <string> res;
int currSize = 0;
string curr = "";
void backtrack(int open, int close){
    if(open == 0 && close == 0 ) {
        res.push_back(curr);
        return;
}
    if (open > 0){
    curr.push_back ('(');
    backtrack(open - 1, close);
    curr.pop_back();
    }
    if(close > open) {
    curr.push_back(')');
    backtrack(open, close - 1);
    curr.pop_back();
}
}
    vector<string> generateParenthesis(int n) {
        backtrack(n, n);
        return res;
        
    }
};
