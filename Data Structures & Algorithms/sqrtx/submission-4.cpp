class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 2;
        int right = x/2;
        int res = 1;
       
        while (left <= right){
             int mid = left + (right - left) /2;
            long long square = (long long )mid*mid;
            if(square == x) return mid;
            else if (square > x ){ 
              
                right = mid - 1;
                       }
           else {
               res = mid;
               left = mid+1;}
        }
        return res;
    }
};