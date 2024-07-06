class Solution {
public:
    int passThePillow(int n, int time) {


        // O(N) complexity - BRUTE FORCE
        
        // int pillow = 1;
        // bool direction = true;

        // while(time) {

        //     if(pillow < n && direction) {
        //         pillow++;
        //         time--;
        //     }
        //     else {
        //         direction = false;
        //     }

        //     if(pillow > 1 && !direction) {
        //        pillow--;
        //        time--;
        //     }
        //     else {
        //         direction = true;
        //     }
        // }

        // return pillow;


        // O(1) Complexity

        int chunks = time / (n - 1);
        return chunks % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
        
    }
};