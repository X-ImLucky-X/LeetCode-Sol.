class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tempMax = maxEnding;

            maxEnding = max({
                nums[i],
                nums[i] * maxEnding,
                nums[i] * minEnding
            });

            minEnding = min({
                nums[i],
                nums[i] * tempMax,
                nums[i] * minEnding
            });

            ans = max(ans, maxEnding);
        }

        return ans;
    }
};