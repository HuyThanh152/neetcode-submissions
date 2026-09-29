class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (const string& s : operations) {
            if (s == "+") {
                // Lấy phần tử trên cùng ra tạm thời
                int top1 = st.top();
                st.pop();
                
                // Lấy phần tử thứ hai
                int top2 = st.top();
                
                // Trả lại phần tử thứ nhất vào stack
                st.push(top1);
                
                // Push tổng của 2 phần tử mới
                st.push(top1 + top2);
            } 
            else if (s == "D") {
                st.push(2 * st.top());
            } 
            else if (s == "C") {
                st.pop(); // Sửa lỗi st.pop -> st.pop()
            } 
            else {
                // Trường hợp còn lại chắc chắn là chuỗi số (kể cả số âm như "-5")
                st.push(stoi(s));
            }
        }

        // Tính tổng tất cả phần tử trong stack
        int totalSum = 0;
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }

        return totalSum;
    }
};