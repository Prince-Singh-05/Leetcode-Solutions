class Solution {
    public List<Integer> twoPtrMethod1(int[] arr, int k, int x) {
        List<Integer> ans = new ArrayList<>();
        int low = 0;
        int high = arr.length-1;

        while(high-low >= k) {
            if((x - arr[low]) > (arr[high] - x)) {
                low++;
            } else {
                high--;
            }
        }

        for(int i = low; i<=high; i++) {
            ans.add(arr[i]);
        }

        return ans;

    }

    public int lowerBound(int arr[], int x) {
        int s = 0;
        int e = arr.length-1;
        int ans = -1;

        while(s <= e) {
            int mid = s+(e-s)/2;

            if(arr[mid] >= x) {
                ans = mid;
                e = mid-1;
            } else if(x > arr[mid]) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return ans;
    }

    public List<Integer> bs_method(int[] arr, int k, int x) {
        List<Integer> ans = new ArrayList<>();
        int high = lowerBound(arr, x);
        int low = high-1;

        while(high-low < k && low>=0 && high<arr.length) {
            if((x - arr[low]) > (arr[high] - x)) {
                high++;
            } else {
                low--;
            }
        }

        for(int i = low; i<=high; i++) {
            ans.add(arr[i]);
        }

        return ans;

    }

    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        return twoPtrMethod1(arr, k, x);
        // return bs_method(arr, k, x);

    }
}