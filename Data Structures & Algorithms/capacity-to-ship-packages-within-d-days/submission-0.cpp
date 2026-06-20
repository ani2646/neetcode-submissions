class Solution {
public:

    int day(vector<int>& weights, int capacity){
        int days = 1;        // start with first day
        int sum = 0;

        for(int w : weights){
            if(sum + w <= capacity){
                sum += w;    // add to current day
            } else {
                days++;      // new day
                sum = w;     // start with current weight
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int w : weights){
            high += w;
        }

        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            int needed = day(weights, mid);

            if(needed > days){
                low = mid + 1;       // capacity too small
            } else {
                ans = mid;           // valid, try smaller
                high = mid - 1;
            }
        }

        return ans;
    }
};