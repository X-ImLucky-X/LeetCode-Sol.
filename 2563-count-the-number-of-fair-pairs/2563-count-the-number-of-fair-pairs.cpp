class Solution {
public:
    long long countLessEqual(vector<int>& nums, long long x) {
        int l = 0;
        int r = nums.size() - 1;
        long long count = 0;

        while (l < r) {
            if ((long long)nums[l] + nums[r] <= x) {
                // nums[l] can pair with every index from l+1 to r
                count += (r - l);
                l++;
            } else {
                r--;
            }
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return countLessEqual(nums, upper)
             - countLessEqual(nums, (long long)lower - 1);
    }
};