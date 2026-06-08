
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // Find insertion position manually
        int pos = 0;
        while (pos < n && arr[pos] < x) {
            pos++;
        }
        
        int left = pos - 1;
        int right = pos;
        
        // Expand window
        while (k--) {
            if (left < 0) {
                right++;
            }
            else if (right >= n) {
                left--;
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            }
            else {
                right++;
            }
        }
        
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};