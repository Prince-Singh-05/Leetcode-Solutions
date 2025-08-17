class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        if(n == 0) return true;

        for(int i = 0; i<len; i++) {
            if(flowerbed[i] == 0) {
                bool isLeftEmpty = (i == 0 || flowerbed[i-1] != 1);
                bool isRightEmpty = (i == len-1 || flowerbed[i+1] != 1);

                if(isLeftEmpty && isRightEmpty) {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }

        return !(n > 0);
    }
};