class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        // With extra space O(n+m)

        /*
        int i = 0;
        int j = 0;
        int index = 0;

        int temp[] = Arrays.copyOf(nums1, m);

        while(i<m && j<n) {
            if(temp[i] <= nums2[j]) {
                nums1[index] = temp[i];
                index++;
                i++;
            } else {
                nums1[index] = nums2[j];
                index++;
                j++;
            }
        }

        while(i<m) {
            nums1[index] = temp[i];
            i++;
            index++;
        }

        while(j<n) {
            nums1[index] = nums2[j];
            j++;
            index++;
        }
        */

        // WIthout any Extra Space

        for(int i = m, j = 0; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }

        Arrays.sort(nums1);

        // int i = m-1;
        // int j = 0;

        // while(i >= 0 && j < n) {
        //     if(nums1[i] > nums2[j]) {
        //         int temp = nums1[i];
        //         nums1[i] = nums2[j];
        //         nums2[j] = temp;

        //         i--;
        //         j++;
        //     } else {
        //         break;
        //     }
        // }

        // Arrays.sort(nums1);
        // Arrays.sort(nums2);
        
    }
}