class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while (left <= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> res;
    vector<string> curr;

    void backtrack (string& s, int start ){
        if(start == s.length()){
            res.push_back(curr);
            return;
        }
        for (int i = start; i < s.length(); i++){
            if(isPalindrome(s, start, i)){
               curr.push_back(s.substr(start, i-start+1));
               backtrack(s, i+1);
               curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
