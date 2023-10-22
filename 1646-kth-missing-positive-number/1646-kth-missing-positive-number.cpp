class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();

        // T.C. -> O(N)
        /*
        for(int i = 0; i<n; i++) {
            if(arr[i] > k) {
                break;
            }

            k++;
        }
        return k;
        */

        // Binary Search TC -> O(log N)

        int low = 0, high = n-1;

        while(low <= high) {
            int mid = (low+high)/2;
            int missing = arr[mid] - (mid+1);

            if(missing < k) {
                low = mid+1;
            } else {
                high = mid-1;
            } 
        }

        return (low + k);
    }
};