#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // Sort in ascending order
        std::sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); ++i) {
            // Skip duplicates
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // Check if consecutive
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            } else {
                longestStreak = std::max(longestStreak, currentStreak);
                currentStreak = 1; // Reset streak
            }
        }

        return std::max(longestStreak, currentStreak);
    }
};