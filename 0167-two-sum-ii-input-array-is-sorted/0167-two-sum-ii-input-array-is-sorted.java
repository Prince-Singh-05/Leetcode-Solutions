class Solution {

    public int bs_search(int numbers[], int target, int i) {
        int s = i+1;
        int e = numbers.length - 1;

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(numbers[mid] == target) {
                return mid;
            } else if(numbers[mid] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return -1;
    }

    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int ans[] = new int[2];

        for(int i = 0; i<n; i++ ) {

            ans[0] = i+1;
            int toFind = target - numbers[i];

            int secIndex = bs_search(numbers, toFind, i);

            if(secIndex >= 0) {
                ans[1] = secIndex+1;
                break;
            }
        }

        return ans;
    }
}