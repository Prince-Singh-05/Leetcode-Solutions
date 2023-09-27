class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        
        int pickP = 0;
        int pickG = 0;
        int pickM = 0;

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        for(int i = 0; i<garbage.length; i++) {

            String curr = garbage[i];

            for(int j = 0; j<curr.length(); j++) {
                if(curr.charAt(j) == 'P') {
                    pickP++;
                    lastP = i;
                }
                else if(curr.charAt(j) == 'G') {
                    pickG++;
                    lastG = i;
                }
                else if(curr.charAt(j) == 'M') {
                    pickM++;
                    lastM = i;
                }
            }
        }

        for(int i = 0; i<lastP; i++) {
            travelP += travel[i];
        }

        for(int i = 0; i<lastG; i++) {
            travelG += travel[i];
        }

        for(int i = 0; i<lastM; i++) {
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);

        return ans;
    }
}