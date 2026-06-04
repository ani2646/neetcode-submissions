class Solution {
public:
    void quicksort(int left, int right, vector<int>& nums) {
        if (left >= right) {
            return;
        }

        int i = left;
        int j = right;
        int pivot = nums[left + (right - left) / 2];

        while (i <= j) {
            while (nums[i] < pivot) {
                i++;
            }

            while (nums[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        quicksort(left, j, nums);
        quicksort(i, right, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(0, nums.size() - 1, nums);
        return nums;
    }
};