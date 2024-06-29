class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int len = flowerbed.size();

        

        for(int i = 0; i<len; i++) {
            if(n > 0) {

                // edge case
                if(len == 1) {
                    if(flowerbed[0] == 0) {
                        flowerbed[0] == 1;
                        --n;
                    }
                }

                // end points
                else if(i == 0 && flowerbed[i] == 0) {

                    if(flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        --n;
                    }
                }

                else if(i == len-1 && flowerbed[i] == 0) {

                    if(flowerbed[i-1] == 0) {
                        flowerbed[i] = 1;
                        --n;
                    }
                }

                // remaining cases
                else {
                    if(flowerbed[i] == 0) {

                        if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                            flowerbed[i] = 1;
                            --n;
                        }
                    }
                }
            }
        }

        if(n > 0) {
            return false;
        }

        return true;
        
    }
};