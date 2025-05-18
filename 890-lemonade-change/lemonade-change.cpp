class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int note5Bill = 0; 
        int note10Bill = 0;
        int note20Bill = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                ++note5Bill;
            } else if(bills[i] == 10) {
                if(note5Bill == 0) {
                    return false;
                }
                ++note10Bill;
                --note5Bill;
            } else {
                ++note20Bill;
                if(note10Bill > 0 && note5Bill > 0) {
                    --note10Bill;
                    --note5Bill;
                } else if(note5Bill >= 3) {
                    note5Bill -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
        
    }
};