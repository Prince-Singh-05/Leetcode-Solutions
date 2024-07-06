class Solution {
public:
    int passThePillow(int n, int time) {

        int pillow = 1;
        bool direction = true;

        while(time) {

            if(pillow < n && direction) {
                pillow++;
                time--;
            }
            else {
                direction = false;
            }

            if(pillow > 1 && !direction) {
               pillow--;
               time--;
            }
            else {
                direction = true;
            }
        }

        return pillow;
        
    }
};