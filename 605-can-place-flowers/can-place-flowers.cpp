class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        // int canBePlanted = false;
        vector<int> temp = flowerbed;

        if(len == 1 && temp[0] != 1) {
            return true;
        }

        for(int i = 0; i<len; i++) {
            if(temp[i] == 0) {
                if (i == 0) {
                    if(temp[i+1] != 1) {
                        temp[i] = 1;
                        n--;
                    }
                }

                if(i > 0 && i < len-1) {
                    if(temp[i-1] != 1 && temp[i+1] != 1) {
                        temp[i] = 1;
                        n--;
                    }
                }

                if(i == len-1) {
                    if(temp[i-1] != 1) {
                        temp[i] = 1;
                        n--;
                    }
                }
            }
        }

        if(n > 0) return false;

        return true;

    }
};