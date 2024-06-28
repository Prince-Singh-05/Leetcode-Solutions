// class Solution {
// public:
//     string largestOddNumber(string num) {

//         string ans;
//         int end = -1;  

//         for(int i = num.size()-1; i >= 0; i--) {

//             if((num[i] - '0')%2 != 0) {
//                 end = i;
//                 break;
//             }
               
//         }
 

//         for(int i = 0; i<=end; i++) {
//             ans += num[i];
//         }

//         return ans;
//     }
// };


class Solution {
public:
    string largestOddNumber(string num) {
        for (int i=num.length()-1; i>=0; i--){
            int digit = num[i]-'0' ;
            if (digit & 1){
                return num.substr(0, i+1) ;
            }
        }
        return "" ;
    }
};