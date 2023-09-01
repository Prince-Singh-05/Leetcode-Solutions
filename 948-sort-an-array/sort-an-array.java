// class Solution {

//     public void mergeSort(int nums[], int start, int end) {
//         if(start <= end) return;

//         int mid = start + ((end-start)/2);
//         mergeSort(nums, start, mid);
//         mergeSort(nums, mid+1, end);
//         merge(nums, start, mid, end);
//     }

//     public int[] merge(int nums[], int start, int mid, int end) {
//         int left = start;
//         int right = mid+1;

//         ArrayList<Integer> temp = new ArrayList<Integer>();

//         while(left<=mid && right<=end) {
//             if(nums[left] <= nums[right]) {
//                 temp.add(nums[left]);
//                 left++;
//             } else {
//                 temp.add(nums[right]);
//                 right++;
//             }
//         }

//         while(left <= mid) {
//             temp.add(nums[left]);
//             left++;
//         }

//         while(right <= end) {
//             temp.add(nums[right]);
//             right++;
//         }

//         for(int i = start; i<=end; i++) {
//             nums[i] = temp.get(i-start);
//         }

//         return nums;

//     }

//     public int[] sortArray(int[] nums) {
//         mergeSort(nums, 0, nums.length - 1);
//         return nums;
//     }
// }


class Solution {

    public void mergeSort(int nums[], int si, int ei) {
        if(si>=ei) {
            return;
        }

        int mid = si+((ei-si)/2);

        mergeSort(nums, si, mid);
        mergeSort(nums, mid+1, ei);
        merge(nums, si, mid, ei);
    }

    public int[] merge(int nums[], int si, int mid, int ei) {
        int i = si;
        int j = mid+1;
        int temp[] = new int[ei-si+1];
        int k = 0;

        while(i<=mid && j<=ei) {
            if(nums[i]<nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }

        while(i<=mid) {
            temp[k++] = nums[i++];
        }

        while(j<=ei) {
            temp[k++] = nums[j++];
        }

        for(int x=0, y=si; x<temp.length; x++,y++) {
            nums[y] = temp[x];
        }
        return nums;
    }

    public int[] sortArray(int[] nums) {
        mergeSort(nums,0,nums.length-1);
        return nums;
    }
}