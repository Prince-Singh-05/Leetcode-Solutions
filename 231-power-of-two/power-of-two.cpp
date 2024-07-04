class Solution {
public:
    bool isPowerOfTwo(int n) {

        // using loop

        // for(int i = 0; i<31; i++) {

        //     if(n == pow(2,i)) {
        //         return true;
        //     } else if(n < pow(2, i)) {
        //         return false;
        //     }
        // }

        // BIT MANIPULATION

        if(n >= 1 && (n & (n-1)) == 0) return true;

        return false;
        
    }
};